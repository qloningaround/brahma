//
// Created by hariharan on 8/8/22.
//

#include <brahma/brahma.h>
#include <fcntl.h>

namespace brahma {
class POSIXTest : public POSIX {
 private:
  static std::shared_ptr<POSIXTest> instance;

 public:
  POSIXTest() {}
  static std::shared_ptr<POSIXTest> get_instance() {
    if (instance == nullptr) {
      instance = std::make_shared<POSIXTest>();
      POSIX::set_instance(instance);
    }
    return instance;
  }
  int open(const char* pathname, int flags, mode_t mode) override {
    auto open_wrappee = (open_fptr)gotcha_get_wrappee(get_open_handle());
    int result = open_wrappee(pathname, flags, mode);
    fprintf(stderr, "[Test]\topen(%s, %d, %u) = %d\n", pathname, flags,
            (unsigned int)mode, result);
    return result;
  }
};

std::shared_ptr<POSIXTest> POSIXTest::instance = nullptr;
}  // namespace brahma

void __attribute__((constructor)) test_init() {
  brahma_gotcha_wrap("tool", 1);
  brahma::POSIXTest::get_instance();
}
void __attribute__((destructor)) test_finalize() {}

int main(int argc, char* argv[]) {
  int fd = open("file.dat", O_WRONLY | O_CREAT | O_EXCL);
  assert(fd != -1);
  int status = close(fd);
  assert(status == 0);
  return 0;
}