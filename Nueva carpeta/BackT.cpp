#include <iostream>
#include <vector>
using namespace std;

void constSubconjunto(vector<int>& A, vector<vector<int>>& res, vector<int>& subconj, int pos, int objetivo) {
    // Agregar el subconjunto si cumple con el objetivo
    int suma = 0;
    for (int num : subconj) {
        suma += num;
    }
    if (suma == objetivo) {
        res.push_back(subconj);
    }

    // Generar subconjuntos de forma recursiva
    for (int i = pos; i < (int)A.size(); i++) {
        // Incluir el elemento actual en el subconjunto si no excede el objetivo
        if (suma + A[i] <= objetivo) {
            subconj.push_back(A[i]);
            // Recursivamente generar subconjuntos con el elemento actual incluido
            constSubconjunto(A, res, subconj, i + 1, objetivo);
            // Excluir el elemento actual del subconjunto (backtracking)
            subconj.pop_back();
        }
    }
}
vector<vector<int>> generar(vector<int>& A, int objetivo) {
    vector<int> subconjunto;
    vector<vector<int>> resultado;
    int pos = 0;
    constSubconjunto(A, resultado, subconjunto, pos, objetivo);
    return resultado;
}
int main() {
    vector<int> arr = {14, 10, 6};
    int objetivo;
    cout << "Ingrese el objetivo: ";
    cin >> objetivo;

    vector<vector<int>> sub_arr = generar(arr, objetivo);

    if (sub_arr.empty()) {
        cout << "No se encontraron subconjuntos que sumen el objetivo." << endl;
    } else {
        cout << "Subconjuntos que suman el objetivo " << objetivo << ":" << endl;
        for (int i = 0; i < (int)sub_arr.size(); i++) {
            for (int j = 0; j < (int)sub_arr[i].size(); j++)
                cout << sub_arr[i][j] << " ";
            cout << endl;
        }
    }

    return 0;
}
