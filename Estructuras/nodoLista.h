/* 
 * File:   nodoLista.h
 * Author: luisrbrenes
 *
 * Created on March 24, 2015, 11:54 PM
 */

#include <iostream>
#include "listaDE.h"
#ifndef NODOLISTA_H
#define	NODOLISTA_H


class nodoLista {
   public:
    nodoLista(int v, nodoLista *sig = NULL, nodoLista *ant = NULL) :
       valor(v), siguiente(sig), anterior(ant) {}

       void SetAnterior(nodoLista* anterior) {
           this->anterior = anterior;
       }

       nodoLista* GetAnterior() const {
           return anterior;
       }

       void SetSiguiente(nodoLista* siguiente) {
           this->siguiente = siguiente;
       }

       nodoLista* GetSiguiente() const {
           return siguiente;
       }

       void SetValor(int valor) {
           this->valor = valor;
       }

       int GetValor() const {
           return valor;
       }

   private:
    int valor;
    nodoLista *siguiente;
    nodoLista *anterior;
        
   friend class lista;

};
   typedef nodoLista *pnodo;


#endif	/* NODOLISTA_H */

