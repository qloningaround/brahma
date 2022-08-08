//
// Created by hariharan on 8/8/22.
//

#ifndef BRAHMA_INTERCEPTOR_H
#define BRAHMA_INTERCEPTOR_H

#include <gotcha/gotcha.h>
#include <memory>

const int MAX_API_COUNT = 1024;
static gotcha_binding_t bindings[MAX_API_COUNT];
static int current_api_index = 0;
#define GOTCHA_BINDING_MACRO(fname) \
    bindings[current_api_index].name = #fname; \
    bindings[current_api_index].wrapper_pointer = (void*) fname##_wrapper; \
    bindings[current_api_index].function_handle = & fname##_handle;        \
    current_api_index++;

#define GOTCHA_MACRO(name, ret, args, args_val, class_name) \
typedef ret (*name##_fptr) args; \
static gotcha_wrappee_handle_t name##_handle; \
ret name##_wrapper args {             \
    return class_name::get_instance()->name args_val;    \
};

#define BRAHMA_WRAPPER(name) name##_wrapper;

#define BRAHMA_UNWRAPPED_FUNC(name, ret, args) \
fprintf(stderr, "[BRAHMA]\tFunction %s() not wrapped. Calling Original.\n", #name); \
name##_fptr name##_wrappee = (name##_fptr) gotcha_get_wrappee(name##_handle); \
ret result = name##_wrappee args; \
return result;

int update_posix();

int update_stdio();

int update_mpiio();

int bind_functions() {
    current_api_index = 0;
    update_posix();
    update_stdio();
    update_mpiio();
    return 0;
}

#endif //BRAHMA_INTERCEPTOR_H
