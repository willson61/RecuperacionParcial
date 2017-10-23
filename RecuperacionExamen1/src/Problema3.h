/*
 * Problema3.h
 *
 *  Created on: 21/10/2017
 *      Author: Will
 */

#ifndef PROBLEMA3_H_
#define PROBLEMA3_H_

#include "stdlib.h"
#include <iostream>
using namespace std;

class Lista{
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
	/**
	 * void que ordena los int de lista de menor a mayor
	 */
	void ordenar(){
		nodeL *n1 = headL;
		nodeL *n2 = NULL;
		int temp;
		while(n1->next != NULL){
			n2 = n1->next;
			while(n2 != NULL){
				if(n1->number > n2->number){
					temp = n2->number;
					n2->number = n1->number;
					n1->number = temp;
				}
				n2 = n2->next;
			}
			n1 = n1->next;
		}
	}
};



#endif /* PROBLEMA3_H_ */
