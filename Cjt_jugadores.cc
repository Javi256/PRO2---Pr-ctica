#include "Cjt_jugadores.hh"

Cjt_jugadores::Cjt_jugadores() {

}

Cjt_jugadores::Cjt_jugadores(int& num_p) {
    for (int i = 0; i < num_p; ++i) {
        string nombre;
        cin >> nombre;
        Jugador jugador(nombre);
        int k = i+1;
        jugador.modificar_ranking(k);

        Jugador_ran jug;
        jug.nombre = nombre;

        ranking.push_back(jug);
        cjt_jugadores.insert({nombre, jugador}); //???
    }
}

Jugador Cjt_jugadores::consultar_jugador(string& p) {
    return cjt_jugadores[p];
}

string Cjt_jugadores::consultar_nombre_jugador(int& n) {
    return ranking[n-1].nombre;
}

bool Cjt_jugadores::existe_jugador(string& p) {
    map<string, Jugador>::const_iterator it = cjt_jugadores.find(p);
    if (it == cjt_jugadores.end()) return false;
    else return true;  
}

void Cjt_jugadores::nuevo_jugador(string & p) {
    Jugador jugador(p);
    int k = ranking.size() + 1;
    if (ranking.size() == 0) k = 1;
    jugador.modificar_ranking(k);

    Jugador_ran jug;
    jug.nombre = p;

    ranking.push_back(jug);
    cjt_jugadores.insert({p, jugador});
}

void Cjt_jugadores::baja_jugador(string& p) {
    map<string, Jugador>::const_iterator it = cjt_jugadores.find(p);
    int k = cjt_jugadores[it->first].consultar_ranking();

    for (int i = k-1; i < ranking.size(); ++i) {
        if (i+1 < ranking.size()) {
            ranking[i] = ranking[i+1];
        }
    }
    ranking.pop_back();
    it = cjt_jugadores.erase(it);

    for (int i = 0; i < ranking.size(); ++i) {
        int j = i+1;
        cjt_jugadores[ranking[i].nombre].modificar_ranking(j);
    }
}

bool Cjt_jugadores::comp(const Jugador_ran& a, const Jugador_ran& b) {
    if (a.puntos != b.puntos) {
        return a.puntos > b.puntos;
    }
    else return a.pos_ant < b.pos_ant;
}

void Cjt_jugadores::actualizar_ranking() {
    for (int i = 0; i < ranking.size(); i++) {
        ranking[i].pos_ant = i+1;
        ranking[i].puntos = cjt_jugadores[ranking[i].nombre].consultar_puntos();
    }

    sort(ranking.begin(), ranking.end(), comp);

    for (int i = 0; i < ranking.size(); ++i) {
        int j = i+1;
        cjt_jugadores[ranking[i].nombre].modificar_ranking(j);
    }
}

void Cjt_jugadores::modificar_jugador(string& p, Jugador& jugador) {
    cjt_jugadores[p] = jugador;
}

void Cjt_jugadores:: listar_jugadores() {
    map<string, Jugador>::const_iterator it = cjt_jugadores.begin();
    for (; it != cjt_jugadores.end(); ++it) {
    cjt_jugadores[it->first].imprimir_jugador();
    }
} 

int Cjt_jugadores::numero_jugadores() {
    return cjt_jugadores.size();
}

void Cjt_jugadores::listar_ranking() {
    for (int i = 0; i < ranking.size(); ++i) {
        int pts = cjt_jugadores[ranking[i].nombre].consultar_puntos();
        cout << i+1 << " " << ranking[i].nombre << " " << pts << endl;
    }
}