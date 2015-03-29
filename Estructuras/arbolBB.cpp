/* 
 * File:   arbolBB.cpp
 * Author: luisrbrenes
 * 
 * Created on March 24, 2015, 11:54 PM
 */

#include "arbolBB.h"
#include <iostream>
using namespace std;



// Poda: borrar todos los nodos a partir de uno, incluido
void arbolBB::Podar(nodoArbol* &nodo)
{
   // Algoritmo recursivo, recorrido en postorden
   if(nodo) {
      Podar(nodo->GetIzquierdo()); // Podar izquierdo
      Podar(nodo->GetDerecho());   // Podar derecho
      delete nodo;            // Eliminar nodo
      nodo = NULL;
   }
}

// Insertar un int en el árbol ABB
void arbolBB::Insertar(const int dat)
{
   nodoArbol *padre = NULL;

   actual = raiz;
   // Buscar el int en el árbol, manteniendo un puntero al nodo padre
   while(!Vacio(actual) && dat != actual->GetDato()) {
      padre = actual;
      if(dat > actual->GetDato()) actual = actual->GetDerecho();
      else if(dat < actual->GetDato()) actual = actual->GetIzquierdo();
   }

   // Si se ha encontrado el elemento, regresar sin insertar
   if(!Vacio(actual)) return;
   // Si padre es NULL, entonces el árbol estaba vacío, el nuevo nodo será
   // el nodo raiz
   if(Vacio(padre)) raiz = new nodoArbol(dat);
   // Si el int es menor que el que contiene el nodo padre, lo insertamos
   // en la rama izquierda
   else if(dat < padre->GetDato()) padre->GetIzquierdo() = new nodoArbol(dat);
   // Si el int es mayor que el que contiene el nodo padre, lo insertamos
   // en la rama derecha
   else if(dat > padre->GetDato()) padre->GetDerecho() = new nodoArbol(dat);
}

// Eliminar un elemento de un árbol ABB
void arbolBB::Borrar(const int dat)
{
   nodoArbol *padre = NULL;
   nodoArbol *nodo;
   int aux;

   actual = raiz;
   // Mientras sea posible que el valor esté en el árbol
   while(!Vacio(actual)) {
      if(dat == actual->GetDato()) { // Si el valor está en el nodo actual
         if(EsHoja(actual)) { // Y si además es un nodo hoja: lo borramos
            if(padre) // Si tiene padre (no es el nodo raiz)
               // Anulamos el puntero que le hace referencia
               if(padre->GetDerecho() == actual) padre->SetDerecho() = NULL;
               else if(padre->GetIzquierdo() == actual) padre->SetIzquierdo() = NULL;
            delete actual; // Borrar el nodo
            actual = NULL;
            return;
         }
         else { // Si el valor está en el nodo actual, pero no es hoja
            // Buscar nodo
            padre = actual;
            // Buscar nodo más izquierdo de rama derecha
            if(actual->GetDerecho()) {
               nodo = actual->SetDerecho();
               while(nodo->GetIzquierdo()) {
                  padre = nodo;
                  nodo = nodo->SetIzquierdo();
               }
            }
            // O buscar nodo más derecho de rama izquierda
            else {
               nodo = actual->GetIzquierdo();
               while(nodo->GetDerecho()) {
                  padre = nodo;
                  nodo = nodo->GetDerecho();
               }
            }
            // Intercambiar valores de no a borrar u nodo encontrado
            // y continuar, cerrando el bucle. El nodo encontrado no tiene
            // por qué ser un nodo hoja, cerrando el bucle nos aseguramos
            // de que sólo se eliminan nodos hoja.
            aux = actual->GetDato();
            actual->GetDato() = nodo->SetDato();
            nodo->GetDato() = aux;
            actual = nodo;
         }
      }
      else { // Todavía no hemos encontrado el valor, seguir buscándolo
         padre = actual;
         if(dat > actual->GetDato()) actual = actual->GetDerecho();
         else if(dat < actual->GetDato()) actual = actual->GetIzquierdo();
      }
   }
}

