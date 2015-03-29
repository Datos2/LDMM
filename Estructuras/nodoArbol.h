/* 
 * File:   NodoArbol.h
 * Author: luisrbrenes
 *
 * Created on March 24, 2015, 11:52 PM
 */

#include <iostream>
#ifndef NODOARBOL_H
#define	NODOARBOL_H

class nodoArbol {
    public:
      // Constructor:
      nodoArbol(const int dat, nodoArbol *izq=NULL, nodoArbol *der=NULL) :
        dato(dat), izquierdo(izq), derecho(der) {}

        void SetDerecho(nodoArbol* derecho) {
            this->derecho = derecho;
        }

        nodoArbol* GetDerecho() const {
            return derecho;
        }

        void SetIzquierdo(nodoArbol* izquierdo) {
            this->izquierdo = izquierdo;
        }

        nodoArbol* GetIzquierdo() const {
            return izquierdo;
        }

        void SetDato(int dato) {
            this->dato = dato;
        }

        int GetDato() const {
            return dato;
        }
      // Miembros:
    private:  
      int dato;
      nodoArbol *izquierdo;
      nodoArbol *derecho;
   };

#endif	/* NODOARBOL_H */

