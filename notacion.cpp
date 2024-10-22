#include <iostream>
#include <stack>
#include <string>
#include <locale>
#include <cctype>

using namespace std;

// Función para determinar la precedencia de los operadores
int precedencia(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '^')
        return 3;
    return 0;
}

// Función para realizar la conversión de infijo a postfijo
string infijoAPostfijo(string infija) {
    stack<char> operadores;
    string postfija;
    
    for (char& c : infija) {
        if (isalnum(c)) {
            postfija += c;  // Añadir operandos a la salida directamente
        } else if (c == '(') {
            operadores.push(c);
        } else if (c == ')') {
            while (!operadores.empty() && operadores.top() != '(') {
                postfija += operadores.top();
                operadores.pop();
            }
            operadores.pop();  // Eliminar el paréntesis de apertura
        } else {
            while (!operadores.empty() && precedencia(operadores.top()) >= precedencia(c)) {
                postfija += operadores.top();
                operadores.pop();
            }
            operadores.push(c);
        }
    }
    
    while (!operadores.empty()) {
        postfija += operadores.top();
        operadores.pop();
    }
    
    return postfija;
}

int main() {
    setlocale(LC_ALL, "");
    string expresiones[] = {"(A+B)*(C-D)/E", "(M^(N-O))/P+Q", "((R*S)-(T/U))+V^W", "(J/(K+L))*(M-N^O)"};
    
    for (const string& infija : expresiones) {
        string postfija = infijoAPostfijo(infija);
        cout << "Expresión infija: " << infija << endl;
        cout << "Expresión postfija: " << postfija << endl;

        cout << endl;
        system("pause");
    }

    return 0;
}
