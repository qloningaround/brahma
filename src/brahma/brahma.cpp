//
// Created by hariharan on 8/8/22.
//

#include <brahma/brahma.h>

extern void brahma_gotcha_wrap(const char* name, uint16_t priority) {
  int status = brahma_bind_functions();
  if (status != 0) {
    fprintf(stderr, "bind functions failed");
    return;
  }
  gotcha_binding_t* bindings = nullptr;
  size_t total_apis = 0;
  status = brahma_get_binding(bindings, total_apis);
  if (status != 0) {
    fprintf(stderr, "brahma_get_binding failed");
    return;
  }
  gotcha_wrap(bindings, total_apis, name);
  gotcha_set_priority(name, priority);
}