#include "Quiniela.h"
#include "Gestor.h"
#include "Interfaz.h"
#include <string>
#include <list>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <cstring>


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

			Gestor gestorAux;

			gestorAux = getGestorBD();
			return( gestorAux.partidosAFichero(getListaPartidos()) );
		}


		/*INTERFAZ*/
		//bool Quiniela::marcarApuestas();
		bool Quiniela::mostrarPartidos(){

			list<Partido>::iterator ite;
			Interfaz i;
			i = getInterfaz();
			list<Partido> listaPartidos = getListaPartidos();

			if(!listaPartidos.empty()){

				cout<<"********************* JORNADA X ************************"<<endl;
				cout<<"********************************************************"<<endl;
				cout<<"Local\t\tGL - GV\tVisitante\tResultado"<<endl;
				cout<<"--------------------------------------------------------"<<endl;

				for(ite=listaPartidos.begin() ; ite!=listaPartidos.end() ; ite++){
					i.visualizarPartido(*ite);
				}
				return(true);
			}else{

				return(false);
			}
		}

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

		bool Quiniela::asignarPartidos(){

			list<string> listaEquipos = getEquipos();
			list<string>::iterator iEquipos;
			iEquipos = listaEquipos.begin();
			list<string>::iterator iAux;
			list<Partido> listaPartidos;
			Partido partido;
			int equipos = 30;
			int vector[30];
			int kk=0;
			int random, encontrado, i;
			srand(time(NULL));

			for(i=0; i<30; i++){
				vector[i]=30;
			}

			while(kk<30){

				iAux = iEquipos;
				do{
					random = rand()%equipos;
					encontrado = 0;
					for( i =0 ; i<kk; i++){
						
						if(random==vector[i]){
							encontrado=1;
							cout<<"paso2"<<endl;
						}
					}
					cout<<"paso 1 ->"<<kk<<"-"<<i<<" random "<<random<<endl;
				}while(encontrado==1);
				vector[kk]=random;
				advance(iAux,random);
				partido.setEquipoLocal(*iAux);
				kk++;

				iAux = iEquipos;
				do{
					random = rand()%equipos;
					encontrado = 0;
					for( i =0 ; i<kk; i++){
						if(random==vector[i]){
							encontrado=1;
						}
					}
					cout<<"paso 3 ->"<<kk<<"-"<<i<<" random "<<random<<endl;
				}while(encontrado==1);
				vector[kk]=random;
				advance(iAux,random);
				partido.setEquipoVisitante(*iAux);
				kk++;

				listaPartidos.push_back(partido);
			}

			setListaPartidos(listaPartidos);

			return (true);
		}