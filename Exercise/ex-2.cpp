#include <cstdlib>
#include <iostream>

int main() {
  int *ptr_int;

  ptr_int = (int *)malloc(sizeof(int));

  if (ptr_int == NULL) {
    std::cerr << "Erro: Falha ao alocar memoria!" << std::endl;

    return 1;
  }

  *ptr_int = 42;
  std::cout << "Valor atribuido: " << *ptr_int << std::endl;

  free(ptr_int);
  ptr_int = nullptr;

  return 0;
}
