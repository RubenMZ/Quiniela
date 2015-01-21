#include "Quiniela.h"
#include "Gestor.h"
#include "Interfaz.h"
#include "Partido.h"

using namespace std;



int main(){


	Quiniela partida;

	partida.cargarListaPartidos();

	partida.mostrarEquipos();

	return 0;
}