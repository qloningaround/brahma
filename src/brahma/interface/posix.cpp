//
// Created by hariharan on 8/16/22.
//
#include <brahma/interface/posix.h>
GOTCHA_MACRO(open, int, (const char *pathname, int flags, mode_t mode),
             (pathname, flags, mode), brahma::POSIX);

GOTCHA_MACRO(creat64, int, (const char *path, mode_t mode), (path, mode),
             brahma::POSIX);

GOTCHA_MACRO(open64, int, (const char *path, int flags, mode_t mode),
             (path, flags, mode), brahma::POSIX);

GOTCHA_MACRO(close, int, (int fd), (fd), brahma::POSIX);

GOTCHA_MACRO(write, ssize_t, (int fd, const void *buf, size_t count),
             (fd, buf, count), brahma::POSIX);

GOTCHA_MACRO(read, ssize_t, (int fd, void *buf, size_t count), (fd, buf, count),
             brahma::POSIX);

GOTCHA_MACRO(lseek, off_t, (int fd, off_t offset, int whence),
             (fd, offset, whence), brahma::POSIX);

GOTCHA_MACRO(lseek64, off64_t, (int fd, off64_t offset, int whence),
             (fd, offset, whence), brahma::POSIX);

GOTCHA_MACRO(pread, ssize_t, (int fd, void *buf, size_t count, off_t offset),
             (fd, buf, count, offset), brahma::POSIX);

GOTCHA_MACRO(pread64, ssize_t,
             (int fd, void *buf, size_t count, off64_t offset),
             (fd, buf, count, offset), brahma::POSIX);

GOTCHA_MACRO(pwrite, ssize_t,
             (int fd, const void *buf, size_t count, off_t offset),
             (fd, buf, count, offset), brahma::POSIX);

GOTCHA_MACRO(pwrite64, ssize_t,
             (int fd, const void *buf, size_t count, off64_t offset),
             (fd, buf, count, offset), brahma::POSIX);

GOTCHA_MACRO(fsync, int, (int fd), (fd), brahma::POSIX);

GOTCHA_MACRO(fdatasync, int, (int fd), (fd), brahma::POSIX);
int update_posix(gotcha_binding_t *&bindings, size_t &binding_index) {
  GOTCHA_BINDING_MACRO(open);
  GOTCHA_BINDING_MACRO(creat64);
  GOTCHA_BINDING_MACRO(open64);
  GOTCHA_BINDING_MACRO(close);
  GOTCHA_BINDING_MACRO(write);
  GOTCHA_BINDING_MACRO(read);
  GOTCHA_BINDING_MACRO(lseek);
  GOTCHA_BINDING_MACRO(lseek64);
  GOTCHA_BINDING_MACRO(pread);
  GOTCHA_BINDING_MACRO(pread64);
  GOTCHA_BINDING_MACRO(pwrite);
  GOTCHA_BINDING_MACRO(pwrite64);
  GOTCHA_BINDING_MACRO(fsync);
  GOTCHA_BINDING_MACRO(fdatasync);
  return 0;
}

size_t count_posix() { return 14; }

namespace brahma {
std::shared_ptr<POSIX> POSIX::my_instance = nullptr;
int POSIX::open(const char *pathname, int flags, mode_t mode) {
  BRAHMA_UNWRAPPED_FUNC(open, int, (pathname, flags, mode));
}

int POSIX::creat64(const char *path, mode_t mode) {
  BRAHMA_UNWRAPPED_FUNC(creat64, int, (path, mode));
}

int POSIX::open64(const char *path, int flags, mode_t mode) {
  BRAHMA_UNWRAPPED_FUNC(open64, int, (path, flags, mode));
}

int POSIX::close(int fd) { BRAHMA_UNWRAPPED_FUNC(close, int, (fd)); }

ssize_t POSIX::write(int fd, const void *buf, size_t count) {
  BRAHMA_UNWRAPPED_FUNC(write, ssize_t, (fd, buf, count));
};

ssize_t POSIX::read(int fd, void *buf, size_t count) {
  BRAHMA_UNWRAPPED_FUNC(read, ssize_t, (fd, buf, count));
};

off_t POSIX::lseek(int fd, off_t offset, int whence) {
  BRAHMA_UNWRAPPED_FUNC(lseek, off_t, (fd, offset, whence));
};

off64_t POSIX::lseek64(int fd, off64_t offset, int whence) {
  BRAHMA_UNWRAPPED_FUNC(lseek, off64_t, (fd, offset, whence));
};

ssize_t POSIX::pread(int fd, void *buf, size_t count, off_t offset) {
  BRAHMA_UNWRAPPED_FUNC(pread, ssize_t, (fd, buf, count, offset));
};

ssize_t POSIX::pread64(int fd, void *buf, size_t count, off64_t offset) {
  BRAHMA_UNWRAPPED_FUNC(pread64, ssize_t, (fd, buf, count, offset));
};

ssize_t POSIX::pwrite(int fd, const void *buf, size_t count, off64_t offset) {
  BRAHMA_UNWRAPPED_FUNC(pwrite, ssize_t, (fd, buf, count, offset));
};

ssize_t POSIX::pwrite64(int fd, const void *buf, size_t count, off64_t offset) {
  BRAHMA_UNWRAPPED_FUNC(pwrite64, ssize_t, (fd, buf, count, offset));
};

int POSIX::fsync(int fd) { BRAHMA_UNWRAPPED_FUNC(fsync, int, (fd)); }

int POSIX::fdatasync(int fd) { BRAHMA_UNWRAPPED_FUNC(fdatasync, int, (fd)); }
}  // namespace brahma