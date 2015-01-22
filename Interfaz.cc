#include <string>
#include <iostream>
#include <list>
#include <algorithm> 
#include "Partido.h"
#include "Interfaz.h"


using namespace std;

		Interfaz::Interfaz(){


		}


		list<string> Interfaz::pedirApuestasPartidos(list<Partido> &lp){

			list<string> apuestasAux;
			list<Partido>::iterator i;
			string apuesta;
			
			cout<<"*Introduce las apuestas:"<<endl<<"1)Gana local"<<endl<<"x)Empate"<<endl<<"2)Gana visitante"<<endl;

			for(i=lp.begin(); i!=lp.end(); i++){
				do{
				cout<<i->getEquipoLocal()<<" - "<<i->getEquipoVisitante()<<endl;
				cout<<"Apuesta: ";
				getline(cin, apuesta);
				apuestasAux.push_back(apuesta);
				}while(apuesta!="1"&&apuesta!="x"&&apuesta!="2");
			}
			return(apuestasAux);
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



