/** @file Jugador.hh
    @brief Especificación de la clase Jugador 
*/

#ifndef _JUGADOR_HH_
#define _JUGADOR_HH_
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
using namespace std;
#endif

/** @class Jugador
    @brief Representa un Jugador
*/

class Jugador {
private:
    string nombre;
    int ranking = 0; 
    int puntos = 0;

    //Categorias
    int Ts = 0; //torneos disputados
    int WM = 0; //partidos ganados
    int LM = 0; //partidos perdidos
    int WS = 0; //sets ganados
    int LS = 0; //sets perdidos
    int WG = 0; //juegos ganados
    int LG = 0; //juegos perdidos
    
public:
    //Constructoras

    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar un jugador.
        \pre <em>cierto</em>
        \post El resultado es un jugador sin nombre ni estadísticas definidas.
    */  
    Jugador();

    /** @brief Creadora de Jugador. 
        \pre <em>cierto</em>
        \post El resultado es un jugador con nombre p y sin estadísticas definidas.
    */ 
    Jugador(string& p);

    //Modificadoras
    /** @brief Modificadora de ranking. 
        \pre <em>cierto</em>
        \post El resultado es el parámetro implícito (jugador) con posición "r" en el ranking.
    */ 
    void modificar_ranking(int& r);

    /** @brief  Modificadora de puntos.
        \pre <em>cierto</em>
        \post El resultado es el parámetro implícito con los anteriores más "ps" puntos.
    */ 
    void modificar_puntos(int ps);

    /** @brief Modificadora de estadísticas. 
        \pre <em>cierto</em>
        \post El resultado es el parámetro implícito (jugador) con las estadísticas actualizadas.
    */ 
    void actualizar_estadisticas(int ps, int ts, int wm, int lm, int ws, int ls, int wg, int lg); 

    //Consultora
    /** @brief Consultora de ranking. 
        \pre <em>cierto</em>
        \post Devuelve la posición en el ranking del parámetro implícito.
    */
    int consultar_ranking();

    /** @brief Consultora de puntos. 
        \pre <em>cierto</em>
        \post Devuelve el número de puntos del parámetro implícito.
    */
    int consultar_puntos();

    //Escritura
    /** @brief Operación de escritura. 
        \pre <em>cierto</em>
        \post Escribe el nombre, la posición en el ranking, los puntos y las estadísticas del parámetro
        implicito por el canal de salida.
    */ 
    void imprimir_jugador(); 
};
#endif