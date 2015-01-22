#ifndef GESTOR_H
#define GESTOR_H


#include <string>
#include "Partido.h"
#include <list>

using namespace std;

class Gestor{
	
	private:
		string ficheroEquipos_;
		string ficheroRegistro_;

	public:

		Gestor();

		/*MODIFICADORES*/

		inline void setFicheroEquipos(const string &f){ficheroEquipos_=f;};
		inline void setFicheroRegistro(const string &f){ficheroRegistro_=f;};

		/*OBSERVADORES*/
		inline string getFicheroEquipos(){return(ficheroEquipos_);};
		inline string getFicheroRegistro(){return(ficheroRegistro_);};

		/*METODOS*/
		list<string> equiposALista();
		bool partidosAFichero( list<Partido> lp);
		



};

#endif