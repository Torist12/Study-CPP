#include <cstdlib>
#include <iostream>

int main() {

  int n = 5;

  double *ptr_array;

  size_t bytes_necessarios = n * sizeof(double);
  ptr_array = static_cast<double *>(malloc(bytes_necessarios));

  if (ptr_array == nullptr) {
    std::cerr << "Erro: Falha ao alocar array!" << std::endl;
  }

  for (int i = 0; i < n; ++i) {
    ptr_array[i] = i * 1.1;
  }

  std::cout << "Array inicializado: " << std::endl;
  for (int i = 0; i < n; ++i) {
    std::cout << "ptr_array[" << i << "] = " << ptr_array[i] << std::endl;
  }

  free(ptr_array);
  ptr_array = nullptr;

  return 0;
}
