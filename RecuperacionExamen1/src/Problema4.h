/*
 * Problema4.h
 *
 *  Created on: 21/10/2017
 *      Author: Will
 */

#ifndef PROBLEMA4_H_
#define PROBLEMA4_H_

#include "stdlib.h"
#include <iostream>
using namespace std;

class ListaSimple{
public:
	struct nodeL {
		int number;
		nodeL *next;
	};
	nodeL *headL;
	nodeL *tailL;
	int size1L = 0;
	int sizeL(){
		return size1L;
	}
	bool isEmptyL(){
		return size1L == 0;
	}
	int firstL(){
		if(isEmptyL()){
			return 0;
		}
		return headL->number;
	}
	int lastL(){
		if(isEmptyL()){
			return 0;
		}
		return tailL->number;
	}
	void addFirst(int num) {
		nodeL *temp = new nodeL;
		temp->number = num;
		temp->next = headL;
		headL = temp;
		if(size1L == 0){
			tailL = temp;
			size1L++;
		}
	}
	void addLast(int num){
		nodeL *temp = new nodeL;
		temp->number = num;
		temp->next = NULL;
		if(isEmptyL()){
			headL = temp;
		}
		else{
			tailL->next = temp;
		}
		tailL = temp;
		size1L++;
	}
	int removeFirst(){
		if(isEmptyL()){
			return 0;
		}
		int response = headL->number;
		headL = headL->next;
		size1L--;
		if(size1L == 0){
			tailL = NULL;
		}
		return response;
	}
};
class ListaDoble{
public:
	struct nodeD {
		int number;
		nodeD *next;
		nodeD *prev;
	};
	nodeD *headD = NULL;
	nodeD *tailD = NULL;
	int size1D = 0;
	int sizeD(){
		return size1D;
	}
	bool isEmptyD(){
		return size1D == 0;
	}
	int firstD(){
		if(isEmptyD()){
			return 0;
		}
		return headD->next->number;
	}
	int lastD(){
		if(isEmptyD()){
				return 0;
			}
			return tailD->prev->number;
	}
	void beginDoubleLinked(){
		headD = new nodeD;
		tailD = new nodeD;
		headD->next = NULL;
		headD->prev = NULL;
		tailD->next = NULL;
		tailD->prev = headD;
		headD->next = tailD;
	}
	void addBetweenD(int num, nodeD *predecessor, nodeD *sucessor){
		nodeD *temp = new nodeD;
		temp->prev = predecessor;
		temp->next = sucessor;
		temp->number = num;
		predecessor->next = temp;
		sucessor->prev = temp;
		size1D++;
	}
	void addFirstD(int num){
		addBetweenD(num, headD, headD->next);
	}
	void addLastD(int num){
		addBetweenD(num, tailD->prev, tailD);
	}
	int removeD(nodeD *nodo){
		nodeD *predecessor = nodo->prev;;
		nodeD *sucessor = nodo->next;
		predecessor->next = sucessor;
		sucessor->prev = predecessor;
		size1D--;
		return nodo->number;
	}
	int removeLastD(){
		if(isEmptyD()){
			return 0;
		}
		return removeD(tailD->prev);
	}
	int removeFirstD(){
		if(isEmptyD()){
				return 0;
		}
		return removeD(headD->next);
	}
};



#endif /* PROBLEMA4_H_ */
