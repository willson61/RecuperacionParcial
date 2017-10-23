/*
 * Problema2.cpp
 *
 *  Created on: 21/10/2017
 *      Author: Will
 */

#include <iostream>
#include "Problema2.h"
class Problema2{
public:
	int main2(){
		Pila m;
		int c;
		cout << "Problema2" << endl;
		//Se agregan los datos a la pila
		m.push(10);
		m.push(20);
		m.push(30);
		m.push(40);
		m.push(50);
		m = remplazar(m, 100, 30);
		c = m.pop();
		while(c != 0){
			cout << c << endl;
			c = m.pop();
		}
		return 0;
	}
	/**
	 * Funcion que retorna una pila con el dato nuevo remplazado por el viejo
	 */
	Pila remplazar(Pila p, int nuevo, int viejo){
		Pila temp;
		int t = p.pop();
		while(t != viejo){
			temp.push(t);
			t = p.pop();
		}
		if(t == viejo){
			p.push(nuevo);
			t = temp.pop();
			while(t != 0){
				p.push(t);
				t = temp.pop();
			}
		}
		return p;
	}
};

