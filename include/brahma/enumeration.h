//
// Created by haridev on 8/28/22.
//

#ifndef BRAHMA_ENUMERATION_H
#define BRAHMA_ENUMERATION_H
#include <cstdint>
namespace brahma {
enum InterfaceType { INTERFACE_POSIX = 0, INTERFACE_STDIO = 1, INTERFACE_MPIIO = 2, INTERFACE_HDF5 = 3 };
}
#endif  // BRAHMA_ENUMERATION_H
