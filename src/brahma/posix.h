//
// Created by hariharan on 8/8/22.
//

#ifndef BRAHMA_POSIX_H
#define BRAHMA_POSIX_H

#include <cstdlib>
#include <bits/types/struct_iovec.h>
#include <unistd.h>

#include <brahma/interceptor.h>

namespace brahma {
    class POSIX {
    private:
        static std::shared_ptr<POSIX> my_instance;
    public:
        static std::shared_ptr<POSIX> get_instance() {
            if (my_instance != nullptr) {
                return my_instance;
            } else {
                throw std::runtime_error("POSIX class not intercepted but used");
            }
        }
        static int set_instance(std::shared_ptr<POSIX> instance_i) {
            if (instance_i != nullptr) {
                my_instance = instance_i;
                return 0;
            } else {
                throw std::runtime_error("instance_i is not set");
            }
        }
        virtual int open(const char *pathname, int flags, mode_t mode);

        virtual int creat64(const char *path, mode_t mode);

        virtual int open64(const char *path, int flags, mode_t mode);

        virtual int close(int fd);

        virtual ssize_t write(int fd, const void *buf, size_t count);

        virtual ssize_t read(int fd, void *buf, size_t count);

        virtual off_t lseek(int fd, off_t offset, int whence);

        virtual off64_t lseek64(int fd, off64_t offset, int whence);

        virtual ssize_t pread(int fd, void *buf, size_t count, off_t offset);

        virtual ssize_t pread64(int fd, void *buf, size_t count, off64_t offset);

        virtual ssize_t pwrite(int fd, const void *buf, size_t count, off64_t offset) ;

        virtual ssize_t pwrite64(int fd, const void *buf, size_t count, off64_t offset) ;

        virtual ssize_t readv(int fd, const struct iovec *iov, int iovcnt);

        virtual ssize_t writev(int fd, const struct iovec *iov, int iovcnt);

        virtual int fsync(int fd);

        virtual int fdatasync(int fd);
    };

    std::shared_ptr<POSIX> POSIX::my_instance = nullptr;
}

GOTCHA_MACRO(open, int, (const char *pathname, int flags, mode_t mode), (pathname, flags, mode), brahma::POSIX);

GOTCHA_MACRO(creat64, int, (const char *path, mode_t mode), (path, mode), brahma::POSIX);

GOTCHA_MACRO(open64, int, (const char *path, int flags, mode_t mode), (path, flags, mode), brahma::POSIX);

GOTCHA_MACRO(close, int, (int fd), (fd), brahma::POSIX);

GOTCHA_MACRO(write, ssize_t, (int fd, const void *buf, size_t count), (fd, buf, count), brahma::POSIX);

GOTCHA_MACRO(read, ssize_t, (int fd, void * buf, size_t count),(fd, buf, count), brahma::POSIX);

GOTCHA_MACRO(lseek, off_t, (int fd, off_t offset, int whence), (fd, offset, whence), brahma::POSIX);

GOTCHA_MACRO(lseek64, off64_t, (int fd, off64_t offset, int whence), (fd, offset, whence), brahma::POSIX);

GOTCHA_MACRO(pread, ssize_t, (int fd, void * buf, size_t count, off_t offset), (fd, buf, count, offset), brahma::POSIX);

GOTCHA_MACRO(pread64, ssize_t, (int fd, void * buf, size_t count, off64_t offset), (fd, buf, count, offset), brahma::POSIX);

GOTCHA_MACRO(pwrite, ssize_t, (int fd, const void *buf, size_t count, off_t offset), (fd, buf, count, offset), brahma::POSIX);

GOTCHA_MACRO(pwrite64, ssize_t, (int fd, const void *buf, size_t count, off64_t offset), (fd, buf, count, offset), brahma::POSIX);

GOTCHA_MACRO(readv, ssize_t, (int fd, const iovec *iov, int iovcnt), (fd, iov, iovcnt), brahma::POSIX);

GOTCHA_MACRO(writev, ssize_t, (int fd, const iovec *iov, int iovcnt), (fd, iov, iovcnt), brahma::POSIX);

GOTCHA_MACRO(fsync, int, (int fd), (fd), brahma::POSIX);

GOTCHA_MACRO(fdatasync, int, (int fd), (fd), brahma::POSIX);

int update_posix() {
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
    GOTCHA_BINDING_MACRO(readv);
    GOTCHA_BINDING_MACRO(writev);
    GOTCHA_BINDING_MACRO(fsync);
    GOTCHA_BINDING_MACRO(fdatasync);
    return 0;
}

namespace brahma {
    int POSIX::open(const char *pathname, int flags, mode_t mode) {
        BRAHMA_UNWRAPPED_FUNC(open, int, (pathname, flags, mode));
    }

    int POSIX::creat64(const char *path, mode_t mode) {
        BRAHMA_UNWRAPPED_FUNC(creat64, int, (path, mode));
    }

    int POSIX::open64(const char *path, int flags, mode_t mode) {
        BRAHMA_UNWRAPPED_FUNC(open64, int, (path, flags, mode));
    }

    int POSIX::close(int fd) {
        BRAHMA_UNWRAPPED_FUNC(close, int, (fd));
    }

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
        BRAHMA_UNWRAPPED_FUNC(pread, ssize_t, (fd, buf, count, offset));};

    ssize_t POSIX::pread64(int fd, void *buf, size_t count, off64_t offset) {
        BRAHMA_UNWRAPPED_FUNC(pread64, ssize_t, (fd, buf, count, offset));};

    ssize_t POSIX::pwrite(int fd, const void *buf, size_t count, off64_t offset) {
        BRAHMA_UNWRAPPED_FUNC(pwrite, ssize_t, (fd, buf, count, offset));};

    ssize_t POSIX::pwrite64(int fd, const void *buf, size_t count, off64_t offset) {
        BRAHMA_UNWRAPPED_FUNC(pwrite64, ssize_t, (fd, buf, count, offset));};

    ssize_t POSIX::readv(int fd, const struct iovec *iov, int iovcnt) {
        BRAHMA_UNWRAPPED_FUNC(readv, ssize_t, (fd, iov, iovcnt));};

    ssize_t POSIX::writev(int fd, const struct iovec *iov, int iovcnt) {
        BRAHMA_UNWRAPPED_FUNC(writev, ssize_t, (fd, iov, iovcnt));
    };

    int POSIX::fsync(int fd) {
        BRAHMA_UNWRAPPED_FUNC(fsync, int, (fd));
    }

    int POSIX::fdatasync(int fd) {
        BRAHMA_UNWRAPPED_FUNC(fdatasync, int, (fd));
    }
}

#endif //BRAHMA_POSIX_H
