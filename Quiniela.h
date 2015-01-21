#ifndef QUINIELA_H
#define QUINIELA_H

#include "Partido.h"
#include "Gestor.h"
#include "Interfaz.h"
#include <string>
#include <list>

using namespace std;


class Quiniela{
	

	private: 

		list<Partido> listaPartidos_;
		Gestor gestorBD_;
		Interfaz interfaz_;
		list<string> Equipos_;
		list<string> Apuestas_;

	public:

		/*CONSTRUCTOR*/
		Quiniela(string fEquipos="Equipos.txt", string fRegistro="Requistro.txt");

		/*MODIFICADORES*/
		inline void setListaPartidos(const list <Partido> &lp){listaPartidos_=lp;};
		inline void setGestorBD(const Gestor &g){gestorBD_=g;};
		inline void setInterfaz(const Interfaz &i){interfaz_=i;};
		inline void setApuestas(const list<string> &a){Apuestas_=a;};
		inline void setEquipos(const list<string> &e){Equipos_=e;};

		/*OBSERVADORES*/
		inline list<Partido> getListaPartidos(){return(listaPartidos_);};
		inline Gestor getGestorBD(){return(gestorBD_);};
		inline Interfaz getInterfaz(){return(interfaz_);};
		inline list<string> getApuestas(){return(Apuestas_);};
		inline list<string> getEquipos(){return(Equipos_);};


		/*GESTOR*/
		bool cargarListaPartidos();
		bool registrarResultados();

		/*INTERFAZ*/
		bool marcarApuestas();
		bool mostrarPartidos();
		bool mostrarEquipos();

		/*QUINIELA*/
		bool simularPartidos();
		bool asignarPremios();

};


#endif