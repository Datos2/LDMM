/* 
 * File:   ListaDE.h
 * Author: luisrbrenes
 *
 * Created on March 24, 2015, 11:55 PM
 */


#include "nodoLista.h"

using namespace std;
#ifndef LISTADE_H
#define	LISTADE_H


class lista {
   public:
    
    
       
    lista() : plista(NULL) {}
    ~lista();
    
    void Insertar(int v);
    void Borrar(int v);
    bool ListaVacia() { return plista == NULL; } 
    void Mostrar(int);
    void Siguiente();
    void Anterior();
    void Primero();
    void Ultimo();
    bool Actual() { return plista != NULL; }
    int ValorActual() { return plista->GetValor(); }
    
    private:
        pnodo plista;
    
    friend class nodoLista;
};

#endif	/* LISTADE_H */

