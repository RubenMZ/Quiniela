#include "Partido.h"
#include <string>

using namespace std;

	Partido::Partido(string local, int resLocal, int resVisitante, string visitante, string resultado){

		setEquipoLocal(local);
		setEquipoVisitante(visitante);
		setResultadoLocal(resLocal);
		setResultadoVisitante(resVisitante);
		setResultado(resultado);

	}