/*
 * Problema3.cpp
 *
 *  Created on: 21/10/2017
 *      Author: Will
 */

#include <iostream>
#include "Problema3.h"
class Problema3{
public:
	int main3(){
		Lista LM;
		Lista l1;
		Lista l2;
		int d;
		cout << "Problema 3" << endl;
		/**
		 * Se agregan y ordenan los elementos de la lista 1
		 */
		l1.addFirst(2);
		l1.addLast(9);
		l1.addLast(1);
		l1.addLast(5);
		l1.addLast(3);
		l1.ordenar();
		/**
		 * Se agregan y ordenan los elemtnos de la lista 2
		 */
		l2.addFirst(10);
		l2.addLast(20);
		l2.addLast(17);
		l2.addLast(9);
		l2.addLast(13);
		l2.ordenar();
		LM = mezclar(l1, l2);
		LM.ordenar();
		d = LM.removeFirst();
		while(d != 0){
			cout << d << endl;
			d = LM.removeFirst();
		}
		return 0;
	}
	/**
	 * Funcion lista que mezcla 2 listas enlazadas simples
	 */
	Lista mezclar(Lista L1, Lista L2){
		Lista L;
		int t = L2.removeFirst();
		while(t != 0){
			L1.addLast(t);
			t = L2.removeFirst();
		}
		L = L1;
		return L;
	}
};


