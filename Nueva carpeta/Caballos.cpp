#include <iostream>
#include <vector>
using namespace std;

const int N = 8; // Tamaño del tablero de ajedrez

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
    // Verificar si hay un caballo en las casillas que ataca el actual
    static int movimientosX[] = {-2, -2, -1, -1, 1, 1, 2, 2};
    static int movimientosY[] = {-1, 1, -2, 2, -2, 2, -1, 1};

    for (int i = 0; i < 8; ++i) {
        int x = fila + movimientosX[i];
        int y = col + movimientosY[i];
        
        if (x >= 0 && y >= 0 && x < N && y < N && tablero[x][y] == 1) {
            return false;
        }
    }

    return true;
}

bool resolver(int tablero[N][N], int caballosColocados, int fila) {
    if (caballosColocados == N) {
        mostrarTablero(tablero);
        return true;
    }

    bool solucionEncontrada = false;
    for (int i = fila; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            if (esPosible(tablero, i, j) && tablero[i][j] == 0) {
                tablero[i][j] = 1;
                solucionEncontrada = resolver(tablero, caballosColocados + 1, i) || solucionEncontrada;
                tablero[i][j] = 0;
            }
        }
    }

    return solucionEncontrada;
}

int main() {
    int tablero[N][N] = {0};

    if (!resolver(tablero, 0, 0)) {
        cout << "No se encontraron soluciones." << endl;
    }

    return 0;
}
