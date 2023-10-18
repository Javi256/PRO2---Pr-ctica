#include "Torneo.hh"

Torneo::Torneo() {

}

Torneo::Torneo(string& t, int& c) {
    nombre_torneo = t;
    categoria = c;
}

void Torneo::actualizar_estadisticas_jugadores(Cjt_jugadores& jugadores) {
    for (int i = 0; i < jugadores_torneo.size(); i++) {
        string nombre = jugadores_torneo[i].nombre;
        Jugador jugador = jugadores.consultar_jugador(nombre);
        jugador_torneo jug = jugadores_torneo[i];
        jugador.actualizar_estadisticas(jug.puntos, 1, jug.partidos_ganados,jug.partidos_perdidos, jug.sets_ganados, jug.sets_perdidos, jug.juegos_ganados, jug.juegos_perdidos);
        jugadores.modificar_jugador(nombre, jugador);
    }
}

void Torneo::restar_puntos(Cjt_jugadores& jugadores){
    for (int i = 0; i < jugadores_torneo.size(); i++) {
        string nombre = jugadores_torneo[i].nombre;
        Jugador jugador = jugadores.consultar_jugador(nombre);
        jugador.modificar_puntos(-jugadores_torneo[i].puntos);
        jugadores.modificar_jugador(nombre, jugador);
    }
}

void Torneo::eliminar_jugador(string& p) {
    bool found = false;
    int i = 0;

    while (not found and i < jugadores_torneo.size()) {
        if (jugadores_torneo[i].nombre == p) {
            found = true;
            jugadores_torneo[i] = jugadores_torneo[jugadores_torneo.size()-1];
            jugadores_torneo.pop_back();
        }
        ++i;
    }
}

void Torneo::modificar_nom_cat(string& ct) {
    nombre_categoria = ct;
}

void Torneo::iniciar_torneo(int& n,  Cjt_jugadores& jugadores) {
    //vector<pair<string,int>> puntos_anteriores;
    if (jugadores_torneo.size() > 0) {
        puntos_anteriores = vector<pair<string,int>> (jugadores_torneo.size());
        for (int i = 0; i < jugadores_torneo.size(); i++) {
        string nombre = jugadores_torneo[i].nombre;
        int puntos = jugadores_torneo[i].puntos;
        puntos_anteriores[i] = make_pair(nombre, puntos);
        }
    }
    
    create_bintree(emp, 2, n, 1);
    
    jugadores_torneo = vector<jugador_torneo>(n);
    
    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        jugadores_torneo[i].ranking = x;
    }

    vector<int> resultados;

    imprimir_bintree(emp, jugadores, jugadores_torneo);
    cout << endl;

    /*if (puntos_anteriores.size() > 0) {
        for (int i = 0; i < puntos_anteriores.size(); i++) {
        string nombre = puntos_anteriores[i].first;
        Jugador jugador = jugadores.consultar_jugador(nombre);
        jugador.modificar_puntos(-puntos_anteriores[i].second);
        jugadores.modificar_jugador(nombre, jugador);
        }
    }*/
}

void Torneo::finalizar_torneo(Cjt_jugadores& jugadores, Categorias& cat) {
    for (int i = 0; i < puntos_anteriores.size(); i++) {
        string nombre = puntos_anteriores[i].first;
        Jugador jugador = jugadores.consultar_jugador(nombre);
        jugador.modificar_puntos(-puntos_anteriores[i].second);
        jugadores.modificar_jugador(nombre, jugador);
    }
    
    BinTree<string> fin;
    BinTree<pair<pair<int,int>,string>> res;
    create_bintree_final(fin);

    int ganador;
    analizar_torneo(fin, emp, res, ganador, cat, 1);
    imprimir_bintree_final(res);

    cout << endl;
    for (int i = 0; i < jugadores_torneo.size(); ++i) {
        int pun = jugadores_torneo[i].puntos;
        if (pun != 0) {
            cout << i+1 << "." << jugadores_torneo[i].nombre << " " << pun << endl;
        }
    }

    actualizar_estadisticas_jugadores(jugadores);

    jugadores.actualizar_ranking();
}

void Torneo::create_bintree(BinTree<int>& emp, int m, const int n, int nodo_anterior) {
    int num;
    num = m + 1 - nodo_anterior;

    BinTree<int> l;
    BinTree<int> r;

    if (num <= n) {
        create_bintree(l, m*2, n, nodo_anterior);
        create_bintree(r, m*2, n, num); 
    }
    emp = BinTree<int>(nodo_anterior, l, r);
}

void Torneo::imprimir_bintree(const BinTree<int>& emp, Cjt_jugadores& jugadores, vector<jugador_torneo>& jugadores_torneo) {
    if (not emp.empty()) {
        int x = emp.value();
        if (not emp.left().empty()) cout << "(";
        imprimir_bintree(emp.left(), jugadores, jugadores_torneo); 
        if (not jugadores_torneo[x-1].aparecido) {
            jugadores_torneo[x-1].aparecido = true;
            string nombre = jugadores.consultar_nombre_jugador(jugadores_torneo[x-1].ranking);
            jugadores_torneo[x-1].nombre = nombre;
            cout << x << "."  << nombre;
        } 
        if (not emp.right().empty())cout << " ";
        imprimir_bintree(emp.right(), jugadores, jugadores_torneo);
        if (not emp.right().empty()) cout << ")";
    }
}

