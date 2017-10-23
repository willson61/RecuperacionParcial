/*
 * Problema2.h
 *
 *  Created on: 21/10/2017
 *      Author: Will
 */

#ifndef PROBLEMA2_H_
#define PROBLEMA2_H_

#include "stdlib.h"
#include <iostream>
using namespace std;

class Pila{
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
	void push(int num){
		nodeL *temp = new nodeL;
		temp->number = num;
		temp->next = headL;
		if(size1L == 0){
			headL = temp;
			tailL = temp;
			size1L++;
		}
		else{
			headL = temp;
			size1L++;
		}
	}
	int top(){
		return firstL();
	}
	int pop(){
		return removeFirst();
	}
	void enqueue(int num){
		addLast(num);
	}
	int dequeue(){
		return removeFirst();
	}
};


#endif /* PROBLEMA2_H_ */
