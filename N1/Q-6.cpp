// Questão 6
#include <iostream>
#include <vector>
using namespace std;

void multiplicar(vector<int> &num, int x) {
  int carry = 0;
  for (size_t i = 0; i < num.size(); i++) {
    int prod = num[i] * x + carry;
    num[i] = prod % 10;
    carry = prod / 10;
  }

  while (carry > 0) {
    num.push_back(carry % 10);
    carry /= 10;
  }
}

void fatorial(int n, vector<int> &resultado) {
  if (n <= 1) {
    resultado.assign(1, 1);
    return;
  }
  fatorial(n - 1, resultado);
  multiplicar(resultado, n);
}

int main() {
  int n;
  int Continuar = 1;

  cout << "Calculadora fatorial";
  cout << endl;

  while (Continuar == 1) {
    cout << "Digite um numero inteiro nao negativo: ";
    cin >> n;

    if (n < 0) {
      cout << "Error Nao existe fatorial de numero negativo." << endl;
      return 1;
    }

    vector<int> resultado;
    fatorial(n, resultado);

    cout << n << "! = ";
    for (int i = (int)resultado.size() - 1; i >= 0; i--)
      cout << resultado[i];
    cout << endl;

    cout << "Digite 1 para continuar e qualquer outro numero para terminar ";
    cout << endl;
    cin >> Continuar;
  }
  if (Continuar != 1) {

    return 0;
  }
}
