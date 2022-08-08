//
// Created by hariharan on 8/8/22.
//

#ifndef BRAHMA_STDIO_H
#define BRAHMA_STDIO_H
#include <cstdio>
#include <brahma/interceptor.h>

namespace brahma {
    class STDIO {
    private:
        static std::shared_ptr<STDIO> my_instance;
    public:
        static std::shared_ptr<STDIO> get_instance() {
            if (my_instance != nullptr) {
                return my_instance;
            } else {
                throw std::runtime_error("STDIO class not intercepted but used");
            }
        }
        static int set_instance(std::shared_ptr<STDIO> instance_i) {
            if (instance_i != nullptr) {
                my_instance = instance_i;
                return 0;
            } else {
                throw std::runtime_error("instance_i is not set");
            }
        }
        virtual FILE* fopen (const char *path, const char *mode);
        virtual FILE* fopen64 (const char *path, const char *mode);
        virtual int fclose (FILE * fp);
        virtual size_t fread (void *ptr, size_t size, size_t nmemb, FILE *stream);
        virtual size_t fwrite (const void *ptr, size_t size, size_t nmemb, FILE *stream);
        virtual long ftell (FILE * fp);
        virtual int fseek (FILE * stream, long offset, int whence);
    };

    std::shared_ptr<STDIO> STDIO::my_instance = nullptr;
}

GOTCHA_MACRO(fopen, FILE *, (const char *path, const char *mode), (path, mode), brahma::STDIO);
GOTCHA_MACRO(fopen64, FILE *, (const char *path, const char *mode), (path, mode), brahma::STDIO);
GOTCHA_MACRO(fclose, int, (FILE * fp), (fp), brahma::STDIO);
GOTCHA_MACRO(fread, size_t, (void *ptr, size_t size, size_t nmemb, FILE *stream), (ptr, size, nmemb, stream), brahma::STDIO);
GOTCHA_MACRO(fwrite, size_t, (const void *ptr, size_t size, size_t nmemb, FILE *stream), (ptr, size, nmemb, stream), brahma::STDIO);
GOTCHA_MACRO(ftell, long, (FILE *stream), (stream), brahma::STDIO);
GOTCHA_MACRO(fseek, int, (FILE * stream, long offset, int whence), (stream,offset,whence), brahma::STDIO);

int update_stdio() {
    GOTCHA_BINDING_MACRO(fopen);
    GOTCHA_BINDING_MACRO(fopen64);
    GOTCHA_BINDING_MACRO(fclose);
    GOTCHA_BINDING_MACRO(fread);
    GOTCHA_BINDING_MACRO(fwrite);
    GOTCHA_BINDING_MACRO(ftell);
    GOTCHA_BINDING_MACRO(fseek);
    return 0;
}

namespace brahma {
   FILE* STDIO::fopen (const char *path, const char *mode) {
       BRAHMA_UNWRAPPED_FUNC(fopen, FILE*, (path, mode));
   };
    FILE* STDIO::fopen64 (const char *path, const char *mode) {
        BRAHMA_UNWRAPPED_FUNC(fopen64, FILE*, (path, mode));
    };
    int STDIO::fclose (FILE * fp){
        BRAHMA_UNWRAPPED_FUNC(fclose, int, (fp));
    };
    size_t STDIO::fread (void *ptr, size_t size, size_t nmemb, FILE *stream){
        BRAHMA_UNWRAPPED_FUNC(fread, size_t, (ptr, size, nmemb, stream));
    };
    size_t STDIO::fwrite (const void *ptr, size_t size, size_t nmemb, FILE *stream){
        BRAHMA_UNWRAPPED_FUNC(fwrite, size_t, (ptr, size, nmemb, stream));
    };
    long STDIO::ftell (FILE * stream){
        BRAHMA_UNWRAPPED_FUNC(ftell, long, (stream));
    };
    int STDIO::fseek (FILE * stream, long offset, int whence){
        BRAHMA_UNWRAPPED_FUNC(fseek, int, (stream, offset, whence));
    };
}

#endif //BRAHMA_STDIO_H
