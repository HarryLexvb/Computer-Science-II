#include <iostream>
#include <ctime>
#include <cstdlib>

using namespace std;

void MULT_MAT(int** A, int** B, int** C, int m, int n, int o) {

    int producto = 0;
    for(int i = 0; i < m; i++) {
        for(int j = 0; j < o; j++) {
            for(int k = 0; k < n; k++) {
                producto = (*(*(A + i) + k)) * (*(*(B + k) + j));
                *(*(C + i) + j) += p;
            }
        }
    }
}

void imprimir(int** matriz, int filas, int columnas) {

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            cout<<*(*(matriz + i) + j )<<" ";
        }
        cout<<endl;
    }
}

int** crearMatriz(int filas, int columnas) {
    int** matriz = new int*[filas];

    for(int i = 0; i < filas; i++) {
        *(matriz + i) = new int[columnas];

        for(int j = 0; j < columnas; j++) {
            *(*(matriz + i) + j ) = 0;
        }
    }

    return matriz;
}

void llenarMatriz(int** matriz, int filas, int columnas) {

    srand(time(NULL));

    for(int i = 0; i < filas; i++) {
        for(int j = 0; j < columnas; j++) {
            *(*(matriz + i) + j ) = rand() % 100 + 1;
        }
    }
}


int main()
{
    int **A, **B, **C;
    int m, n, o;
    m = 3;
    n = 4;
    o = 3;

    // Crear matrices dinamicas A, B, y C
    A = crearMatriz(m, n);
    B = crearMatriz(n, o);
    C = crearMatriz(m, o);

    // Llenar matrices dinamicas A, B
    llenarMatriz(A, m, n);
    llenarMatriz(B, n, o);

    // Multiplicar matrices
    MULT_MAT(A, B, C, m, n, o);

    // Imprimir matrices dinamicas A, B y C
    imprimir(A, m, n);
    cout<<endl;
    imprimir(B, n, o);
    cout<<endl;
    imprimir(C, m, o);

    return 0;
}
