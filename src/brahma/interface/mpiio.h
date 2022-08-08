//
// Created by hariharan on 8/8/22.
//

#ifndef BRAHMA_MPIIO_H
#define BRAHMA_MPIIO_H

#include "brahma/interceptor.h"
#include <mpi.h>

namespace brahma {
    class MPIIO {
    private:
        static std::shared_ptr<MPIIO> my_instance;
    public:
        static std::shared_ptr<MPIIO> get_instance() {
            if (my_instance != nullptr) {
                return my_instance;
            } else {
                throw std::runtime_error("STDIO class not intercepted but used");
            }
        }

        static int set_instance(std::shared_ptr<MPIIO> instance_i) {
            if (instance_i != nullptr) {
                my_instance = instance_i;
                return 0;
            } else {
                throw std::runtime_error("instance_i is not set");
            }
        }

        virtual int PMPI_File_close(MPI_File *fh);

        virtual int PMPI_File_set_size(MPI_File fh, MPI_Offset size);

        virtual int PMPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                                       MPI_Request *request);

        virtual int PMPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request);

        virtual int
        PMPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request);

        virtual int
        PMPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype,
                            MPI_Request *request);

        virtual int
        PMPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request);

        virtual int
        PMPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request);

        virtual int PMPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh);

        virtual int PMPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype);

        virtual int PMPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);

        virtual int PMPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                                          MPI_Status *status);

        virtual int
        PMPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype);

        virtual int PMPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                                      MPI_Status *status);

        virtual int PMPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);

        virtual int PMPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype);

        virtual int
        PMPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);

        virtual int PMPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status);

        virtual int PMPI_File_sync(MPI_File fh);

        virtual int PMPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype);

        virtual int
        PMPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status);

        virtual int
        PMPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype);

        virtual int
        PMPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype,
                               MPI_Status *status);

        virtual int
        PMPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype,
                           MPI_Status *status);

        virtual int PMPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status);

        virtual int PMPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype);

        virtual int
        PMPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status);

        virtual int
        PMPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status);
    };

    std::shared_ptr<MPIIO> MPIIO::my_instance = nullptr;
}

GOTCHA_MACRO(PMPI_File_close, int, (MPI_File * fh), (fh), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_set_size, int, (MPI_File fh, MPI_Offset size), (fh, size), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_iread_at, int,
             (MPI_File fh, MPI_Offset offset, void * buf, int count, MPI_Datatype datatype, MPI_Request * request),
             (fh, offset, buf, count, datatype, request), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_iread, int, (MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Request * request),
             (fh, buf, count, datatype, request), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_iread_shared, int,
             (MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Request * request),
             (fh, buf, count, datatype, request), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_iwrite_at, int,
             (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Request * request),
             (fh, offset, buf, count, datatype, request), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_iwrite, int,
             (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request * request),
             (fh, buf, count, datatype, request), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_iwrite_shared, int,
             (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request * request),
             (fh, buf, count, datatype, request), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_open, int, (MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File * fh),
             (comm, filename, amode, info, fh), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_read_all_begin, int, (MPI_File fh, void * buf, int count, MPI_Datatype datatype),
             (fh, buf, count, datatype), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_read_all, int, (MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, buf, count, datatype, status), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_read_at_all, int,
             (MPI_File fh, MPI_Offset offset, void * buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, offset, buf, count, datatype, status), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_read_at_all_begin, int,
             (MPI_File fh, MPI_Offset offset, void * buf, int count, MPI_Datatype datatype),
             (fh, offset, buf, count, datatype), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_read_at, int,
             (MPI_File fh, MPI_Offset offset, void * buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, offset, buf, count, datatype, status), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_read, int, (MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, buf, count, datatype, status), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_read_ordered_begin, int, (MPI_File fh, void * buf, int count, MPI_Datatype datatype),
             (fh, buf, count, datatype), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_read_ordered, int,
             (MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, buf, count, datatype, status), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_read_shared, int,
             (MPI_File fh, void * buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, buf, count, datatype, status), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_sync, int, (MPI_File fh), (fh), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_write_all_begin, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype),
             (fh, buf, count, datatype), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_write_all, int,
             (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, buf, count, datatype, status), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_write_at_all_begin, int,
             (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype),
             (fh, offset, buf, count, datatype), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_write_at_all, int,
             (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, offset, buf, count, datatype, status), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_write_at, int,
             (MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, offset, buf, count, datatype, status), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_write, int,
             (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, buf, count, datatype, status), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_write_ordered_begin, int, (MPI_File fh, const void *buf, int count, MPI_Datatype datatype),
             (fh, buf, count, datatype), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_write_ordered, int,
             (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, buf, count, datatype, status), brahma::MPIIO);

GOTCHA_MACRO(PMPI_File_write_shared, int,
             (MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status * status),
             (fh, buf, count, datatype, status), brahma::MPIIO);

