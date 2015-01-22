#include "Quiniela.h"
#include "Gestor.h"
#include "Interfaz.h"
#include "Partido.h"
#include <iostream>

using namespace std;



int main(){


	Quiniela partida;

	partida.cargarListaPartidos();

	partida.mostrarEquipos();

	partida.asignarPartidos();

	if(!partida.marcarApuestas()){
		cout<<"ERROR. La lista de partidos esta vacia"<<endl;
	}

	partida.simularPartidos();

	partida.mostrarPartidos();

	partida.asignarPremios();

	if(partida.registrarResultados()){
		cout<<"Se registraron los resultados"<<endl;
	}else{
		cout<<"ERROR. Al registrar resultados"<<endl;
	}



	return 0;
}