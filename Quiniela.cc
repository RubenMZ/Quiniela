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
		bool Quiniela::marcarApuestas(){
			list<Partido> lPartidos = getListaPartidos();
			list<string> apuestas;
			Interfaz i = getInterfaz();

			if(lPartidos.empty()){
				return(false);
			}else{
				apuestas = i.pedirApuestasPartidos(lPartidos);
				setApuestas(apuestas);
				return(true);
			}
		}

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
		bool Quiniela::simularPartidos(){
			int vector[40]={0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,2,3,3,3,3,3,4,4,5,5,6};
			srand(time(NULL));
			list<Partido> listaPartidos = getListaPartidos();
			list<Partido>::iterator i;
		
			if(listaPartidos.empty()){
				return(false);
			}

			for(i=listaPartidos.begin(); i!=listaPartidos.end(); i++){

				i->setResultadoLocal(vector[rand()%40]);
				i->setResultadoVisitante(vector[rand()%40]);
				i->setResultado( calcularResultado(i->getResultadoLocal(),i->getResultadoVisitante()) );
			}

			setListaPartidos(listaPartidos);
			return(true);
		}

		string Quiniela::calcularResultado(const int &local, const int &visitante){

			if(local>visitante){
				return("1");
			}else{
				if(local<visitante){
					return("2");
				}else{
					return("x");
				}
			}

		}


		bool Quiniela::asignarPremios(){
			list<Partido> partidos = getListaPartidos();
			list<string> apuestas = getApuestas();
			list<string>::iterator i;
			i = apuestas.begin();
			list<Partido>::iterator j;
			int contador = 0;

			if(partidos.empty()){
				return false;
			}

			for(j=partidos.begin(); j!=partidos.end() ; j++){
				if((*i)==j->getResultado()){
					contador++;
				}
				i++;
			}

			cout<<"Has acertado "<<contador<<" PARTIDOS"<<endl;

			return true;
		}

		bool Quiniela::asignarPartidos(){

			list<string> listaEquipos = getEquipos();
			list<string>::iterator iEquipos;
			iEquipos = listaEquipos.begin();
			list<string>::iterator iAux;
			list<Partido> listaPartidos;
			Partido partido;
			int equipos = 30;
			int *vector;
			vector = new int[30];
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
						}
					}
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
				}while(encontrado==1);

				vector[kk]=random;
				advance(iAux,random);
				partido.setEquipoVisitante(*iAux);
				kk++;

				listaPartidos.push_back(partido);
			}

			setListaPartidos(listaPartidos);
			delete [] vector;
			return (true);
		}