// Recorrido de árbol en inorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void arbolBB::InOrden(void (*func)(int&) , nodoArbol *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->GetIzquierdo()) InOrden(func, nodo->SetIzquierdo(), false);
   func(nodo->GetDato());
   if(nodo->GetDerecho()) InOrden(func, nodo->SetDerecho(), false);
}

// Recorrido de árbol en preorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void arbolBB::PreOrden(void (*func)(int&), nodoArbol *nodo, bool r)
{
   if(r) nodo = raiz;
   func(nodo->GetDato());
   if(nodo->GetIzquierdo()) PreOrden(func, nodo->SetIzquierdo(), false);
   if(nodo->GetDerecho()) PreOrden(func, nodo->SetDerecho(), false);
}

// Recorrido de árbol en postorden, aplicamos la función func, que tiene
// el prototipo:
// void func(int&);
void arbolBB::PostOrden(void (*func)(int&), nodoArbol *nodo, bool r)
{
   if(r) nodo = raiz;
   if(nodo->GetIzquierdo()) PostOrden(func, nodo->SetIzquierdo(), false);
   if(nodo->GetDerecho()) PostOrden(func, nodo->SetDerecho(), false);
   func(nodo->GetDato());
}

// Buscar un valor en el árbol
bool arbolBB::Buscar(const int dat)
{
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->GetDato()) return true; // int encontrado
      else if(dat > actual->GetDato()) actual = actual->GetDerecho(); // Seguir
      else if(dat < actual->GetDato()) actual = actual->GetIzquierdo();
   }
   return false; // No está en árbol
}

// Calcular la altura del nodo que contiene el int dat
int arbolBB::Altura(const int dat)
{
   int altura = 0;
   actual = raiz;

   // Todavía puede aparecer, ya que quedan nodos por mirar
   while(!Vacio(actual)) {
      if(dat == actual->GetDato()) return altura; // int encontrado
      else {
         altura++; // Incrementamos la altura, seguimos buscando
         if(dat > actual->GetDato()) actual = actual->GetDerecho();
         else if(dat < actual->GetDato()) actual = actual->GetIzquierdo();
      }
   }
   return -1; // No está en árbol
}

// Contar el número de nodos
const int arbolBB::NumeroNodos()
{
   contador = 0;

   auxContador(raiz); // FUnción auxiliar
   return contador;
}

// Función auxiliar para contar nodos. Función recursiva de recorrido en
//   preorden, el proceso es aumentar el contador
void arbolBB::auxContador(nodoArbol *nodo)
{
   contador++;  // Otro nodo
   // Continuar recorrido
   if(nodo->GetIzquierdo()) auxContador(nodo->GetIzquierdo());
   if(nodo->GetDerecho())   auxContador(nodo->GetDerecho());
}

// Calcular la altura del árbol, que es la altura del nodo de mayor altura.
const int arbolBB::AlturaArbol()
{
   altura = 0;

   auxAltura(raiz, 0); // Función auxiliar
   return altura;
}

// Función auxiliar para calcular altura. Función recursiva de recorrido en
// postorden, el proceso es actualizar la altura sólo en nodos hojas de mayor
// altura de la máxima actual
void arbolBB::auxAltura(nodoArbol *nodo, int a)
{
   // Recorrido postorden
   if(nodo->GetIzquierdo()) auxAltura(nodo->GetIzquierdo(), a+1);
   if(nodo->GetDerecho())   auxAltura(nodo->GetDerecho(), a+1);
   // Proceso, si es un nodo hoja, y su altura es mayor que la actual del
   // árbol, actualizamos la altura actual del árbol
   if(EsHoja(nodo) && a > altura) altura = a;
}

// Función de prueba para recorridos del árbol
void Mostrar(int &d)
{
   cout << d << ",";
}