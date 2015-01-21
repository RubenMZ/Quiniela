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
		void visualizarPartido(const Partido &p);
		bool mostrarEquipos(list<string> listaEquipos);
		bool ordenarEquipos(list<string> &listaEquipos);
		inline bool condicion(string e1, string e2){return(e1>e2);};

};

#endif