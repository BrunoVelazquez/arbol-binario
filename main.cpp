// Alumno: Bruno Levi Velázquez Sánchez
// Grupo: DS-DEDA-2002-B1-003
// Semestre: 2002-B1
// Fecha: miércoles, 2 de septiembre de 2020
// Docente: Jazmín Pérez Méndez

#include<iostream>
#include<stdio.h>
#include<stdlib.h>

struct nodo {
	char dato;
	struct nodo *der;
	struct nodo *izq;
};

typedef struct nodo _nodo;

_nodo *crear(char dato){
	_nodo *nuevo;
	nuevo = (_nodo *)malloc(sizeof(_nodo));
	nuevo->dato = dato;
	nuevo->der = NULL;
	nuevo->izq = NULL;

	return nuevo;
}

_nodo *agregarDerecha(_nodo *nuevo, _nodo *raiz){
	raiz->der = nuevo;
	return raiz;
}

_nodo *agregarIzquierda(_nodo *nuevo, _nodo *raiz){
	raiz->izq = nuevo;
	return raiz;
}

void imprimir(_nodo *nodo){
	if(nodo != NULL){
		printf(" %c ", nodo->dato);
	}
}

void preOrden(_nodo *raiz){
	if(raiz != NULL){
		imprimir(raiz);
		preOrden(raiz->izq);
		preOrden(raiz->der);
	}
}

void inOrden(_nodo *raiz){
	if(raiz != NULL){
		inOrden(raiz->izq);
		imprimir(raiz);
		inOrden(raiz->der);
	}
}

void posOrden(_nodo *raiz){
	if(raiz != NULL){
		posOrden(raiz->izq);
		posOrden(raiz->der);
		imprimir(raiz);
	}
}

int main() {
	_nodo *raiz;

	raiz = crear('+');
	raiz->izq = crear('*');
	raiz->der = crear('^');
	raiz->izq->izq = crear('A');
	raiz->izq->der = crear('B');
	raiz->der->izq = crear('/');
	raiz->der->izq->izq = crear('C');
	raiz->der->izq->der = crear('D');
	raiz->der->der = crear('2');

	printf("Preorden (R I D): ");
	preOrden(raiz);
	printf("\nInorden (I R D): ");
	inOrden(raiz);
	printf("\nPostorden (I D R): ");
	posOrden(raiz);
	printf("\n");
	return 0;
}
