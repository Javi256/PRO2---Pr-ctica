/** @file Cjt_torneos.hh
    @brief Especificación de la clase Cjt_torneos 
*/

#ifndef _CJT_TORNEOS_HH_
#define _CJT_TORNEOS_HH_
#include "Torneo.hh"
#ifndef NO_DIAGRAM
#include <iostream>
using namespace std;
#endif

/** @class Cjt_torneos
    @brief Representa un Conjunto de Torneos
*/

class Cjt_torneos {
private:
    map<string, Torneo> cjt_torneos;

public:
    //Constructoras
    /** @brief Creadora por defecto. 
        Se ejecuta automáticamente al declarar un conjunto de torneos.
        \pre <em>cierto</em>
        \post El resultado es un conjunto de torneos sin nombre ni estadísticas ni categoría.
    */
    Cjt_torneos();

    /** @brief Creadora de conjunto de torneos. 
        \pre <em>cierto</em>
        \post El resultado es un conjunto de num_t torneos con nombre y categoría.
    */ 
    Cjt_torneos(int& num_t);

    //Consultoras
    /** @brief Operación de consulta. 
        \pre <em>cierto</em>
        \post El resultado es un torneo con identificador t perteneciente al parámetro implícito.
    */
    Torneo consultar_torneo(string& t); //devuelve el torneo con identificador t

    /** @brief Operación de consulta de existencia. 
        \pre <em>cierto</em>
        \post El resultado indica si el parámetro está en el conjunto de torneos (parámetro implícito).
    */
    bool existe_torneo(string& t); //true si el torneo existe 

    //Modificadoras
    /** @brief Modifica un torneo del conjunto. 
        \pre <em>cierto</em>
        \post El torneo con nombre t del parámetro implícito es substituido por el parámetro "torneo".
    */
    void modificar_torneo(string& t, Torneo& torneo); 
    
///************************************************
    void baja_jugador_torneo(string& p);

    /** @brief Añade el nombre de su categoría a todos los torneos del conjunto.
        \pre <em>cierto</em>
        \post El parámetro implícito contiene los troneos iniciales pero estos tienen el nombre de su 
        // categoría en el atríbuto "nombre_categoría".
    */
    void anadir_nom_cat(Categorias& categorias);
    
    /** @brief Añade un torneo al conjunto. 
        \pre No existe el torneo en el parámetro implícito.
        \post El parámetro implícito contiene los troneos iniciales más el torneo nuevo.
    */
    void nuevo_torneo(string& t, int& c);

    /** @brief Elimina un torneo del conjunto. 
        \pre El torneo t existe en el parámetro implícito
        \post El parámetro implícito contiene los torneos iniciales menos el troneo nuevo,
         el ranking queda actualizado si es necesario.
    */
    void baja_torneo(string& t, Cjt_jugadores& jugadores);

    //Escritura
    /** @brief Operación de escritura del conjunto de troeneos. 
        \pre <em>cierto</em>
        \post Escribe por orden creciente de identificador (nombre del torneo) el nombre 
        y la categoría de todos los troneos del conjunto (parámetro implícito).
    */
    void listar_torneos();

    /** @brief Operación de escritura del numero de torneos. 
        \pre <em>cierto</em>
        \post Escribe el nombre de torneos del conjunto (parámetro implícito) por el canal de salida.
    */
    int numero_torneos();
};
#endif