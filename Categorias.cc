#include "Categorias.hh"

Categorias::Categorias() {

}

Categorias::Categorias(int& num_c, int& num_k) {
    Cjt_categorias = vector<string>(num_c);
    num_C = num_c;
    string nombre_cat;
    for (int i = 0; i < num_c; ++i) {
        cin >> nombre_cat;
        Cjt_categorias[i] = nombre_cat;
    }

    Puntos = vector< vector<int> >(num_c, vector<int>(num_k));
    num_K = num_k;
    int puntos;
    for (int i = 0; i < num_C; ++i){
        for (int j = 0; j < num_K; ++j) {
            cin >> puntos;
            Puntos[i][j] = puntos;
        }
    }
}

bool Categorias::existe_categoria(int& c) {
    if (c > 0 and c <= num_C) return true;
    else return false;
}

int Categorias::consultar_puntos(int& c, const int& k) {
    return Puntos[c-1][k-1];
}

string Categorias::consultar_categoria(int& c) {
    return Cjt_categorias[c-1];
}

void Categorias::listar_categorias() {
    cout << num_C << " " << num_K << endl;

    for (int i = 0; i < num_C; ++i) {
        cout << Cjt_categorias[i] << " ";
        for (int j = 0; j < num_K; ++j) {
            cout << Puntos[i][j];
            if (j+1 != num_K) cout << " ";
        }
        cout << endl;
    }
}