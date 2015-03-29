/* 
 * File:   ListaDE.cpp
 * Author: luisrbrenes
 * 
 * Created on March 24, 2015, 11:55 PM
 */


using namespace std;

#define ASCENDENTE 1
#define DESCENDENTE 0

#include "listaDE.h"
#include "nodoLista.h"

lista::~lista()
{
   pnodo aux;
   
   Primero();
   while(plista) {
      aux = plista;
      plista = plista->GetSiguiente();
      delete aux;
   }
}

void lista::Insertar(int v)
{
   pnodo nuevo;
 
   Primero();
   // Si la lista está vacía
   if(ListaVacia() || plista->GetValor() > v) {
      // Asignamos a lista un nuevo nodo de valor v y
      // cuyo siguiente elemento es la lista actual                    
      nuevo = new nodoLista(v, plista);
      if(!plista) plista = nuevo;
      else plista->SetAnterior() = nuevo;
   }
   else {
      // Buscar el nodo de valor menor a v 
      // Avanzamos hasta el último elemento o hasta que el siguiente tenga 
      // un valor mayor que v 
      while(plista->GetSiguiente() && plista->GetSiguiente()->GetValor() <= v) Siguiente();
      // Creamos un nuevo nodo después del nodo actual
      nuevo = new nodoLista(v, plista->SetSiguiente(), plista);
      plista->SetSiguiente() = nuevo;
      if(nuevo->GetSiguiente()) nuevo->GetSiguiente()->GetAnterior() = nuevo;
   }
}

void lista::Borrar(int v)
{
   pnodo nodo;
   
   nodo = plista;
   while(nodo && nodo->GetValor() < v) nodo = nodo->GetSiguiente();
   while(nodo && nodo->GetValor() > v) nodo = nodo->GetAnterior();

   if(!nodo || nodo->GetValor() != v) return;
   // Borrar el nodo 
   
   if(nodo->GetAnterior()) // no es el primer elemento 
      nodo->GetAnterior()->GetSiguiente() = nodo->GetSiguiente();
   if(nodo->GetAnterior()) // no el el último nodo
      nodo->GetSiguiente()->GetAnterior() = nodo->GetAnterior();
   delete nodo;
}

void lista::Mostrar(int orden)
{
   pnodo nodo;
   if(orden == ASCENDENTE) {
      Primero();
      nodo = plista;
      while(nodo) {
         cout << nodo->GetValor() << "-> ";
         nodo = nodo->GetSiguiente();
      }
   }
   else {
      Ultimo();
      nodo = plista;
      while(nodo) {
         cout << nodo->GetValor() << "-> ";
         nodo = nodo->GetAnterior();
      }
   }
   cout << endl;
}

void lista::Siguiente()
{
   if(plista) plista = plista->GetSiguiente();
}

void lista::Anterior()
{
   if(plista) plista = plista->GetAnterior();
}

void lista::Primero()
{
   while(plista && plista->GetAnterior()) plista = plista->GetAnterior();
}

void lista::Ultimo()
{
   while(plista && plista->GetSiguiente()) plista = plista->GetSiguiente();
}
