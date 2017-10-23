//============================================================================
// Name        : RecuperacionExamen1.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include "Problema2.cpp"
#include "Problema3.cpp"
#include "Problema4.cpp"
#include "Problema5.cpp"

using namespace std;
/**
 * Nodo de lista enlazada simple
 */
struct nodeL {
	int number;
	nodeL *next;
};
//Head y tail de lista enlazada simple
nodeL *headL;
nodeL *tailL;
int size1L = 0;
//Prototipos de metodos y funciones de lista enlazada y metodos y funciones de implementacion de cola y pila
int sizeL();
bool isEmptyL();
int firstL();
int lastL();
void addFirst(int num);
void addLast(int num);
int removeFirst();
void push(int num);
int top();
int pop();
void enqueue(int num);
int dequeue();

/**
 * Nodo de lista enlazada doble
 */
struct nodeD {
	int number;
	nodeD *next;
	nodeD *prev;
};
//head y tail de lista enlazada doble
nodeD *headD = NULL;
nodeD *tailD = NULL;
//Prototipos de metodos y funciones de lista enlazada doble
int size1D = 0;
int sizeD();
bool isEmptyD();
int firstD();
int lastD();
void beginDoubleLinked();
void addFirstD(int num);
void addLastD(int num);
void addBetweenD(int num, nodeD *sucessor, nodeD *predecessor);
int removeLastD();
int removeFirstD();
int removeD(nodeD *node);

/**
 * Nodo de lista circular
 */
struct nodeC{
	int number;
	nodeC *next;
};
//tail de lista circular
nodeC *tailC;
//Prototipos de metodos y funciones de lista circular
int size1C = 0;
int sizeC();
bool isEmptyC();
int firstC();
int lastC();
void rotate();
void addFirstC(int num);
void addLastC(int num);
int removeFirstC();

int main() {
	cout << "Problema 1" << endl;
	cout << "!!!Implementacion de Lista enlazada!!!" << endl;
	addFirst(1);
	addLast(2);
	addLast(3);
	addLast(5);
	addLast(4);
	int val = removeFirst();
	while(val != 0){
		cout << val << endl;
		val = removeFirst();
	}

	cout << "!!!Implementacion de lista doblemente enlazada!!!" << endl;

	beginDoubleLinked();
	addFirstD(4);
	addFirstD(5);
	addLastD(10);
	addFirstD(1);
	int val2 = removeFirstD();
	while(val2 != 0){
		cout << val2 << endl;
		val2 = removeFirstD();
	}

	cout << "!!!Implementacion de lista circular!!!" << endl;
	addFirstC(4);
	addLastC(8);
	addFirstC(1);
	addLastC(12);
	int val3 = removeFirstC();
	while(val3 != 0){
		cout << val3 << endl;
		val3 = removeFirstC();
	}

	cout << "!!!implementacion de pila en lista enlazada!!!" << endl;
	push(10);
	push(20);
	push(30);
	push(15);
	int val4 = pop();
	while(val4 != 0){
		cout << val4 << endl;
		val4 = pop();
	}

	cout << "!!!implementacion de cola en lista enlazada!!!" << endl;
	enqueue(15);
	enqueue(10);
	enqueue(20);
	enqueue(50);
	int val5 = dequeue();
	while(val5 != 0){
		cout << val5 << endl;
		val5 = dequeue();
	}
	//Objeto de clase que contiene el problema 2
	Problema2 problema;
	problema.main2();
	//Objeto de clase que contiene el problema 3
	Problema3 problema1;
	problema1.main3();
	//Objeto de clase que contiene el problema 4
	Problema4 problema2;
	problema2.main4();
	//Objeto de clase que contiene el problema 5
	Problema5 problema3;
	problema3.main5();
	return 0;
}
/**
 * @return size1L int el tamaño de la lista
 */
int sizeL(){
	return size1L;
}
/**
 * @return bool que determina si esta vacia o no la lista
 */
bool isEmptyL(){
	return size1L == 0;
}
/**
 * @return primer numero de la lista
 */
int firstL(){
	if(isEmptyL()){
		return 0;
	}
	return headL->number;
}
/**
 * @return ultimo numero de la lista
 */
