#include "Cjt_torneos.hh"

Cjt_torneos::Cjt_torneos() {

}

Cjt_torneos::Cjt_torneos(int& num_t) {
    for(int i = 0; i < num_t; i++) {
        string nombre;
        int cat;
        cin >> nombre >> cat;

        Torneo torneo(nombre, cat);
        cjt_torneos.insert({nombre, torneo});
    }
}
    
Torneo Cjt_torneos::consultar_torneo(string& t) {
    return cjt_torneos[t];
}

bool Cjt_torneos::existe_torneo(string& t) {
    map<string, Torneo>::const_iterator it = cjt_torneos.find(t);
    if (it == cjt_torneos.end()) return false;
    else return true;
}

void Cjt_torneos::modificar_torneo(string& t, Torneo& torneo) {
    cjt_torneos[t] = torneo;
}

void Cjt_torneos::baja_jugador_torneo(string& p) {
    map<string, Torneo>::const_iterator it = cjt_torneos.begin();
    for (; it != cjt_torneos.end(); ++it) {
        cjt_torneos[it->first].eliminar_jugador(p);
    }
}

void Cjt_torneos::anadir_nom_cat(Categorias& categorias) {
    map<string, Torneo>::const_iterator it = cjt_torneos.begin();
    for (; it != cjt_torneos.end(); ++it) {
        int cat = cjt_torneos[it->first].consultar_categoria();
        string ct = categorias.consultar_categoria(cat);
        cjt_torneos[it->first].modificar_nom_cat(ct);
    }
}

void Cjt_torneos::nuevo_torneo(string& t, int& c) {
    Torneo torneo(t, c);
    cjt_torneos.insert({t, torneo});
}

void Cjt_torneos::baja_torneo(string& t, Cjt_jugadores& jugadores) {
    cjt_torneos[t].restar_puntos(jugadores);
    jugadores.actualizar_ranking();
    cjt_torneos.erase(t);
}

void Cjt_torneos::listar_torneos() {
    map<string, Torneo>::const_iterator it = cjt_torneos.begin();
    for (; it != cjt_torneos.end(); ++it) {
    cjt_torneos[it->first].imprimir_torneo();
    }
}

int Cjt_torneos::numero_torneos() {
    return cjt_torneos.size();
}