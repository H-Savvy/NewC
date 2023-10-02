#include <iostream>
using namespace std;
const int N = 4;
void mostrarTablero(int tablero[N][N]) {
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            cout << tablero[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
bool esPosible(int tablero[N][N], int fila, int col) {
    // Verificar vertical (misma columna)
    for (int i = 0; i < fila; ++i) {
        if (tablero[i][col] == 1) {
            return false;
        }
    }
    // Diagonal de izquierda a derecha, abajo a arriba
    for (int i = fila, j = col; i >= 0 && j < N; --i, ++j) {
        if (tablero[i][j] == 1) {
            return false;
        }
    }
    // Diagonal de izquierda abajo a derecha arriba
    for (int i = fila, j = col; i >= 0 && j >= 0; --i, --j) {
        if (tablero[i][j] == 1) {
            return false;
        }
    }
    return true;
}
bool resolver(int tablero[N][N], int fila) {
    if (fila == N) {
        mostrarTablero(tablero);
        return true;
    }
    bool solucionEncontrada = false;
    for (int i = 0; i < N; ++i) {
        if (esPosible(tablero, fila, i)) {
            tablero[fila][i] = 1;
            solucionEncontrada = resolver(tablero, fila + 1) || solucionEncontrada;
            tablero[fila][i] = 0;
        }
    }
    return solucionEncontrada;
}
int main() {
    int tablero[N][N] = {{0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0},
                         {0, 0, 0, 0}};
    if (!resolver(tablero, 0)) {
        cout << "solucion no encontrada" << endl;
    }
    return 0;
}
