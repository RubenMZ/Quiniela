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

	partida.mostrarPartidos();

	partida.registrarResultados();



	return 0;
}