#include <iostream>
#include <stack> 
#include <locale>

using namespace std;

void pushElements(stack<int>& pila, int n) {
    for (int i = 0; i < n; i++) {
        int elemento;
        cout << "Ingrese el elemento " << i + 1 << ": ";
        cin >> elemento;
        pila.push(elemento);
    }
}


bool isEmpty(stack<int>& pila) {
    return pila.empty();
}


void popElements(stack<int>& pila, int cantidad) {
    for (int i = 0; i < cantidad && !pila.empty(); i++) {
        pila.pop();
    }
}


void showTopElement(stack<int>& pila) {
    if (!pila.empty()) {
        cout << "El último elemento ingresado es: " << pila.top() << endl;
    } else {
        cout << "La pila está vacía." << endl;
    }
}


void pilaSize(stack<int>& pila) {
    cout << "El tamaño de la pila es: " << pila.size() << endl;
}

int main() {
    setlocale(LC_ALL,"");
    stack<int> pila;
    int opcion, n, cantidad;

    do {
        cout << "\n1. Ingresar elementos en la pila\n";
        cout << "2. Determinar si la pila tiene elementos\n";
        cout << "3. Sacar elementos de la pila\n";
        cout << "4. Ver el último elemento de la pila\n";
        cout << "5. Determinar el tamaño de la pila\n";
        cout << "6. Salir\n";
        cout << "Seleccione una opcion: ";
        cin >> opcion;

        switch (opcion) {
            case 1:
                cout << "¿Cuántos elementos desea ingresar?: ";
                cin >> n;
                pushElements(pila, n);
                break;
            case 2:
                if (isEmpty(pila)) {
                    cout << "La pila está vacía.\n";
                } else {
                    cout << "La pila contiene elementos.\n";
                }
                break;
            case 3:
                cout << "¿Cuántos elementos desea sacar?: ";
                cin >> cantidad;
                popElements(pila, cantidad);
                break;
            case 4:
                showTopElement(pila);
                break;
            case 5:
                pilaSize(pila);
                break;
            case 6:
                cout << "Saliendo...\n";
                break;
            default:
                cout << "Opción inválida.\n";
        }
    } while (opcion != 6);

    return 0;
}
