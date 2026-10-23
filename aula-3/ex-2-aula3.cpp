#include <cstdlib>
#include <iomanip>
#include <iostream>

int main() {
  int k = 0;

  while (k <= 0) {
    std::cout << "Numero de candidatos: ";
    if (!(std::cin >> k)) {
      std::cerr << "Erro na leitura da entrada." << std::endl;
      return 1;
    }
    if (k <= 0) {
      std::cout << "Valor invalido! Deve haver pelo menos 1 candidato."
                << std::endl;
    }
  }

  int *votos = static_cast<int *>(calloc(k + 1, sizeof(int)));
  if (votos == nullptr) {
    std::cerr << "Erro: falha na alocacao de memoria!" << std::endl;
    return 1;
  }
  std::cout << "Memoria alocada: " << (k + 1) * sizeof(int) << " bytes"
            << std::endl;

  std::cout << "Digite os votos (0 encerra): ";
  int v;
  int validos = 0;
  while (std::cin >> v && v != 0) {
    if (v >= 1 && v <= k) {
      votos[v]++;
      validos++;
    } else {
      votos[0]++;
    }
  }

  std::cout << std::fixed << std::setprecision(1);
  int maior = 0;
  for (int i = 1; i <= k; ++i) {
    double perc = 0.0;
    if (validos > 0) {
      perc = 100.0 * votos[i] / validos;
    }
    std::cout << "Candidato " << i << ": " << votos[i] << " voto(s) ("
              << std::setw(5) << perc << "%) ";
    for (int j = 0; j < votos[i]; ++j)
      std::cout << '*';
    std::cout << std::endl;
    if (votos[i] > maior)
      maior = votos[i];
  }
  std::cout << "Votos nulos: " << votos[0] << std::endl;

  if (validos == 0) {
    std::cout << "Nenhum voto valido: nao ha vencedor." << std::endl;
  } else {
    int vencedor = 0;
    int empatados = 0;
    for (int i = 1; i <= k; ++i) {
      if (votos[i] == maior) {
        ++empatados;
        vencedor = i;
      }
    }
    if (empatados >= 2) {
      std::cout << "empate!" << std::endl;
    } else {
      std::cout << "Vencedor: candidato " << vencedor << std::endl;
    }
  }

  free(votos);
  votos = nullptr;

  return 0;
}
