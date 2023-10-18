/** @file Categorias.hh
    @brief Especificación de la clase Categorias 
*/

#ifndef _CATEGORIAS_HH_
#define _CATEGORIAS_HH_
#ifndef NO_DIAGRAM
#include <iostream>
#include <vector>
using namespace std;
#endif

/** @class Categorias
    @brief Representa el conjunto de categorías del circuito
*/

class Categorias {
private:
    vector<string> Cjt_categorias;
    vector< vector<int> > Puntos;
    int num_C = 0;
    int num_K = 0;

public:
    //Constructoras
    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar un conjunto de jugadores.
        \pre <em>cierto</em>
        \post El resultado dos estructuras de datos sin datos.
    */
    Categorias();

    /** @brief Creadora de Categorias. 
        \pre <em>cierto</em>
        \post El resultado son dos estructuras de datos, un vector para las categorias con 
        num_c elementos y una matriz para los puntos con num_c * num_k elementos.
    */
    Categorias(int& num_c, int& num_k); 

    //Consultora
    /** @brief Operación de consulta de existencia. 
        \pre <em>cierto</em>
        \post El resultado indica si el parámetro está es una categoría (parámetro implícito).
    */
    bool existe_categoria(int& c);

    /** @brief Consultora de puntos. 
        \pre <em>cierto</em>
        \post Escribe los puntos de la categoría c en el nivel k por el canal de salida.
    */
    int consultar_puntos(int& c, const int& k);

    //Doxygen
    string consultar_categoria(int& c);

    //Escritura
     /** @brief Operación de escritura de categorias. 
        \pre <em>cierto</em>
        \post Escribe en orden creciente el nombre y la tabla de puntos por niveles de cada
        categoría del circuito (parámetro implícito) por el canal de salida.
    */
    void listar_categorias(); 
};
#endif