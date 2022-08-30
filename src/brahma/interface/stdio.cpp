//
// Created by hariharan on 8/16/22.
//
#include <brahma/interface/stdio.h>
GOTCHA_MACRO(fopen, FILE *, (const char *path, const char *mode), (path, mode),
             brahma::STDIO);

GOTCHA_MACRO(fopen64, FILE *, (const char *path, const char *mode),
             (path, mode), brahma::STDIO);

GOTCHA_MACRO(fclose, int, (FILE * fp), (fp), brahma::STDIO);

GOTCHA_MACRO(fread, size_t,
             (void *ptr, size_t size, size_t nmemb, FILE *stream),
             (ptr, size, nmemb, stream), brahma::STDIO);

GOTCHA_MACRO(fwrite, size_t,
             (const void *ptr, size_t size, size_t nmemb, FILE *stream),
             (ptr, size, nmemb, stream), brahma::STDIO);

GOTCHA_MACRO(ftell, long, (FILE * stream), (stream), brahma::STDIO);

GOTCHA_MACRO(fseek, int, (FILE * stream, long offset, int whence),
             (stream, offset, whence), brahma::STDIO);
int update_stdio(gotcha_binding_t *&bindings, size_t &binding_index) {
  GOTCHA_BINDING_MACRO(fopen);
  GOTCHA_BINDING_MACRO(fopen64);
  GOTCHA_BINDING_MACRO(fclose);
  GOTCHA_BINDING_MACRO(fread);
  GOTCHA_BINDING_MACRO(fwrite);
  GOTCHA_BINDING_MACRO(ftell);
  GOTCHA_BINDING_MACRO(fseek);
  return 0;
}
size_t count_stdio() { return 7; }

namespace brahma {

std::shared_ptr<STDIO> STDIO::my_instance = nullptr;
FILE *STDIO::fopen(const char *path, const char *mode) {
  BRAHMA_UNWRAPPED_FUNC(fopen, FILE *, (path, mode));
  return result;
};

FILE *STDIO::fopen64(const char *path, const char *mode) {
  BRAHMA_UNWRAPPED_FUNC(fopen64, FILE *, (path, mode));
  return result;
};

int STDIO::fclose(FILE *fp) {
  BRAHMA_UNWRAPPED_FUNC(fclose, int, (fp));
  return result;
};

size_t STDIO::fread(void *ptr, size_t size, size_t nmemb, FILE *stream) {
  BRAHMA_UNWRAPPED_FUNC(fread, size_t, (ptr, size, nmemb, stream));
  return result;
};

size_t STDIO::fwrite(const void *ptr, size_t size, size_t nmemb, FILE *stream) {
  BRAHMA_UNWRAPPED_FUNC(fwrite, size_t, (ptr, size, nmemb, stream));
  return result;
};

long STDIO::ftell(FILE *stream) {
  BRAHMA_UNWRAPPED_FUNC(ftell, long, (stream));
  return result;
};

int STDIO::fseek(FILE *stream, long offset, int whence) {
  BRAHMA_UNWRAPPED_FUNC(fseek, int, (stream, offset, whence));
  return result;
};
}  // namespace brahma