int lastL(){
	if(isEmptyL()){
			return 0;
		}
		return tailL->number;
}
/**
 * Agrega un numero al inicio de la lista (solo se hace una vez para iniciar la lista)
 * @param num int de numero que se agrega al inicio
 */
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
/**
 * Agrega un numero al final de lista
 * @param num int de numero que se agrega de ultimo
 */
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
/**
 * borra y devuelve el valor guardado en el primer nodo de lalista
 */
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
 * Metodos de implementacion de pila
 * Agrega un nodo a la pila
 * @param num int de numero que se agrega
 */
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
/**
 * Devuelve el valor del nodo del tope de la pila
 */
int top(){
	return firstL();
}
/**
 * Saca el nodo al tope de la pila
 */
int pop(){
	return removeFirst();
}
/**
 * Metodos de implementacion de cola
 * Agrega un nodo a la cola
 * @param num int de numero que se agrega
 */
void enqueue(int num){
	addLast(num);
}
/**
 * Saca el nodo al fondo de la cola
 */
int dequeue(){
	return removeFirst();
}


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
/**
 * Inicializa la lista doblemente enlazada
 */
void beginDoubleLinked(){
	headD = new nodeD;
	tailD = new nodeD;
	headD->next = NULL;
	headD->prev = NULL;
	tailD->next = NULL;
	tailD->prev = headD;
	headD->next = tailD;
}
/**
 * Agregar un nuevo nodo en medio de 2 nodos
 * @param num int de numero que se agrega
 * @param predecessor nodo predecesor al nodo que se agrega
 * @param sucessor nodo sucesor al nodo que se agrega
 */
void addBetweenD(int num, nodeD *predecessor, nodeD *sucessor){
	nodeD *temp = new nodeD;
	temp->prev = predecessor;
	temp->next = sucessor;
	temp->number = num;
	predecessor->next = temp;
	sucessor->prev = temp;
	size1D++;
}
/**
 * Agrega un nodo al inicio de la lista doblemente enlazada
 * @param num int de numero que se agrega
 */
void addFirstD(int num){
	addBetweenD(num, headD, headD->next);
}
/**
 * Agrega un nodo al final de la lista doblemente enlazada
 * @param num int de numero que se agrega
 */
void addLastD(int num){
	addBetweenD(num, tailD->prev, tailD);
}
/**
 * remueve un nodo especifico
 * @param nodo	nodo que se elimina de la lista
 */
int removeD(nodeD *nodo){
	nodeD *predecessor = nodo->prev;;
	nodeD *sucessor = nodo->next;
	predecessor->next = sucessor;
	sucessor->prev = predecessor;
	size1D--;
	return nodo->number;
}
/**
 * Remueve un nodo al final de la lista doblemente enlazada
 */
int removeLastD(){
	if(isEmptyD()){
		return 0;
	}
	return removeD(tailD->prev);
}
/**
 * Remueve un nodo al inicio de la lista doblemente enlazada
 */
int removeFirstD(){
	if(isEmptyD()){
			return 0;
	}
	return removeD(headD->next);
}


int sizeC(){
	return size1C;
}
bool isEmptyC(){
	return size1C == 0;
}
int firstC(){
	if(isEmptyC()){
		return 0;
	}
	return tailC->next->number;
}
int lastC(){
	if(isEmptyC()){
			return 0;
		}
		return tailD->number;
}
void rotate(){
	if(tailC != NULL){
		tailC = tailC->next;
	}
}
void addFirstC(int num){
	if(size1C == 0){
		tailC = new nodeC;
		tailC->number = num;
		tailC->next = tailC;
	}
	else{
		nodeC *temp = new nodeC;
		temp->number = num;
		temp->next = tailC->next;
		tailC->next = temp;
	}
	size1C++;
}
void addLastC(int num){
	addFirstC(num);
	tailC = tailC->next;
}
int removeFirstC(){
	if(isEmptyC()){
		return 0;
	}
	nodeC *headC = tailC->next;
	if(headC == tailC){
		tailC = NULL;
	}
	else{
		tailC->next = headC->next;
	}
	size1C--;
	return headC->number;
}
