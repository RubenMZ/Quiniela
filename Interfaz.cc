#include <string>
#include <iostream>
#include <list>
#include <algorithm> 
#include "Partido.h"
#include "Interfaz.h"


using namespace std;

		Interfaz::Interfaz(){


		}


		list<string> Interfaz::pedirApuestasPartidos(const list<Partido> &lp){

			list<string> apuestasAux;
			list<Partido>::iterator i;
			//....
		}

		void Interfaz::visualizarPartido( Partido &p){
				cout<<p.getEquipoLocal()<<"\t"<<p.getResultadoLocal()<<" - "<<p.getResultadoVisitante()<<"\t"<<p.getEquipoVisitante()<<"\t"<<p.getResultado()<<endl;
		}



		bool Interfaz::mostrarEquipos(list<string> listaEquipos){
			list<string>::iterator i;
			int j=1;

			if(ordenarEquipos(listaEquipos)){
				cout<<"Tu lista de equipos es: "<<endl;

				for(i=listaEquipos.begin(); i!=listaEquipos.end(); i++){
					cout<<j<<" ) - "<<(*i)<<endl;
					j++;
				}
				return(true);
			}else{
				return (false);
			}
		}

		bool Interfaz::ordenarEquipos(list<string> &listaEquipos){

			if(!listaEquipos.empty()){
				listaEquipos.sort();
				return(true);
			}else{
				return(false);
			}
		}



