// Questão 5
#include <iostream>
using namespace std;

int main() {
  const int TAM = 8;
  double valores[TAM];
  double soma = 0.0;

  cout << "Digite " << TAM << " numeros do tipo double:" << endl;
  for (int i = 0; i < TAM; i++) {
    cout << "Valor [" << i << "]: ";
    cin >> valores[i]; // Receber valores
    soma += valores[i];
  }

  double media = soma / TAM; // Media

  int acimaMedia = 0;
  for (int i = 0; i < TAM; i++) {
    if (valores[i] > media) {
      acimaMedia++;
    }
  }

  cout << "\nMedia dos valores: " << media << endl;
  cout << "Quantidade de valores acima da media: " << acimaMedia << endl;

  return 0;
}
