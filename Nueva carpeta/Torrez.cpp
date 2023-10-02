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
    // Verificar si hay una torre en la misma fila
    for (int i = 0; i < N; ++i) {
        if (tablero[fila][i] == 1) {
            return false;
        }
    }

    // Verificar si hay una torre en la misma columna
    for (int i = 0; i < N; ++i) {
        if (tablero[i][col] == 1) {
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
        cout << "Solucion no encontrada" << endl;
    }

    return 0;
}
