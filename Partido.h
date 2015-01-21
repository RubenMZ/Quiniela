#ifndef PARTIDO_H
#define PARTIDO_H


#include <string>

using namespace std;


class Partido{
	
	private:

		string EquipoLocal_, EquipoVisitante_;
		int ResultadoLocal_, ResultadoVisitante_;
		string Resultado_;// 1 gana local x empate 2 gana visitante

	public:

		/*CONSTRUCTOR*/
		Partido();

		/*MODIFICADORES*/
		inline void setEquipoLocal(const string &equipo){EquipoLocal_=equipo;};
		inline void setEquipoVisitante(const string &equipo){EquipoVisitante_=equipo;};
		inline void setResultadoLocal(const int &resultado){ResultadoLocal_=resultado;};
		inline void setResultadoVisitante(const int &resultado){ResultadoVisitante_=resultado;};
		inline void setResultado(const string &resultado){Resultado_=resultado;};

		/*OBSERVADORES*/
		inline string getEquipoLocal(){return(EquipoLocal_);};
		inline string getEquipoVisitante(){return(EquipoVisitante_);};
		inline int getResultadoLocal(){return(ResultadoLocal_);};
		inline int getResultadoVisitante(){return(ResultadoVisitante_);};
		inline string getResultado(){return(Resultado_);};
};

#endif