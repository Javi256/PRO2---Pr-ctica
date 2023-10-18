#include "Jugador.hh"

Jugador::Jugador() {
    nombre = " ";
}
 
Jugador::Jugador(string& p) {
    nombre = p;
} 

void Jugador::modificar_ranking(int& r) {
    ranking = r;
}

void Jugador::modificar_puntos(int ps) {
    //if (puntos > 0) 
    puntos += ps;
}
 
void Jugador::actualizar_estadisticas(int ps, int ts, int wm, int lm, int ws, int ls, int wg, int lg) {
    puntos += ps;
    Ts += ts;
    WM += wm;
    LM += lm;
    WS += ws;
    LS += ls;
    WG += wg;
    LG += lg;
} 

int Jugador::consultar_ranking() {
    return ranking;
}

int Jugador::consultar_puntos() {
    return puntos;
}

void Jugador::imprimir_jugador() {
    cout << nombre << " Rk:" << ranking << " Ps:" << puntos;
    cout << " Ts:" << Ts;
    cout << " WM:" << WM << " LM:" << LM;
    cout << " WS:" << WS << " LS:" << LS;
    cout << " WG:" << WG << " LG:" << LG;
    cout << endl;
}