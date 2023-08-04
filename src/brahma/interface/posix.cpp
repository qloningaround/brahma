//
// Created by hariharan on 8/16/22.
//
#include <brahma/interface/posix.h>
#include <fcntl.h>

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

GOTCHA_MACRO(openat, int, (int dirfd, const char *pathname, int flags, mode_t mode), (dirfd, pathname, flags, mode), brahma::POSIX);
GOTCHA_MACRO(mmap, void *, (void *addr, size_t length, int prot, int flags, int fd, off_t offset),
(addr, length, prot, flags, fd, offset), brahma::POSIX);
GOTCHA_MACRO(mmap64, void *, (void *addr, size_t length, int prot, int flags, int fd, off64_t offset),
(addr, length, prot, flags, fd, offset), brahma::POSIX);
GOTCHA_MACRO(__xstat, int, (int vers, const char *path, stat *buf), (vers, path, buf), brahma::POSIX);
GOTCHA_MACRO(__xstat64, int, (int vers, const char *path, stat64 *buf), (vers, path, buf), brahma::POSIX);
GOTCHA_MACRO(__lxstat, int, (int vers, const char *path, stat *buf), (vers, path, buf), brahma::POSIX);
GOTCHA_MACRO(__lxstat64, int, (int vers, const char *path, stat64 *buf), (vers, path, buf), brahma::POSIX);
GOTCHA_MACRO(__fxstat, int, (int vers, int fd, stat *buf), (vers, path, buf), brahma::POSIX);
GOTCHA_MACRO(__fxstat64, int, (int vers, int fd, stat64 *buf), (vers, path, buf), brahma::POSIX);
GOTCHA_MACRO(getcwd, char*, (char *buf, size_t size),(buf, size), brahma::POSIX);
GOTCHA_MACRO(mkdir, int, (const char *pathname, mode_t mode), (pathname, mode), brahma::POSIX);
GOTCHA_MACRO(rmdir, int, (const char *pathname), (pathname), brahma::POSIX);
GOTCHA_MACRO(chdir, int, (const char *path), (path), brahma::POSIX);
GOTCHA_MACRO(link, int, (const char *oldpath, const char *newpath), (oldpath, newpath), brahma::POSIX);
GOTCHA_MACRO(linkat, int, (int fd1, const char *path1, int fd2, const char *path2, int flag), (fd1, path1, fd2, path2, flag), brahma::POSIX);
GOTCHA_MACRO(unlink, int, (const char *pathname), (pathname), brahma::POSIX);
GOTCHA_MACRO(symlink, int, (const char *path1, const char *path2), (path1, path2), brahma::POSIX);
GOTCHA_MACRO(symlinkat, int, (const char *path1, int fd, const char *path2), (path1, fd, path2), brahma::POSIX);
GOTCHA_MACRO(readlink, ssize_t, (const char *path, char *buf, size_t bufsize), (path, buf, bufsize), brahma::POSIX);
GOTCHA_MACRO(readlinkat, ssize_t, (int fd, const char *path, char *buf, size_t bufsize), (fd, path, buf, bufsize), brahma::POSIX);
GOTCHA_MACRO(rename, int, (const char *oldpath, const char *newpath), (oldpath, newpath), brahma::POSIX);
GOTCHA_MACRO(chmod, int, (const char *path, mode_t mode), (path, mode), brahma::POSIX);
GOTCHA_MACRO(chown, int, (const char *path, uid_t owner, gid_t group), (path, owner, group), brahma::POSIX);
GOTCHA_MACRO(lchown, int, (const char *path, uid_t owner, gid_t group), (path, owner, group), brahma::POSIX);
GOTCHA_MACRO(utime, int, (const char *filename, const utimbuf *buf), (filename, buf), brahma::POSIX);
GOTCHA_MACRO(opendir, DIR*, (const char *name), (name), brahma::POSIX);
GOTCHA_MACRO(readdir, struct dirent*, (DIR *dir), (dir), brahma::POSIX);
GOTCHA_MACRO(closedir, int, (DIR *dir), (dir), brahma::POSIX);
GOTCHA_MACRO(rewinddir, void, (DIR *dir), (dir), brahma::POSIX);
GOTCHA_MACRO(fcntl, int, (int fd, int cmd, long arg), (fd, cmd, arg), brahma::POSIX);
GOTCHA_MACRO(dup, int, (int oldfd), (oldfd), brahma::POSIX);
GOTCHA_MACRO(dup2, int, (int oldfd, int newfd), (oldfd, newfd), brahma::POSIX);
GOTCHA_MACRO(pipe, int, (int pipefd[2]), (pipefd), brahma::POSIX);
GOTCHA_MACRO(mkfifo, int, (const char *pathname, mode_t mode), (pathname, mode), brahma::POSIX);
GOTCHA_MACRO(umask, mode_t, (mode_t mask), (mask), brahma::POSIX);
GOTCHA_MACRO(access, int, (const char *path, int amode), (path, amode), brahma::POSIX);
GOTCHA_MACRO(faccessat, int, (int fd, const char *path, int amode, int flag), (fd, path, amode, flag), brahma::POSIX);
GOTCHA_MACRO(remove, int, (const char *pathname), (pathname), brahma::POSIX);
GOTCHA_MACRO(truncate, int, (const char *pathname, off_t length), (pathname, length), brahma::POSIX);
GOTCHA_MACRO(ftruncate, int, (int fd, off_t length), (fd, length), brahma::POSIX);
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

  GOTCHA_BINDING_MACRO(openat);
  GOTCHA_BINDING_MACRO(mmap);
  GOTCHA_BINDING_MACRO(mmap64);
  GOTCHA_BINDING_MACRO(__xstat);
  GOTCHA_BINDING_MACRO(__xstat64);
  GOTCHA_BINDING_MACRO(__lxstat);
  GOTCHA_BINDING_MACRO(__lxstat64);
  GOTCHA_BINDING_MACRO(__fxstat);
  GOTCHA_BINDING_MACRO(__fxstat64);
  GOTCHA_BINDING_MACRO(getcwd);
  GOTCHA_BINDING_MACRO(mkdir);
  GOTCHA_BINDING_MACRO(rmdir);
  GOTCHA_BINDING_MACRO(chdir);
  GOTCHA_BINDING_MACRO(link);
  GOTCHA_BINDING_MACRO(linkat);
  GOTCHA_BINDING_MACRO(unlink);
  GOTCHA_BINDING_MACRO(symlink);
  GOTCHA_BINDING_MACRO(symlinkat);
  GOTCHA_BINDING_MACRO(readlink);
  GOTCHA_BINDING_MACRO(readlinkat);
  GOTCHA_BINDING_MACRO(rename);
  GOTCHA_BINDING_MACRO(chmod);
  GOTCHA_BINDING_MACRO(chown);
  GOTCHA_BINDING_MACRO(lchown);
  GOTCHA_BINDING_MACRO(utime);
  GOTCHA_BINDING_MACRO(opendir);
  GOTCHA_BINDING_MACRO(readdir);
  GOTCHA_BINDING_MACRO(closedir);
  GOTCHA_BINDING_MACRO(rewinddir);
  GOTCHA_BINDING_MACRO(fcntl);
  GOTCHA_BINDING_MACRO(dup);
  GOTCHA_BINDING_MACRO(dup2);
  GOTCHA_BINDING_MACRO(pipe);
  GOTCHA_BINDING_MACRO(mkfifo);
  GOTCHA_BINDING_MACRO(umask);
  GOTCHA_BINDING_MACRO(access);
  GOTCHA_BINDING_MACRO(faccessat);
  GOTCHA_BINDING_MACRO(remove);
  GOTCHA_BINDING_MACRO(truncate);
  GOTCHA_BINDING_MACRO(ftruncate);
  return 0;
}

