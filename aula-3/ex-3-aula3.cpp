#include <cstdlib>
#include <iostream>

int *aumentaCapacidade(int *antigo, int tamanho, int &capacidade) {
  int novaCapacidade = capacidade * 2;
  int *novo = static_cast<int *>(
      malloc(static_cast<size_t>(novaCapacidade) * sizeof(int)));
  if (novo == nullptr) {
    return nullptr;
  }

  for (int i = 0; i < tamanho; ++i) {
    novo[i] = antigo[i];
  }

  free(antigo);
  antigo = nullptr;

  std::cout << "[capacidade: " << capacidade << " -> " << novaCapacidade << "]"
            << std::endl;
  capacidade = novaCapacidade;
  return novo;
}

int main() {
  int capacidade = 2;
  int tamanho = 0;
  int expansoes = 0;

  int *v =
      static_cast<int *>(malloc(static_cast<size_t>(capacidade) * sizeof(int)));
  if (v == nullptr) {
    std::cerr << "Erro: falha na alocacao de memoria!" << std::endl;
    return 1;
  }

  std::cout << "Digite inteiros nao negativos (-1 encerra):" << std::endl;
  int x;
  while (std::cin >> x && x != -1) {
    if (x < 0) {
      std::cout << "Valor negativo ignorado (use -1 para encerrar)."
                << std::endl;
      continue;
    }

    if (tamanho == capacidade) {
      int *novo = aumentaCapacidade(v, tamanho, capacidade);
      if (novo == nullptr) {
        std::cerr << "Erro: falha ao aumentar a capacidade!" << std::endl;
        free(v);
        v = nullptr;
        return 1;
      }
      v = novo;
      ++expansoes;
    }

    v[tamanho] = x;
    ++tamanho;
  }

  std::cout << "Ordem inversa:";
  for (int i = tamanho - 1; i >= 0; --i) {
    std::cout << " " << v[i];
  }
  std::cout << std::endl;
  std::cout << "Elementos: " << tamanho << ", Capacidade final: " << capacidade
            << ", Expansoes: " << expansoes << std::endl;
  std::cout << "Memoria ociosa: " << (capacidade - tamanho) * sizeof(int)
            << " bytes" << std::endl;

  free(v);
  v = nullptr;

  return 0;
}
