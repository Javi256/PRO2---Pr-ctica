OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -Wextra -Werror -Wno-uninitialized -Wno-sign-compare -std=c++11
# OPCIONS = -D_GLIBCXX_DEBUG -O2 -Wall -std=c++11

program.exe: Cjt_jugadores.o Jugador.o Cjt_torneos.o Torneo.o Categorias.o program.o 
	g++ $(OPCIONS) -o program.exe Cjt_jugadores.o Jugador.o Cjt_torneos.o Torneo.o Categorias.o program.o

program.o: program.cc
	g++ $(OPCIONS) -c program.cc

Cjt_jugadores.o: Cjt_jugadores.cc Cjt_jugadores.hh
	g++ $(OPCIONS) -c Cjt_jugadores.cc

Jugador.o: Jugador.cc Jugador.hh
	g++ $(OPCIONS) -c Jugador.cc

Cjt_torneos.o: Cjt_torneos.cc Cjt_torneos.hh
	g++ $(OPCIONS) -c Cjt_torneos.cc

Torneo.o: Torneo.cc Torneo.hh
	g++ $(OPCIONS) -c Torneo.cc

Categorias.o: Categorias.cc Categorias.hh
	g++ $(OPCIONS) -c Categorias.cc

practica.tar: Makefile Cjt_jugadores.hh Cjt_jugadores.cc Cjt_torneos.hh Cjt_torneos.cc Jugador.cc Jugador.hh Torneo.hh Torneo.cc Categorias.cc Categorias.hh BinTree.hh program.cc
	tar -cvf practica.tar *.cc *.hh Makefile
	
clean: 
	rm -f *.o *.gch *.exe *.tar