size_t count_posix() { return 54; }

namespace brahma {
std::shared_ptr<POSIX> POSIX::my_instance = nullptr;
int POSIX::open(const char *pathname, int flags, ...) {

  if (flags & O_CREAT) {
    va_list args;
    va_start(args, flags);
    int mode = va_arg(args, int);
    va_end(args);
    BRAHMA_UNWRAPPED_FUNC(open, int, (pathname, flags, mode));
    return result;
  } else {
    BRAHMA_UNWRAPPED_FUNC(open, int, (pathname, flags));
    return result;
  }
}

int POSIX::creat64(const char *path, mode_t mode) {
  BRAHMA_UNWRAPPED_FUNC(creat64, int, (path, mode));
  return result;
}

int POSIX::open64(const char *path, int flags, ...) {
  if (flags & O_CREAT) {
    va_list args;
    va_start(args, flags);
    int mode = va_arg(args, int);
    va_end(args);
    BRAHMA_UNWRAPPED_FUNC(open64, int, (path, flags, mode));
    return result;
  } else {
    BRAHMA_UNWRAPPED_FUNC(open64, int, (path, flags));
    return result;
  }
}

int POSIX::close(int fd) {
  BRAHMA_UNWRAPPED_FUNC(close, int, (fd));
  return result;
}

ssize_t POSIX::write(int fd, const void *buf, size_t count) {
  BRAHMA_UNWRAPPED_FUNC(write, ssize_t, (fd, buf, count));
  return result;
};

ssize_t POSIX::read(int fd, void *buf, size_t count) {
  BRAHMA_UNWRAPPED_FUNC(read, ssize_t, (fd, buf, count));
  return result;
};

off_t POSIX::lseek(int fd, off_t offset, int whence) {
  BRAHMA_UNWRAPPED_FUNC(lseek, off_t, (fd, offset, whence));
  return result;
};

off64_t POSIX::lseek64(int fd, off64_t offset, int whence) {
  BRAHMA_UNWRAPPED_FUNC(lseek, off64_t, (fd, offset, whence));
  return result;
};

ssize_t POSIX::pread(int fd, void *buf, size_t count, off_t offset) {
  BRAHMA_UNWRAPPED_FUNC(pread, ssize_t, (fd, buf, count, offset));
  return result;
};

ssize_t POSIX::pread64(int fd, void *buf, size_t count, off64_t offset) {
  BRAHMA_UNWRAPPED_FUNC(pread64, ssize_t, (fd, buf, count, offset));
  return result;
};

ssize_t POSIX::pwrite(int fd, const void *buf, size_t count, off64_t offset) {
  BRAHMA_UNWRAPPED_FUNC(pwrite, ssize_t, (fd, buf, count, offset));
  return result;
};

ssize_t POSIX::pwrite64(int fd, const void *buf, size_t count, off64_t offset) {
  BRAHMA_UNWRAPPED_FUNC(pwrite64, ssize_t, (fd, buf, count, offset));
  return result;
};

int POSIX::fsync(int fd) {
  BRAHMA_UNWRAPPED_FUNC(fsync, int, (fd));
  return result;
}

int POSIX::fdatasync(int fd) {
  BRAHMA_UNWRAPPED_FUNC(fdatasync, int, (fd));
  return result;
}

int POSIX::openat(int dirfd, const char *pathname, int flags, ...) {
  if (flags & O_CREAT) {
    va_list args;
    va_start(args, flags);
    int mode = va_arg(args, int);
    va_end(args);
    BRAHMA_UNWRAPPED_FUNC(openat, int, (dirfd, pathname, flags, mode));
    return result;
  }else {
    BRAHMA_UNWRAPPED_FUNC(openat, int, (dirfd, pathname, flags));
    return result;
  }
}
void* POSIX::mmap(void *addr, size_t length, int prot, int flags, int fd, off_t offset) {
  BRAHMA_UNWRAPPED_FUNC(mmap, void*, (addr, length, prot, flags, fd, offset));
  return result;
}

void* POSIX::mmap64(void *addr, size_t length, int prot, int flags, int fd, off64_t offset) {
  BRAHMA_UNWRAPPED_FUNC(mmap64, void*, (addr, length, prot, flags, fd, offset));
  return result;
}
int POSIX::__xstat(int vers, const char *path, struct stat *buf) {
  BRAHMA_UNWRAPPED_FUNC(__xstat, int, (vers, path, buf));
  return result;
}
int POSIX::__xstat64(int vers, const char *path, struct stat64 *buf) {
  BRAHMA_UNWRAPPED_FUNC(__xstat64, int, (vers, path, buf));
  return result;
}
int POSIX::__lxstat(int vers, const char *path, struct stat *buf) {
  BRAHMA_UNWRAPPED_FUNC(__lxstat, int, (vers, path, buf));
  return result;
}
int POSIX::__lxstat64(int vers, const char *path, struct stat64 *buf) {
  BRAHMA_UNWRAPPED_FUNC(__lxstat64, int, (vers, path, buf));
  return result;
}
int POSIX::__fxstat(int vers, int fd, struct stat *buf) {
  BRAHMA_UNWRAPPED_FUNC(__fxstat, int, (vers, fd, buf));
  return result;
}
int POSIX::__fxstat64(int vers, int fd, struct stat64 *buf) {
  BRAHMA_UNWRAPPED_FUNC(__fxstat64, int, (vers, fd, buf));
  return result;
}
char* POSIX::getcwd(char *buf, size_t size) {
  BRAHMA_UNWRAPPED_FUNC(getcwd, char*, (buf, size));
  return result;
}
int POSIX::mkdir(const char *pathname, mode_t mode) {
  BRAHMA_UNWRAPPED_FUNC(mkdir, int, (pathname, mode));
  return result;
}
int POSIX::rmdir(const char *pathname) {
  BRAHMA_UNWRAPPED_FUNC(rmdir, int, (pathname));
  return result;
}
int POSIX::chdir(const char *path) {
  BRAHMA_UNWRAPPED_FUNC(chdir, int, (path));
  return result;
}
int POSIX::link(const char *oldpath, const char *newpath) {
  BRAHMA_UNWRAPPED_FUNC(link, int, (oldpath, newpath));
  return result;
}
int POSIX::linkat(int fd1, const char *path1, int fd2, const char *path2, int flag) {
  BRAHMA_UNWRAPPED_FUNC(linkat, int, (fd1, path1, fd2, path2, flag));
  return result;
}
int POSIX::unlink(const char *pathname) {
  BRAHMA_UNWRAPPED_FUNC(unlink, int, (pathname));
  return result;
}
int POSIX::symlink(const char *path1, const char *path2) {
  BRAHMA_UNWRAPPED_FUNC(symlink, int, (path1, path2));
  return result;
}
int POSIX::symlinkat(const char *path1, int fd, const char *path2) {
  BRAHMA_UNWRAPPED_FUNC(symlinkat, int, (path1, fd, path2));
  return result;
}
ssize_t POSIX::readlink(const char *path, char *buf, size_t bufsize) {
  BRAHMA_UNWRAPPED_FUNC(readlink, ssize_t, (path, buf, bufsize));
  return result;
}
ssize_t POSIX::readlinkat(int fd, const char *path, char *buf, size_t bufsize) {
  BRAHMA_UNWRAPPED_FUNC(readlinkat, ssize_t, (fd, path, buf, bufsize));
  return result;
}
int POSIX::rename(const char *oldpath, const char *newpath) {
  BRAHMA_UNWRAPPED_FUNC(rename, int, (oldpath, newpath));
  return result;
}
int POSIX::chmod(const char *path, mode_t mode) {
  BRAHMA_UNWRAPPED_FUNC(chmod, int, (path, mode));
  return result;
}
int POSIX::chown(const char *path, uid_t owner, gid_t group) {
  BRAHMA_UNWRAPPED_FUNC(chown, int, (path, owner, group));
  return result;
}
int POSIX::lchown(const char *path, uid_t owner, gid_t group) {
  BRAHMA_UNWRAPPED_FUNC(lchown, int, (path, owner, group));
  return result;
}
int POSIX::utime(const char *filename, const utimbuf *buf) {
  BRAHMA_UNWRAPPED_FUNC(utime, int, (filename, buf));
  return result;
}
DIR* POSIX::opendir(const char *name) {
  BRAHMA_UNWRAPPED_FUNC(opendir, DIR*, (name));
  return result;
}
dirent* POSIX::readdir(DIR *dir) {
  BRAHMA_UNWRAPPED_FUNC(readdir, dirent*, (dir));
  return result;
}
int POSIX::closedir(DIR *dir) {
  BRAHMA_UNWRAPPED_FUNC(closedir, int, (dir));
  return result;
}
void POSIX::rewinddir(DIR *dir) {
  BRAHMA_UNWRAPPED_FUNC_VOID(rewinddir, (dir));
}
int POSIX::fcntl(int fd, int cmd, ...) {
  if(cmd==F_DUPFD || cmd==F_DUPFD_CLOEXEC || cmd==F_SETFD || cmd==F_SETFL || cmd==F_SETOWN) {            // arg: int
    va_list arg;
    va_start(arg, cmd);
    int val = va_arg(arg, int);
    va_end(arg);
    BRAHMA_UNWRAPPED_FUNC(fcntl, int, (fd, cmd, val));
    return result;
  } else if(cmd==F_GETFD || cmd==F_GETFL || cmd==F_GETOWN) {
    BRAHMA_UNWRAPPED_FUNC(fcntl, int, (fd, cmd));
    return result;
  } else if(cmd==F_SETLK || cmd==F_SETLKW || cmd==F_GETLK) {
    va_list arg;
    va_start(arg, cmd);
    struct flock *lk = va_arg(arg, struct flock*);
    va_end(arg);
    BRAHMA_UNWRAPPED_FUNC(fcntl, int, (fd, cmd, lk));
    return result;
  } else {                        // assume arg: void, cmd==F_GETOWN_EX || cmd==F_SETOWN_EX ||cmd==F_GETSIG || cmd==F_SETSIG)
    BRAHMA_UNWRAPPED_FUNC(fcntl, int, (fd, cmd));
    return result;
  }
}
int POSIX::dup(int oldfd) {
  BRAHMA_UNWRAPPED_FUNC(dup, int, (oldfd));
  return result;
}
int POSIX::dup2(int oldfd, int newfd) {
  BRAHMA_UNWRAPPED_FUNC(dup2, int, (oldfd, newfd));
  return result;
}
int POSIX::pipe(int pipefd[2]) {
  BRAHMA_UNWRAPPED_FUNC(pipe, int, (pipefd));
  return result;
}
int POSIX::mkfifo(const char *pathname, mode_t mode) {
  BRAHMA_UNWRAPPED_FUNC(mkfifo, int, (pathname, mode));
  return result;
}
mode_t POSIX::umask(mode_t mask) {
    BRAHMA_UNWRAPPED_FUNC(umask, mode_t, (mask));
    return result;
}

int POSIX::access(const char *path, int amode) {
  BRAHMA_UNWRAPPED_FUNC(access, int, (path, amode));
  return result;
}
int POSIX::faccessat(int fd, const char *path, int amode, int flag) {
  BRAHMA_UNWRAPPED_FUNC(faccessat, int, (fd, path, amode, flag));
  return result;
}

int POSIX::remove(const char *pathname) {
  BRAHMA_UNWRAPPED_FUNC(remove, int, (pathname));
  return result;
}
int POSIX::truncate(const char *pathname, off_t length) {
  BRAHMA_UNWRAPPED_FUNC(truncate, int, (pathname, length));
  return result;
}
int POSIX::ftruncate(int fd, off_t length) {
  BRAHMA_UNWRAPPED_FUNC(ftruncate, int, (fd, length));
  return result;
}

}  // namespace brahma