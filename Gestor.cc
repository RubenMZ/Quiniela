#include "Gestor.h"
#include "Partido.h"
#include <fstream>
#include <string>
#include <iostream>
#include <cstdlib>
#include <list>

using namespace std;

		Gestor::Gestor(){

			//...
		}


/*METODOS*/
		
		

		list<string> Gestor::equiposALista(){

			list<string> listaEquipos;
			fstream file;
			char line[500];

			file.open(getFicheroEquipos().c_str(), ios::in);

			if(file.is_open()){

				while(file.getline(line, 500, '\n')){

					listaEquipos.push_back(line);
				}

				file.close();

			}else{
				cout<<"ERROR. El fichero "<<getFicheroEquipos()<<" no puede abrirse"<<endl<<endl;
				exit(-1);
			}

			return(listaEquipos);
		}


		bool Gestor::partidosAFichero( list<Partido> lp){

			fstream file;
			list<Partido>::iterator i;
			i=lp.begin();

			file.open(getFicheroRegistro().c_str(), ios::out);

			if(file.is_open()){

				file<<endl<<"**************** JORNADA X *******************"<<endl;
				file<<"**********************************************"<<endl;
				file<<"Local\tGL - GV\tVisitante\tResultado"<<endl;
				file<<"----------------------------------------------"<<endl;


				while(i!=lp.end()){
					file<<i->getEquipoLocal()<<"\t"<<i->getResultadoLocal()<<" - "<<i->getResultadoVisitante()<<"\t"<<i->getEquipoVisitante()<<"\t"<<i->getResultado()<<endl;
					i++;
				}

				file.close();
				return(true);

			}else{
				cout<<"ERROR. El fichero "<<getFicheroRegistro()<<" no puede abrirse"<<endl<<endl;
				return(false);
			}
		}