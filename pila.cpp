#include <iostream>
#include <stack>
#include <string>
#include <locale>
#include <algorithm>
#include <iomanip>

using namespace std;

// Función para manejar la pila de caracteres y formar la palabra final
string procesarCadena(const string& cadena) {
    stack<char> pila;
    string resultado;
    for (char c : cadena) {
        if (c == '*') {
            if (!pila.empty()) {
                pila.pop();  // Pop en la pila si se encuentra un asterisco
            }
        } else {
            pila.push(c);  // Push en la pila si es una letra
        }
    }
    // Sacamos los elementos de la pila para formar la palabra
    while (!pila.empty()) {
        resultado += pila.top();
        pila.pop();
    }
    // Dado que los elementos se agregan en orden inverso, se debe revertir el resultado
    reverse(resultado.begin(), resultado.end());
    return resultado;
}

// Función para calcular el porcentaje de similitud entre dos palabras
float calcularSimilitud(const string& palabra, const string& comparacion) {
    int coincidencias = 0;
    int longitud = min(palabra.length(), comparacion.length());
    for (int i = 0; i < longitud; i++) {
        if (palabra[i] == comparacion[i]) {
            coincidencias++;
        }
    }
    return (float(coincidencias) / comparacion.length()) * 100;
}

int main() {
    setlocale(LC_ALL,"");
    string palabras[] = {"BIENVENIDO", "HOLA", "MUNDO", "ADIOS", "CODIGO"};
    string cadena, resultado;
    
    cout << "Ingrese una cadena de caracteres y asteriscos: ";
    cin >> cadena;
    
    resultado = procesarCadena(cadena);
    cout << "La palabra formada es: " << resultado << endl;
    
    // Comparar con las palabras del arreglo y calcular similitud
    for (const string& palabra : palabras) {
        float similitud = calcularSimilitud(resultado, palabra);
        cout << "Similitud con \"" << palabra << "\": " << fixed << setprecision(2) << similitud << "%" << endl;
        system("pause");
    }

    return 0;
}
