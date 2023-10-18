/** @file Torneo.hh
    @brief Especificación de la clase Torneo 
*/

#ifndef _TORNEO_HH_
#define _TORNEO_HH_
#include "Categorias.hh"
#include "Cjt_jugadores.hh"
#include "BinTree.hh"
#ifndef NO_DIAGRAM
#include <iostream>
#include<vector>
#include <string>
using namespace std;
#endif

/** @class Torneo
    @brief Representa un Torneo
*/

class Torneo {
private:
    string nombre_categoria;
    string nombre_torneo;
    int categoria;
    BinTree<int> emp;

    struct jugador_torneo {
        string nombre;
        int ranking = 0; 
        int puntos = 0;

        int partidos_ganados = 0; 
        int partidos_perdidos = 0; 
        int sets_ganados = 0; 
        int sets_perdidos = 0; 
        int juegos_ganados = 0; 
        int juegos_perdidos = 0; 

        bool aparecido = false;
    };
    vector<jugador_torneo> jugadores_torneo;
    vector<pair<string,int>> puntos_anteriores;

public:
    //Constructoras

    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar un Torneo.
        \pre <em>cierto</em>
        \post El resultado es un Torneo sin nombre ni categorías.
    */ 
    Torneo(); 

    /** @brief Creadora de Torneo. 
        \pre <em>cierto</em>
        \post El resultado es un Torneo con nombre t y categoría c.
    */ 
    Torneo(string& t, int& c);

    //Modificadoras

    /** @brief Actualiza las estadísticas de los jugadores del torneo.
        \pre <em>cierto</em>
        \post El resultado es el map "jugadores" donde los jugadores participantes en el torneo tienen las 
        //estadísticas actualizadas.
    */
    void actualizar_estadisticas_jugadores(Cjt_jugadores& jugadores);

    /** @brief Restadora de puntos.
        \pre Comando de baja de torneo o inicialización de un torneo que ya ha sido jugado.
        \post El resultado es el map "jugadores" donde a los jugadores participantes en el torneo se les
        //han restado los puntos que obtuvieron.
    */
    void restar_puntos(Cjt_jugadores& jugadores);

    void eliminar_jugador(string& p);

    /** @brief Modificadora de nombre de categoría.
        \pre <em>cierto</em>
        \post El atributo "nombre_categoría" del parámetro implícito es ahora el parámetro "c".
    */
    void modificar_nom_cat(string& c);

    //Otros

    /** @brief Inicialización de un Torneo. 
        \pre El parámetro implícito no está inicializado.
        \post Escribe el cuadro de emparejamientos de los jugadores inscritos en el parámetro implícito
        por el canal de salida.
    */ 
    void iniciar_torneo(int& n, Cjt_jugadores& jugadores);

    /** @brief Finalizadora de Torneo. 
        \pre El parámetro implícito está inicializado.
        \post Escribe el cuadro oficial de resultado, los puntos para el ranking ganados 
        por cada uno de los jugadores participantes en el parámetro implícito por el canal de salida. 
        Actualiza el ranking y las estadísticas de los jugadores.
    */ 
    void finalizar_torneo(Cjt_jugadores& jugadores, Categorias& cat);

    /** @brief Creadora del BinTree de emparejamientos.
        \pre <em>cierto</em>
        \post Se ha construido un árbol de ints (Árbol de emparejamientos).
    */
    void create_bintree(BinTree<int>& emp, int m, const int n, int nodo_anterior);

    /** @brief Escribe el árbol de emparejamientos.
        \pre <em>cierto</em>
        \post Escribe los emparejamientos del torneo por el canal de salida.
    */
    void imprimir_bintree(const BinTree<int>& emp, Cjt_jugadores& jugadores, vector<jugador_torneo>& jugadores_torneo);

    /** @brief Crea el árbol de resultados.
        \pre <em>cierto</em>
        \post Se ha construido un árbol de strings (Árbol de resultados).
    */
    void create_bintree_final(BinTree<string>& fin);

    /** @brief Analizadora de partido.
        \pre <em>cierto</em>
        \post Devuelve el ganador del partido entre a y b, modifica las estadísticas del struct "jugador_torneo"
        // de a y b y calcula los puntos de los dos jugadores.
    */
    int analizar_partido(string partido, int a, int b, Categorias& cat, int nivel);

    /** @brief Crea el BinTree del torneo.
        \pre <em>cierto</em>
        \post Se ha construido un árbol de pair<pair<int,int>,string> con los árboles de 
        //emparejamientos y el de resultados.
    */
    void analizar_torneo(const BinTree<string>& fin, const BinTree<int>& emp, BinTree<pair<pair<int,int>,string>>& res, int& ganador, Categorias& cat, int nivel);

    /** @brief Escribe el árbol del torneo.
        \pre <em>cierto</em>
        \post Escribe el árbol de emparejamientos en preorden por el canal de salida. También escribe los puntos
        //que han conseguido los jugadores participantes.
    */
    void imprimir_bintree_final(const BinTree<pair<pair<int,int>,string>>& res);

    /** @brief Consultora de categoría.
        \pre <em>cierto</em>
        \post Devuelve la categoría a la que pertenece el parámetro implícito.
    */
    int consultar_categoria();

    //Escritura

    /** @brief Operación de escritura. 
        \pre <em>cierto</em>
        \post Escribe el nombre y la categoría del parámetro implícito por el canal de salida.
    */ 
    void imprimir_torneo(); //se imprimen los datos del torneo
};
#endif









/*void Torneo::create_bintree(BinTree<int>& emp, int n_nodos, const int n_jugadores, int ant) {
    int num;
    num = 1 + n_nodos - ant;

    if (num <= n_jugadores) {
        BinTree<int> l;
        create_bintree(l, (n_nodos*2), n_jugadores, ant);

        BinTree<int> r;
        create_bintree(r, (n_nodos*2), n_jugadores, num); 

        emp = BinTree<int>(ant, l, r);
    }
    else emp = BinTree<int>(ant);
}*/