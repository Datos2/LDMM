/* 
 * File:   arbolBB.h
 * Author: luisrbrenes
 *
 * Created on March 24, 2015, 11:54 PM
 */
#include <iostream>
#include "nodoArbol.h"
#ifndef ARBOLBB_H
#define	ARBOLBB_H

class arbolBB {
  private:
   //// Clase local de Lista para Nodo de ArbolBinario:


   // Punteros de la lista, para cabeza y nodo actual:
   nodoArbol *raiz;
   nodoArbol *actual;
   int contador;
   int altura;

  public:
   // Constructor y destructor básicos:
   arbolBB() : raiz(NULL), actual(NULL) {}
   ~arbolBB() { Podar(raiz); }
   // Insertar en árbol ordenado:
   void Insertar(const int dat);
   // Borrar un elemento del árbol:
   void Borrar(const int dat);
   // Función de búsqueda:
   bool Buscar(const int dat);
   // Comprobar si el árbol está vacío:
   bool Vacio(nodoArbol *r) { return r==NULL; }
   // Comprobar si es un nodo hoja:
   bool EsHoja(nodoArbol *r) { return !r->GetDerecho() && !r->GetIzquierdo(); }
   // Contar número de nodos:
   const int NumeroNodos();
   const int AlturaArbol();
   // Calcular altura de un int:
   int Altura(const int dat);
   // Devolver referencia al int del nodo actual:
   int ValorActual() { return actual->GetDato(); }
   // Moverse al nodo raiz:
   void Raiz() { actual = raiz; }
   // Aplicar una función a cada elemento del árbol:
   void InOrden(void (*func)(int&) , nodoArbol *nodo=NULL, bool r=true);
   void PreOrden(void (*func)(int&) , nodoArbol *nodo=NULL, bool r=true);
   void PostOrden(void (*func)(int&) , nodoArbol *nodo=NULL, bool r=true);
  private:
   // Funciones auxiliares
   void Podar(nodoArbol* &);
   void auxContador(nodoArbol*);
   void auxAltura(nodoArbol*, int);
};

#endif	/* ARBOLBB_H */

