/*
 * Problema5.cpp
 *
 *  Created on: 21/10/2017
 *      Author: Will
 */

#include <iostream>
#include "Problema5.h"
#include "Persona.h"
#include "Premio.h"

class Problema5{
public:
	int main5(){
		//Listas del problema
		ListaPersonas Personas;
		ListaPremios Premios;
		ListaPersonas Ganadores;
		int cont = 6;
		//personas almacenadas en lista Personas
		persona p1;
		p1.nombreP = "Jose";
		persona p2;
		p2.nombreP = "Gary";
		persona p3;
		p3.nombreP = "Farfan";
		persona p4;
		p4.nombreP = "Williams";
		persona p5;
		p5.nombreP = "Sergio";
		persona p6;
		p6.nombreP = "Marcela";
		premio pi1;
		//premios almacenados en lista premios
		pi1.nombre = "Primer Lugar";
		premio pi2;
		pi2.nombre = "Segundo Lugar";
		premio pi3;
		pi3.nombre = "Tercero Lugar";
		Premios.addFirst(pi1);
		Premios.addLast(pi2);
		Premios.addLast(pi3);
		Personas.addFirst(p1);
		Personas.addLast(p2);
		Personas.addLast(p3);
		Personas.addLast(p4);
		Personas.addLast(p5);
		Personas.addLast(p6);
		int in = 1;
		while(in != 0){
			cout << "Ingrese el numero de la operacion para realizarala y 0 para terminar" << endl;
			cout << "2 para sortear un premio" << endl;
			cout << "3 para sortear todos los premios" << endl;
			cout << "4 para ver todas las listas (solo se puede hacer una vez)" << endl;
			cin >> in;
			if(in == 2){
				//Saca un premio de la lista, lo asigna a una presona random y agrega esa persona a la lista de ganadores
				int random = rand() % (cont + 1);
				persona pt;
				pt = Personas.removeData(random);
				cont--;
				pt.p = Premios.removeFirst();
				Ganadores.addLast(pt);
			}
			if(in == 3){
				//Saca un premio de la lista, lo asigna a una presona random y agrega esa persona a la lista de ganadores hasta que se acaben los premios
				while(Premios.sizeL() != 0){
					int random = rand() % (cont + 1);
					persona pt;
					pt = Personas.removeData(random);
					cont--;
					pt.p = Premios.removeFirst();
					Ganadores.addLast(pt);
				}
			}
			if(in == 4){
				//Muestra las personas almacenadas
				cout << "El listado de personas sin recibir premios es:" << endl;
				while(Personas.sizeL() != 0){
					string nom = Personas.removeFirst();
					cout << nom << endl;
				}
				//Muestra los premios almacenados
				cout << "El listado de Premios es :" << endl;
				while(Premios.sizeL() != 0){
					premio p = Premios.removeFirst();
					cout << p.nombre << endl;
				}
				//Muestra los ganadores alamacenados
				cout << "El listado de ganadores es :" << endl;
				while(Ganadores.sizeL() != 0){
					string nom = Ganadores.removeFirst();
					cout << nom << endl;
				}
			}
		}
		return 0;
	}
};


