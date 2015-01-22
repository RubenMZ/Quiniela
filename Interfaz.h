#ifndef INTERFAZ_H
#define INTERFAZ_H


#include "Partido.h"
#include <string>
#include <list>


using namespace std;



class Interfaz{
	
	private:
		//NOTHING, THERE ARE NOT CAMPOS

	public: 

		Interfaz();
		list<string> pedirApuestasPartidos(const list<Partido> &lp);
		void visualizarPartido( Partido &p);
		bool mostrarEquipos(list<string> listaEquipos);
		bool ordenarEquipos(list<string> &listaEquipos);

};

#endif