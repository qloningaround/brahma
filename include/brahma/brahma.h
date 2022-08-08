//
// Created by hariharan on 8/8/22.
//

#ifndef BRAHMA_BRAHMA_H
#define BRAHMA_BRAHMA_H

#include <brahma/interface/posix.h>
#include <brahma/interface/stdio.h>
#include <brahma/interface/mpiio.h>
#include <cassert>

void brahma_gotcha_wrap(const char *name, uint16_t priority) {
    assert(bind_functions() == 0);
    gotcha_wrap(bindings, current_api_index - 2, name);
    gotcha_set_priority(name, priority);
}

void __attribute__((constructor)) brahma_init() {
    //brahma_gotcha_wrap("brahma", 0);
}

void __attribute__((destructor)) brahma_finalize() {

}

#endif //BRAHMA_BRAHMA_H
