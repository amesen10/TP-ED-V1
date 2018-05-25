#ifndef LISTAORD_LSE_H
#define LISTAORD_LSE_H
#include "NodoL.h"
#include <iostream>
#include <string>

using namespace std;

template<class A>
class ListaOrd_LSE
{
    public:
        NodoL<A> *PrimerElem;
        int contador;

        ListaOrd_LSE(){

        }
        /**
        * @brief Inicializa la lista con nodo vacio
        * @param No recibe parámetros
        * @return void
        */
        void Iniciar(){
             PrimerElem=nullptr;
        }
         /**
        * @brief Elimina todos los elemntos existentes en la lista y luego la destruye, devolviendo todo el espacio al compilador
        * @param No recibe parámetros
        * @return void
        */
        void Destruir(){
            NodoL<A>* sig;
            while(PrimerElem!=nullptr){
                sig=PrimerElem->ptrSig;
                delete &PrimerElem;
                PrimerElem=sig;
            }
            delete this;
        }
         /**
        * @brief Elimina todos los elementos de la lista sin destruirla por completp.
        * @param No recibe parámetros
        * @return void
        */
        void Vaciar(){
            NodoL<A>* sig;
                while(PrimerElem!=nullptr){
                    sig=PrimerElem->ptrSig;
                    delete &PrimerElem;
                    PrimerElem=sig;
                }
        }
         /**
        * @brief Revisa el primer elemento de la lista para verificar si esta vacia.
        * @param No recibe parámetros
        * @return true en caso de que lo este, false de lo contrario.
        */
        bool Vacia(){
            if(PrimerElem!=nullptr){
                return true;
            }
            return false;
        }

         /**
        * @brief Este algoritmo realiza la insercion de los elementos de manera ordenada en la lista
        * @require Una relacion de mayor en los elementos que se inserten
        * @param dato: es el elemento a ser insertado
        * @return void
        */
        void Insertar(A dato){
            if(PrimerElem==nullptr){
                PrimerElem=new NodoL<A>(dato);
                ++contador;
            }else{
                if((PrimerElem->elemento)>dato){
                    NodoL<A> *nuevo=new NodoL<A>(dato);
                    nuevo->ptrSig=PrimerElem;
                    PrimerElem=nuevo;
                    ++contador;
                }else{
                    NodoL<A> *iter=PrimerElem;
                    bool insertado=false;
                    while(iter!=nullptr && !insertado){
                        if((iter->ptrSig) != nullptr){
                            if(((iter->elemento)<dato) && ((iter->ptrSig->elemento)>dato)){
                                NodoL<A>* nuevo=new NodoL<A>(dato);
                                nuevo->ptrSig=iter->ptrSig;
                                iter->ptrSig=nuevo;
                                insertado=true;
                                ++contador;
                            }
                        }
                        if(((iter->elemento)<dato) && ((iter->ptrSig)==nullptr)){
                            NodoL<A> *nuevo=new NodoL<A>(dato);
                            iter->ptrSig=nuevo;
                            insertado=true;
                            ++contador;
                        }
                        iter=iter->ptrSig;
                    }
                }
            }
        }

        /**
        * @brief Elimina el elemento de la lista que coincida con el que es enviado como parametro.
        * @require Que el elemento se encuentre en la lista.
        * @param dato: es el elemento a ser borrado
        * @return void
        */
        void Borrar(A dato){
            if(PrimerElem->elemento==dato){
                NodoL<A>* Temp=PrimerElem;
                PrimerElem=PrimerElem->ptrSig;
                --contador;
                delete Temp;
            }else{
                NodoL<A>* iterador=PrimerElem;
                NodoL<A>* iteradorAtrasado=PrimerElem;
                while(iterador->elemento<dato){
                        iterador=iterador->ptrSig;
                        if(iterador->elemento==dato){
                            iteradorAtrasado->ptrSig=iterador->ptrSig;
                            delete iterador;
                            --contador;
                            break;
                        }
                    iteradorAtrasado=iteradorAtrasado->ptrSig;
                }
            }
        }
        /**
        * @brief Devuelve la cantidad de elementos presentes en la lista
        * @param No recibe parámetros
        * @return contador: El contador con el numero de elementos.
        */
        int NumElem(){
            return contador;
        }
        /**
        * @brief Devuelve el elemento en la primera posicion de la lista
        * @param No recibe parámetros
        * @return El dato de tipo elemento en la primera posicion.
        */
        A Primero(){
           return PrimerElem->elemento;
        }
        /**
        * @brief Devuelve el elemento en la ultima posicion de la lista
        * @param No recibe parámetros
        * @return El dato de tipo elemento en la ultima posicion.
        */
        A Ultimo(){
            NodoL<A>* iterador=PrimerElem;
            while(iterador->ptrSig!=nullptr){
                iterador=iterador->ptrSig;
            }
            return iterador->elemento;
        }
        /**
        * @brief Devuelve el elemento en la siguiente posicion al elemento enviado como parametro
        * @param dato: elemento a ser enviado para comparacion
        * @return El dato de tipo elemento en la siguiente posicion a dato
        */
        A Siguiente(A dato){
            NodoL<A>* iterador=PrimerElem;
            while(iterador->elemento!=dato){
                iterador=iterador->ptrSig;
            }
            return iterador->ptrSig->elemento;
        }
        /**
        * @brief Devuelve el elemento en la anterior posicion al elemento enviado como parametro
        * @param dato: elemento a ser enviado para comparacion
        * @return El dato de tipo elemento en la anterior posicion a dato
        */
        A Anterior(A dato){
            NodoL<A>* iterador=PrimerElem->ptrSig;
            NodoL<A>* iteradorAtrasado=PrimerElem;
            while(iterador!=nullptr){
                if(iterador->elemento==dato){
                    return iteradorAtrasado->elemento;
                }
                iterador=iterador->ptrSig;
                iteradorAtrasado=iteradorAtrasado->ptrSig;
            }
        }
        /**
        * @brief Imprime la lista con todos sus elementos
        * @param no recibe parametros
        * @return void
        */
        void Imprimir(){
            NodoL<A>* iterador=PrimerElem;
            while(iterador!=nullptr){
                cout<<"  "<<iterador->elemento;
                iterador=iterador->ptrSig;
            }
            cout<<endl;
        }

        virtual ~ListaOrd_LSE(){

        }

    protected:

    private:
};

#endif // LISTAORD_LSE_H
