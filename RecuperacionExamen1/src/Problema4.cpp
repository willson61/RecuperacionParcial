/*
 * Problema4.cpp
 *
 *  Created on: 21/10/2017
 *      Author: Will
 */

#include <iostream>
#include "Problema4.h"
class Problema4{
public:
	int main4(){
		int cont = 0;
		int ingreso = 1;
		int val;
		int comprobante1;
		int comprobante2;
		ListaSimple lsA;
		ListaDoble ldA;
		ListaSimple lsB;
		ListaDoble ldB;
		ldA.beginDoubleLinked();
		ldB.beginDoubleLinked();
		cout << "Problema 4:" << endl;
		cout << "Ingrese el numero para agregarlo a la lista enlazada y ingrese 0 para terminar" << endl;
		while(ingreso != 0){
			if(lsA.sizeL() == 0){
				cout << "Ingrese un numero" << endl;
				cin >> val;
				if(val != 0){
					lsA.addFirst(val);
					lsB.addFirst(val);
					cont++;
				}
			}
			else{
				cout << "Ingrese un numero" << endl;
				cin >> val;
				if(val != 0){
					lsA.addLast(val);
					lsB.addLast(val);
					cont++;
				}
			}
			if(val == 0){
				ingreso = 0;
			}
		}
		cout << "Ingrese el numero para agregarlo a la lista enlazada doble y ingrese 0 para terminar" << endl;
		ingreso = 1;
		while(ingreso != 0){
			cout << "Ingrese un numero" << endl;
			cin >> val;
			if(val != 0){
				ldA.addFirstD(val);
				ldB.addFirstD(val);
			}
			if(val == 0){
				ingreso = 0;
			}
		}
		int arreglo1[cont];
		int arreglo2[cont];
		comprobante1 = comprobarA(ldA, lsA, arreglo1);
		comprobante2 = comprobarB(ldB, lsB, arreglo2);
		if((cont == comprobante1) || (cont == comprobante2)){
			cout << "La lista enlazada simple esta contenida en al lista doblemente enlazada" << endl;
		}
		else{
			cout << "La lista enlazada simple no esta contenida en al lista doblemente enlazada" << endl;
		}
		return 0;
	}
	/**
	* Compruba que la lista este contenida en la lista doblemente enlazada cuando se recorre de adelante para atras
	*/
	int comprobarA(ListaDoble LD, ListaSimple LS, int arr[]){
		int cont = 0;
		int cont2 = 0;
		int cont3 = 0;
		int t = LD.removeLastD();
		int d = LS.removeFirst();
		while(d != 0){
			arr[cont] = d;
			d = LS.removeFirst();
			cont++;
		}
		while(t != 0){
			if(t == arr[cont2]){
				cont2++;
				cont3++;
			}
			t = LD.removeLastD();
		}
		return cont3;
	}
	/**
	 * Compruba que la lista este contenida en la lista doblemente enlazada cuando se recorre de atras para adelante
	 */
	int comprobarB(ListaDoble LD, ListaSimple LS, int arr[]){
		int cont = 0;
		int cont2 = 0;
		int cont3 = 0;
		int t = LD.removeFirstD();
		int d = LS.removeFirst();
		while(d != 0){
			arr[cont] = d;
			d = LS.removeFirst();
			cont++;
		}
		while(t != 0){
			if(t == arr[cont2]){
				cont2++;
				cont3++;
			}
			t = LD.removeFirstD();
		}
		return cont3;
	}
};