void Torneo::create_bintree_final(BinTree<string>& fin) {
    string resultados;
    cin >> resultados;

    if (resultados != "0") {
        BinTree<string> l;
        BinTree<string> r;

        create_bintree_final(l);
        create_bintree_final(r); 

        fin = BinTree<string>(resultados, l, r);
    }
}

int Torneo::analizar_partido(string partido, int a, int b, Categorias& cat, int nivel) {
    if (partido.length() > 3) {
        int juegos_a_ganados = 0;
        int juegos_b_ganados = 0;
        int juegos_a_perdidos = 0;
        int juegos_b_perdidos = 0;
        int sets_a_ganados = 0;
        int sets_b_ganados = 0;
        int sets_a_perdidos = 0;
        int sets_b_perdidos = 0;

        int i = 0;
        int j = 2;

        while (j < partido.length()) {
            int num_a = partido[i]-'0';
            int num_b = partido[j]-'0';
            juegos_a_ganados += num_a;
            juegos_b_ganados += num_b;
            juegos_a_perdidos += num_b;
            juegos_b_perdidos += num_a;

            if (num_a > num_b) {
                ++sets_a_ganados;
                ++sets_b_perdidos;
            }
            else {
                ++sets_b_ganados;
                ++sets_a_perdidos;
            }

            i += 4;
            j += 4;
        }

        jugadores_torneo[a-1].sets_ganados += sets_a_ganados;
        jugadores_torneo[a-1].sets_perdidos += sets_a_perdidos;
        jugadores_torneo[a-1].juegos_ganados += juegos_a_ganados;
        jugadores_torneo[a-1].juegos_perdidos += juegos_a_perdidos;

        jugadores_torneo[b-1].sets_ganados += sets_b_ganados;
        jugadores_torneo[b-1].sets_perdidos += sets_b_perdidos;
        jugadores_torneo[b-1].juegos_ganados += juegos_b_ganados;
        jugadores_torneo[b-1].juegos_perdidos += juegos_b_perdidos;

        if (sets_a_ganados > sets_b_ganados) {
            ++jugadores_torneo[a-1].partidos_ganados;
            ++jugadores_torneo[b-1].partidos_perdidos;

            int puntos_a = cat.consultar_puntos(categoria, nivel);
            int puntos_b = cat.consultar_puntos(categoria, nivel+1);
            jugadores_torneo[a-1].puntos = puntos_a;
            jugadores_torneo[b-1].puntos = puntos_b;

            return a;
        }

        else {
            ++jugadores_torneo[b-1].partidos_ganados;
            ++jugadores_torneo[a-1].partidos_perdidos;

            int puntos_a = cat.consultar_puntos(categoria, nivel+1);
            int puntos_b = cat.consultar_puntos(categoria, nivel);
            jugadores_torneo[a-1].puntos = puntos_a;
            jugadores_torneo[b-1].puntos = puntos_b;

            return b;
        }
    }

    else if (partido.length() == 3) {
        if (partido[0] == '1') {
            ++jugadores_torneo[a-1].partidos_ganados;
            ++jugadores_torneo[b-1].partidos_perdidos;

            int puntos_a = cat.consultar_puntos(categoria, nivel);
            int puntos_b = cat.consultar_puntos(categoria, nivel+1);
            jugadores_torneo[a-1].puntos = puntos_a;
            jugadores_torneo[b-1].puntos = puntos_b;

            return a;
        } 
        else {
            ++jugadores_torneo[b-1].partidos_ganados;
            ++jugadores_torneo[a-1].partidos_perdidos;

            int puntos_a = cat.consultar_puntos(categoria, nivel+1);
            int puntos_b = cat.consultar_puntos(categoria, nivel);
            jugadores_torneo[a-1].puntos = puntos_a;
            jugadores_torneo[b-1].puntos = puntos_b;

            return b;
        }
    }  

    else return 0;
}

void Torneo::analizar_torneo(const BinTree<string>& fin, const BinTree<int>& emp, BinTree<pair<pair<int,int>,string>>& res, int& ganador, Categorias& cat, int nivel) {
    int ganador1;
    int ganador2;

    if (fin.empty()) {
        ganador = emp.value();
        res = BinTree<pair<pair<int,int>,string>> ();
    }

    else if (not fin.empty()) {

        pair<pair<int,int>,string> partido;
        BinTree<pair<pair<int,int>,string> > res1;
        BinTree<pair<pair<int,int>,string> > res2;
        
        analizar_torneo(fin.left(), emp.left(), res1, ganador1, cat, nivel+1);
        analizar_torneo(fin.right(), emp.right(), res2, ganador2, cat, nivel+1);

        partido = make_pair(make_pair(ganador1, ganador2), fin.value());
        
        res = BinTree<pair<pair<int,int>,string>> (partido, res1, res2);
        ganador = analizar_partido(fin.value(), ganador1, ganador2, cat, nivel);
    }
}

void Torneo::imprimir_bintree_final(const BinTree<pair<pair<int,int>,string>>& res) {
    if (not res.empty()) {
        int a = res.value().first.first;
        int b = res.value().first.second;
        string resultado = res.value().second;
        if (not emp.left().empty()) cout << "(";
        cout << a << "." << jugadores_torneo[a-1].nombre << " vs "<< b << "." << jugadores_torneo[b-1].nombre << " " << resultado;
        imprimir_bintree_final(res.left());
        imprimir_bintree_final(res.right());
        if (not emp.right().empty()) cout << ")";
    }
}

int Torneo::consultar_categoria() {
    return categoria;
}

void Torneo::imprimir_torneo() {
    cout << nombre_torneo << " " << nombre_categoria << endl;
}