/**
 * @mainpage Proyecto de diseño modular: Circuito de Torneos de Tenis
*/

/** @file main.cc
    @brief Programa principal para el ejercicio <em>Circuito de Torneos de Tenis</em>.
*/


#include "Torneo.hh"
#include "Cjt_torneos.hh"
#include "Categorias.hh"
#include "Jugador.hh"
#include "Cjt_jugadores.hh"

int main() {
    int num_c, num_k;
    cin >> num_c >> num_k;
    Categorias categorias(num_c, num_k);

    int num_t;
    cin >> num_t;
    Cjt_torneos torneos(num_t);

    int num_p;
    cin >> num_p;
    Cjt_jugadores jugadores(num_p);

    string comando;
    cin >> comando;
    while (comando != "fin") {
       if (comando == "nuevo_jugador" or comando == "nj") {
            string p; 
            cin >> p;

            if (comando == "nuevo_jugador") cout << "#nuevo_jugador " << p << endl;
            else cout << "#nj " << p << endl;

            if (jugadores.existe_jugador(p)) cout << "error: ya existe un jugador con ese nombre" << endl;
            else {
                jugadores.nuevo_jugador(p);
                cout << jugadores.numero_jugadores() << endl;
            }
        }

       else if (comando == "nuevo_torneo" or comando == "nt") {
            string t; 
            int c;
            cin >> t  >> c;

            if (comando == "nuevo_torneo") cout << "#nuevo_torneo " << t << " " << c << endl;
            else cout << "#nt " << t << " " << c << endl;

            if (torneos.existe_torneo(t)) cout << "error: ya existe un torneo con ese nombre" << endl;
            else if (not categorias.existe_categoria(c)) cout << "error: la categoria no existe" << endl;
            else {
                torneos.nuevo_torneo(t,c);
                cout << torneos.numero_torneos() << endl;
            }
        }

        else if (comando == "baja_jugador" or comando == "bj") {
            string p; 
            cin >> p;

            if (comando == "baja_jugador") cout << "#baja_jugador " << p << endl;
            else cout << "#bj " << p << endl;

            if (not jugadores.existe_jugador(p)) cout << "error: el jugador no existe" << endl;
            else {
                jugadores.baja_jugador(p);
                cout << jugadores.numero_jugadores() << endl;

                torneos.baja_jugador_torneo(p);
            }
        }

        else if (comando == "baja_torneo" or comando == "bt") {
            string t; 
            cin >> t;

            if (comando == "baja_torneo") cout << "#baja_torneo " << t << endl;
            else cout << "#bt " << t << endl;

            if (not torneos.existe_torneo(t)) cout << "error: el torneo no existe" << endl;
            else {
                torneos.baja_torneo(t, jugadores);
                cout << torneos.numero_torneos() << endl;
            }
        }

        else if (comando == "iniciar_torneo" or comando == "it") {
            string t;
            int n; 
            cin >> t >> n;

            if (comando == "iniciar_torneo") cout << "#iniciar_torneo " << t << endl;
            else cout << "#it " << t << endl;

            Torneo torneo = torneos.consultar_torneo(t);
            torneo.iniciar_torneo(n, jugadores);
            torneos.modificar_torneo(t, torneo);
        }

        else if (comando == "finalizar_torneo" or comando == "ft") {
            string t; 
            cin >> t;

            if (comando == "finalizar_torneo") cout << "#finalizar_torneo " << t << endl;
            else cout << "#ft " << t << endl;

            Torneo torneo = torneos.consultar_torneo(t);
            torneo.finalizar_torneo(jugadores, categorias);
            torneos.modificar_torneo(t, torneo);
        }

        else if (comando == "listar_ranking" or comando == "lr") {
            if (comando == "listar_ranking") cout << "#listar_ranking" << endl;
            else cout << "#lr" << endl;
            jugadores.listar_ranking();
        }

        else if (comando == "listar_jugadores" or comando == "lj") {
            if (comando == "listar_jugadores") cout << "#listar_jugadores" << endl;
            else cout << "#lj" << endl;
            cout << jugadores.numero_jugadores() << endl;
            jugadores.listar_jugadores();
        }

        else if (comando == "consultar_jugador" or comando == "cj") {
            string p;
            cin >> p;

            if (comando == "consultar_jugador") cout << "#consultar_jugador " << p << endl;
            else cout << "#cj " << p << endl;

            if (not jugadores.existe_jugador(p)) cout << "error: el jugador no existe" << endl;
            else {
                Jugador jugador = jugadores.consultar_jugador(p);
                jugador.imprimir_jugador();
            }
        }

        else if (comando == "listar_torneos" or comando == "lt") {
            if (comando == "listar_torneos") cout << "#listar_torneos" << endl;
            else cout << "#lt" << endl;
            cout << torneos.numero_torneos() << endl;
            torneos.anadir_nom_cat(categorias);
            torneos.listar_torneos();
        } 

        else if (comando == "listar_categorias" or comando == "lc") {
            if (comando == "listar_categorias") cout << "#listar_categorias" << endl;
            else cout << "#lc" << endl;
            categorias.listar_categorias(); 
        }

        cin >> comando;
    }
}