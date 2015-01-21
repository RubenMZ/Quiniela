#include "Quiniela.h"
#include "Gestor.h"
#include "Interfaz.h"
#include <string>
#include <list>

using namespace std;

	/*CONSTRUCTOR*/
		Quiniela::Quiniela(string fEquipos, string fRegistro){

			gestorBD_.setFicheroEquipos(fEquipos);
			gestorBD_.setFicheroRegistro(fRegistro);


		}


		/*MODIFICADORES*/
			//inline en .h

		/*OBSERVADORES*/
			//inline en .h


		/*GESTOR*/
		bool Quiniela::cargarListaPartidos(){
			
			Gestor gestorAux;

			gestorAux = getGestorBD();
			setEquipos(gestorAux.equiposALista());

			return (true);
		}

		bool Quiniela::registrarResultados(){


		}


		/*INTERFAZ*/
		//bool Quiniela::marcarApuestas();
		//bool Quiniela::mostrarPartidos();
		bool Quiniela::mostrarEquipos(){
			Interfaz i;

			i = getInterfaz();
			if(i.mostrarEquipos(getEquipos())){
				return(true);
			}else{
				return(false);
			}
		}

		/*QUINIELA*/
		//bool Quiniela::simularPartidos();
		//bool Quiniela::asignarPremios();