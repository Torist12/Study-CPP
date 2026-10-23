#include <cstdlib>
#include <iomanip>
#include <iostream>

int main() {

  int n = 0;

  while (n <= 0) {
    std::cout << "Quantidade de alunos: ";
    if (!(std::cin >> n)) {
      std::cerr << "Erro na leitura da entrada." << std::endl;
      return 1;
    }
    if (n <= 0) {
      std::cout << "Quantidade invalida! Digite um valor maior que 0!"
                << std::endl;
    }
  }
  size_t bytes = static_cast<size_t>(n) * sizeof(double);
  double *notas = static_cast<double *>(malloc(bytes));
  if (notas == nullptr) {
    std::cerr << "Erro: falha na alocacao de memoria!" << std::endl;
    return 1;
  }
  std::cout << "Memoria alocada: " << bytes << "bytes" << std::endl;

  for (int i = 0; i < n; ++i) {
    double nota;
    while (true) {
      std::cout << "Nota do aluno: " << i + 1 << ": ";
      if (!(std::cin >> nota)) {
        std::cerr << "Erro na leitura da entrada" << std::endl;
        free(notas);
        notas = nullptr;
        return 1;
      }
      if (nota >= 0.0 && notas[i] <= 10.0) {
        break;
      }
      std::cout << "Nota invalida! Digite um valor entre 0 e 10! " << std::endl;
    }
    notas[i] = nota;
  }

  double soma = 0.0;
  double maior = notas[0];
  double menor = notas[0];
  for (int i = 0; i < n; i++) {
    soma += notas[i];
    if (notas[i] > maior)
      maior = notas[i];
    if (notas[i] < menor)
      menor = notas[i];
  }
  double media = soma / n;

  int acima = 0;
  for (int i = 0; i < n; i++) {
    if (notas[i] > media)
      ++acima;
  }

  std::cout << std::fixed << std::setprecision(2);
  std::cout << "Media da turma: " << media << std::endl;
  std::cout << "Maior nota: " << maior << std::endl;
  std::cout << "Menor nota: " << menor << std::endl;
  std::cout << "Aluno acima da da media: " << acima << std::endl;

  free(notas);
  notas = nullptr;

  return 0;
}