int update_mpiio() {
    GOTCHA_BINDING_MACRO(PMPI_File_close);
    GOTCHA_BINDING_MACRO(PMPI_File_set_size);
    GOTCHA_BINDING_MACRO(PMPI_File_iread_at);
    GOTCHA_BINDING_MACRO(PMPI_File_iread);
    GOTCHA_BINDING_MACRO(PMPI_File_iread_shared);
    GOTCHA_BINDING_MACRO(PMPI_File_iwrite_at);
    GOTCHA_BINDING_MACRO(PMPI_File_iwrite);
    GOTCHA_BINDING_MACRO(PMPI_File_iwrite_shared);
    GOTCHA_BINDING_MACRO(PMPI_File_open);
    GOTCHA_BINDING_MACRO(PMPI_File_read_all_begin);
    GOTCHA_BINDING_MACRO(PMPI_File_read_all);
    GOTCHA_BINDING_MACRO(PMPI_File_read_at_all);
    GOTCHA_BINDING_MACRO(PMPI_File_read_at_all_begin);
    GOTCHA_BINDING_MACRO(PMPI_File_read_at);
    GOTCHA_BINDING_MACRO(PMPI_File_read);
    GOTCHA_BINDING_MACRO(PMPI_File_read_ordered_begin);
    GOTCHA_BINDING_MACRO(PMPI_File_read_ordered);
    GOTCHA_BINDING_MACRO(PMPI_File_read_shared);
    GOTCHA_BINDING_MACRO(PMPI_File_sync);
    GOTCHA_BINDING_MACRO(PMPI_File_write_all_begin);
    GOTCHA_BINDING_MACRO(PMPI_File_write_all);
    GOTCHA_BINDING_MACRO(PMPI_File_write_at_all_begin);
    GOTCHA_BINDING_MACRO(PMPI_File_write_at_all);
    GOTCHA_BINDING_MACRO(PMPI_File_write_at);
    GOTCHA_BINDING_MACRO(PMPI_File_write);
    GOTCHA_BINDING_MACRO(PMPI_File_write_ordered_begin);
    GOTCHA_BINDING_MACRO(PMPI_File_write_ordered);
    GOTCHA_BINDING_MACRO(PMPI_File_write_shared);
    return 0;
}

namespace brahma {
    int MPIIO::PMPI_File_close(MPI_File *fh) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_close, int, (fh));
    }

    int MPIIO::PMPI_File_set_size(MPI_File fh, MPI_Offset size) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_set_size, int, (fh, size));
    }

    int MPIIO::PMPI_File_iread_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                                  MPI_Request *request) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_iread_at, int, (fh, offset, buf, count, datatype, request));
    }

    int MPIIO::PMPI_File_iread(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_iread, int, (fh, buf, count, datatype, request));
    }

    int MPIIO::PMPI_File_iread_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Request *request) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_iread_shared, int, (fh, buf, count, datatype, request));
    }

    int MPIIO::PMPI_File_iwrite_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype,
                                   MPI_Request *request) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_iwrite_at, int, (fh, offset, buf, count, datatype, request));
    }

    int MPIIO::PMPI_File_iwrite(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Request *request) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_iwrite, int, (fh, buf, count, datatype, request));
    }

    int MPIIO::PMPI_File_iwrite_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype,
                                       MPI_Request *request) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_iwrite_shared, int, (fh, buf, count, datatype, request));
    }

    int MPIIO::PMPI_File_open(MPI_Comm comm, const char *filename, int amode, MPI_Info info, MPI_File *fh) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_open, int, (comm, filename, amode, info, fh));
    }

    int MPIIO::PMPI_File_read_all_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_read_all_begin, int, (fh, buf, count, datatype));
    }

    int MPIIO::PMPI_File_read_all(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_read_all, int, (fh, buf, count, datatype, status));
    }

    int MPIIO::PMPI_File_read_at_all(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                                     MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_read_at_all, int, (fh, offset, buf, count, datatype, status));
    }

    int
    MPIIO::PMPI_File_read_at_all_begin(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_read_at_all_begin, int, (fh, offset, buf, count, datatype));
    }

    int MPIIO::PMPI_File_read_at(MPI_File fh, MPI_Offset offset, void *buf, int count, MPI_Datatype datatype,
                                 MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_read_at, int, (fh, offset, buf, count, datatype, status));
    }

    int MPIIO::PMPI_File_read(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_read, int, (fh, buf, count, datatype, status));
    }

    int MPIIO::PMPI_File_read_ordered_begin(MPI_File fh, void *buf, int count, MPI_Datatype datatype) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_read_ordered_begin, int, (fh, buf, count, datatype));
    }

    int MPIIO::PMPI_File_read_ordered(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_read_ordered, int, (fh, buf, count, datatype, status));
    }

    int MPIIO::PMPI_File_read_shared(MPI_File fh, void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_read_shared, int, (fh, buf, count, datatype, status));
    }

    int MPIIO::PMPI_File_sync(MPI_File fh) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_sync, int, (fh));
    }

    int MPIIO::PMPI_File_write_all_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_write_all_begin, int, (fh, buf, count, datatype));
    }

    int MPIIO::PMPI_File_write_all(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_write_all, int, (fh, buf, count, datatype, status));
    }

    int MPIIO::PMPI_File_write_at_all_begin(MPI_File fh, MPI_Offset offset, const void *buf, int count,
                                            MPI_Datatype datatype) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_write_at_all_begin, int, (fh, offset, buf, count, datatype));
    }

    int MPIIO::PMPI_File_write_at_all(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype,
                                      MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_write_at_all, int, (fh, offset, buf, count, datatype, status));
    }

    int MPIIO::PMPI_File_write_at(MPI_File fh, MPI_Offset offset, const void *buf, int count, MPI_Datatype datatype,
                                  MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_write_at, int, (fh, offset, buf, count, datatype, status));
    }

    int MPIIO::PMPI_File_write(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_write, int, (fh, buf, count, datatype, status));
    }

    int MPIIO::PMPI_File_write_ordered_begin(MPI_File fh, const void *buf, int count, MPI_Datatype datatype) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_write_ordered_begin, int, (fh, buf, count, datatype));
    }

    int
    MPIIO::PMPI_File_write_ordered(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_write_ordered, int, (fh, buf, count, datatype, status));
    }

    int
    MPIIO::PMPI_File_write_shared(MPI_File fh, const void *buf, int count, MPI_Datatype datatype, MPI_Status *status) {
        BRAHMA_UNWRAPPED_FUNC(PMPI_File_write_shared, int, (fh, buf, count, datatype, status));
    }
}

#endif //BRAHMA_MPIIO_H
