//calculadora em c++
#include <iostream>
#include <cmath>
using namespace std;

int main() {
    float num1, num2, resultado;

    cout << "Digite o primeiro número: ";
    cin >> num1;
    cout << "Digite o segundo número: ";
    cin >> num2;

    cout << "Escolha uma operação:" << endl;
    cout << "1. Adição" << endl;
    cout << "2. Subtração" << endl;
    cout << "3. Multiplicação" << endl;
    cout << "4. Divisão" << endl;
    cout << "5. Potenciação" << endl;
    int opcao;
    cin >> opcao;

    switch (opcao) {
        case 1:
            resultado = num1 + num2;
            cout << "Resultado: " << resultado << endl;
            break;
        case 2:
            resultado = num1 - num2;
            cout << "Resultado: " << resultado << endl;
            break;
        case 3:
            resultado = num1 * num2;
            cout << "Resultado: " << resultado << endl;
            break;
        case 4:
            if (num2 != 0) {
                resultado = num1 / num2;
                cout << "Resultado: " << resultado << endl;
            } else {
                cout << "Erro: Divisão por zero não é permitida." << endl;
            }
            break;
        case 5:
            resultado = pow(num1, num2);
            cout << "Resultado: " << resultado << endl;
            break;
        default:
            cout << "Opção inválida." << endl;
    }

    return 0;
}

