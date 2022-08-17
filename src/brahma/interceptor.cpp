//
// Created by hariharan on 8/16/22.
//
#include <brahma/interceptor.h>

namespace brahma {
gotcha_binding_t* bindings = nullptr;
size_t total_apis = 0;
}  // namespace brahma

extern int brahma_bind_functions() {
  if (brahma::bindings == nullptr) {
    brahma::total_apis = count_posix() + count_mpiio() + count_stdio();
    brahma::bindings = static_cast<gotcha_binding_t*>(
        calloc(brahma::total_apis, sizeof(gotcha_binding_t)));
    size_t current_index = 0;
    update_posix(brahma::bindings, current_index);
    update_stdio(brahma::bindings, current_index);
    update_mpiio(brahma::bindings, current_index);
    if (current_index != brahma::total_apis) {
      BRAHMA_LOGERROR("brahma_bind_functions failed", "");
      return -1;
    }
  }
  return 0;
}

extern int brahma_get_binding(gotcha_binding_t*& bindings_i,
                              size_t& binding_count) {
  bindings_i = brahma::bindings;
  binding_count = brahma::total_apis;
  return 0;
}

extern int free_bindings() {
  free(brahma::bindings);
  return 0;
}