#ifndef PILA_H
#define PILA_H
#include "Nodo.h"
#include <iostream>
#include <stdlib.h>
#include <sstream>

using namespace std;
template<class A>
class Pila
{
    public:
        Nodo<A> *inicio;

        Pila(){
        }
        /**
        * @brief Inicializa la lista en nulo
        * @param No recibe parámetros
        * @return void
        */
        void Crear(){
            inicio=nullptr;
        }
        /**
        * @brief Elimina todos los elemntos existentes en la pila y luego la destruye, devolviendo todo el espacio al compilador
        * @param No recibe parámetros
        * @return void
        */
        void Destruir(){
            Nodo<A> *sig;
            while(inicio!=nullptr){
                sig=inicio->ptrSig;
                delete &inicio;
                inicio=sig;
            }
            delete this;
        }
        /**
        * @brief Elimina todos los elementos de la pila sin destruirla por completp.
        * @param No recibe parámetros
        * @return void
        */
        void Vaciar(){
            Nodo<A> *sig;
            while(inicio!=nullptr){
                sig=inicio->ptrNext;
                delete &inicio;
                inicio=sig;
            }
        }
        /**
        * @brief Revisa el primer elemento de la pila para verificar si esta vacia.
        * @param No recibe parámetros
        * @return true en caso de que lo este, false de lo contrario.
        */
        bool Vacia(){
            if(inicio!=nullptr){
                return false;
            }
            return true;
        }
        /**
        * @brief Este algoritmo realiza la insercion de los elementos en la pila
        * @param dato: es el elemento a ser insertado
        * @return void
        */
        void Poner(A elemento){
            Nodo<A> *nuevoNodo= new Nodo<A>(elemento);
            nuevoNodo->ptrSig=inicio;
            inicio=nuevoNodo;
        }
        /**
        * @brief Este algoritmo extrae el elemento al tope de la ila
        * @param no recibe parametros
        * @return Retorna el nodo extraido
        */
        Nodo<A>* Quitar(){
            Nodo<A> *retorno=inicio;
            inicio=inicio->ptrSig;
            return retorno;
        }
        /**
        * @brief Este algoritmo etorna el elemento en el tope de la lista
        * @param no recibe parametros
        * @return retorna el elemento
        */
        A Tope(){
             return inicio->dato;
        }
        /**
        * @brief Imprime la pila con todos sus elementos
        * @param no recibe parametros
        * @return void
        */
        void Imprimir(){
            Nodo<A> *iterador=inicio;
            cout<<"Pila: "<<endl;
            while(iterador!=nullptr){
                cout <<iterador->dato<<" ";
                iterador=iterador->ptrSig;
            }
        }

        virtual ~Pila(){}

    protected:

    private:
};

#endif // PILA_H
