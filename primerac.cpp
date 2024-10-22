#include <iostream>
using namespace std;
int main(   ){

int x = 0;
if (x > 0) {
    std::cout << "x es positivo" << std::endl;
} else if (x == 0) {
    std::cout << "x es cero" << std::endl;
} else {
    std::cout << "x es negativo" << std::endl;
}


int vect[10], mat[3][5], *p;
p = &vect[0];
cout << *(p + 2) << endl; /* se imprimirá vect[2]*/
p = &mat[0][0];
cout << *(p + 2) << endl; /* se imprimirá mat[0][2]*/
cout << *(p + 4) << endl; /* se imprimirá mat[0][4]*/
cout << *(p + 5) << endl; /* se imprimirá mat[1][0]*/
cout << *(p + 12) << endl; 
    system("pause");
    return 0;
}