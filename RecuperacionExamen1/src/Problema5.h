/*
 * Problema5.h
 *
 *  Created on: 21/10/2017
 *      Author: Will
 */

#ifndef PROBLEMA5_H_
#define PROBLEMA5_H_

#include "stdlib.h"
#include "Persona.h"
#include "Premio.h"
#include <iostream>
using namespace std;

class ListaPersonas{
public:
	struct nodeL {
		persona per;
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
	persona firstL(){
		if(isEmptyL()){
			persona nullp;
			return nullp;
		}
		return headL->per;
	}
	persona lastL(){
		if(isEmptyL()){
			persona nullp;
			return nullp;
		}
		return tailL->per;
	}
	void addFirst(persona p) {
		nodeL *temp = new nodeL;
		temp->per = p;
		temp->next = headL;
		headL = temp;
		if(size1L == 0){
			tailL = temp;
			size1L++;
		}
	}
	void addLast(persona p){
		nodeL *temp = new nodeL;
		temp->per = p;
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
	string removeFirst(){
		if(isEmptyL()){
			return NULL;
		}
		string response = headL->per.nombreP;
		headL = headL->next;
		size1L--;
		if(size1L == 0){
			tailL = NULL;
		}
		return response;
	}
	persona removeData(int num){
		if(isEmptyL()){
			persona pnull;
			return pnull;
		}
		if(num <= size1L){
			nodeL *temp1 = headL;
			nodeL *temp2 = temp1;
			if(num == 1){
				headL = temp1->next;
				return temp1->per;
				temp1 = NULL;
				size1L--;
			}
			else{
				for(int i = 1; i < num; i++){
					temp2 = temp1;
					temp1 = temp1->next;
				}
				temp2->next = temp1->next;
				return temp1->per;
				temp1 = NULL;
				size1L--;
			}
		}
		else{
			persona pnull;
			return pnull;
		}
	}
};

class ListaPremios{
public:
	struct nodeL {
			premio pre;
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
		premio firstL(){
			if(isEmptyL()){
				premio pnull;
				return pnull;
			}
			return headL->pre;
		}
		premio lastL(){
			if(isEmptyL()){
				premio pnull;
				return pnull;
			}
			return tailL->pre;
		}
		void addFirst(premio p) {
			nodeL *temp = new nodeL;
			temp->pre = p;
			temp->next = headL;
			headL = temp;
			if(size1L == 0){
				tailL = temp;
				size1L++;
			}
		}
		void addLast(premio p){
			nodeL *temp = new nodeL;
			temp->pre = p;
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
		premio removeFirst(){
			if(isEmptyL()){
				premio pnull;
				return pnull;
			}
			premio response = headL->pre;
			headL = headL->next;
			size1L--;
			if(size1L == 0){
				tailL = NULL;
			}
			return response;
		}
};


#endif /* PROBLEMA5_H_ */
