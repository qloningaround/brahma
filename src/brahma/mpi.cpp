//
// Created by haridev on 9/6/22.
//

#include <brahma/mpi.h>
GOTCHA_MACRO(MPI_Init, int, (int *argc, char ***argv), (argc, argv), brahma::MPI);
GOTCHA_MACRO(MPI_Finalize, int, (), (), brahma::MPI);

int update_mpi(gotcha_binding_t *&bindings, size_t &binding_index) {
  GOTCHA_BINDING_MACRO(MPI_Init);
  GOTCHA_BINDING_MACRO(MPI_Finalize);
  return 0;
}
size_t count_mpi() { return 2; }

namespace brahma {
  std::shared_ptr<MPI> MPI::my_instance = nullptr;
  int MPI::MPI_Init(int *argc, char ***argv) {
    BRAHMA_UNWRAPPED_FUNC(MPI_Init, int, (argc, argv));
    return result;
  }
  int MPI::MPI_Finalize() {
    BRAHMA_UNWRAPPED_FUNC(MPI_Finalize, int, ());
    return result;
  }
}  // namespace brahma
