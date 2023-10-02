#include <iostream>
using namespace std;

const int N = 9; // Tamaño del tablero de Sudoku

bool esSeguro(int tablero[N][N], int fila, int col, int num) {
    // Verificar si el número num ya está en la fila o columna
    for (int i = 0; i < N; ++i) {
        if (tablero[fila][i] == num || tablero[i][col] == num) {
            return false;
        }
    }

    // Verificar si el número num ya está en la región 3x3
    int inicioFila = fila - fila % 3;
    int inicioCol = col - col % 3;
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (tablero[inicioFila + i][inicioCol + j] == num) {
                return false;
            }
        }
    }

    return true;
}

bool resolverSudoku(int tablero[N][N]) {
    int fila, col;
    bool vacio = false;

    // Buscar una celda vacía
    for (fila = 0; fila < N; ++fila) {
        for (col = 0; col < N; ++col) {
            if (tablero[fila][col] == 0) {
                vacio = true;
                break;
            }
        }
        if (vacio) {
            break;
        }
    }

    // Si no hay celdas vacías, se ha resuelto
    if (!vacio) {
        return true;
    }

    // Probar números del 1 al 9
    for (int num = 1; num <= 9; ++num) {
        if (esSeguro(tablero, fila, col, num)) {
            tablero[fila][col] = num;

            // Recursivamente intentar llenar el resto del tablero
            if (resolverSudoku(tablero)) {
                return true;
            }

            // Si no se puede encontrar una solución, deshacer el cambio
            tablero[fila][col] = 0;
        }
    }

    // No se encontró una solución
    return false;
}

void mostrarTablero(int tablero[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
}

int main() {
    int tablero[N][N] = {{5, 3, 0, 0, 7, 0, 0, 0, 0},
                         {6, 0, 0, 1, 9, 5, 0, 0, 0},
                         {0, 9, 8, 0, 0, 0, 0, 6, 0},
                         {8, 0, 0, 0, 6, 0, 0, 0, 3},
                         {4, 0, 0, 8, 0, 3, 0, 0, 1},
                         {7, 0, 0, 0, 2, 0, 0, 0, 6},
                         {0, 6, 0, 0, 0, 0, 2, 8, 0},
                         {0, 0, 0, 4, 1, 9, 0, 0, 5},
                         {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (resolverSudoku(tablero)) {
        mostrarTablero(tablero);
    } else {
        cout << "No se encontró una solución." << endl;
    }

    return 0;
}
