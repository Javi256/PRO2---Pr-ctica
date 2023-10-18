/** @file Cjt_jugadores.hh
    @brief Especificación de la clase Cjt_jugadores 
*/

#ifndef _CJT_JUGADORES_HH_
#define _CJT_JUGADORES_HH_
#include "Jugador.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
#endif

/** @class Cjt_jugadores
    @brief Representa un Conjunto de Jugadores
*/

class Cjt_jugadores {
private:
    struct Jugador_ran{
        string nombre;
        int puntos = 0;
        int pos_ant;
    };
        vector<Jugador_ran> ranking;
        map<string, Jugador> cjt_jugadores;

public:
    
    //Constructoras
    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar un conjunto de jugadores.
        \pre <em>cierto</em>
        \post El resultado es un conjunto de jugadores sin nombre ni estadísticas definidas.
    */
    Cjt_jugadores();

    /** @brief Creadora de conjunto de jugadores. 
        \pre <em>cierto</em>
        \post El resultado es un conjunto de num_p jugadores con nombre y sin estadísticas definidas.
    */ 
    Cjt_jugadores(int& num_p); 

    //Consultoras

    /** @brief Operación de consulta. 
        \pre <em>cierto</em>
        \post El resultado es un jugador con identificador p perteneciente al parametro implícito.
    */
    Jugador consultar_jugador(string& p);

    //Doxygen
    string consultar_nombre_jugador(int& n);

    /** @brief Operación de consulta de existencia. 
        \pre <em>cierto</em>
        \post El resultado indica si el parámetro está en el conjunto de jugadores (perametro implícito).
    */
    bool existe_jugador(string& p);

    //Modificadoras

    /** @brief Añade un jugador al conjunto. 
        \pre No existe el jugador en el parámetro implícito.
        \post El parámetro implícito contiene los jugadores iniciales más el jugador nuevo.
    */
    void nuevo_jugador(string& p);

    /** @brief Elimina un jugador del conjunto. 
        \pre Existe el jugador en el parámetro implícito
        \post El parámetro implícito contiene los jugadores iniciales menos el jugador nuevo,
         el ranking queda actualizado.
    */
    void baja_jugador(string& p);

    static bool comp(const Jugador_ran& a, const Jugador_ran& b);

    /** @brief Actualiza el ranking. 
        \pre <em>cierto</em>
        \post El parámetro implícito tiene el ranking de jugadores actualizado.
    */
    void actualizar_ranking();

    /** @brief Modifica un jugador del conjunto. 
        \pre Existe el jugador en el parámetro implícito.
        \post El parámetro implícito contiene los jugadores iniciales y el jugador 
        pasado por parámetro está modificado.
    */
    void modificar_jugador(string& p, Jugador& jugador);

    //Escritura

    /** @brief Operación de escritura del conjunto de jugadores. 
        \pre <em>cierto</em>
        \post Escribe por orden creciente de identificador (nombre del jugador) el nombre, 
        la posición en el ranking, los puntos y las estadísticas de todos los jugadores del 
        conjunto (parámetro implícito).
    */
    void listar_jugadores(); 

    /** @brief Operación de escritura del numero de jugadores. 
        \pre <em>cierto</em>
        \post Escribe el nombre de jugadores del conjunto (parámetro implícito) por el canal de salida.
    */
    int numero_jugadores();

    /** @brief Operación de escritura del ranking. 
        \pre <em>cierto</em>
        \post Escribe en orden creciente la posición, el nombre y los puntos de cada jugador 
        del conjunto (parámetro implícito) por el canal de salida.
    */
    void listar_ranking();

    //función ordenar ranking
};
#endif