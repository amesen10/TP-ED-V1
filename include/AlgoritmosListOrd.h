#ifndef ALGORITMOSLISTORD_H
#define ALGORITMOSLISTORD_H
#include "ListaOrd_LSE.h"

template<class A>
class AlgoritmosListOrd
{
    public:
        AlgoritmosListOrd(){
        }
        virtual ~AlgoritmosListOrd(){

        }
        bool Iguales(ListaOrd_LSE<A> L1, ListaOrd_LSE<A> L2){
            if(L1.NumElem()!=L2.NumElem()){
                return false;
            }else{
                A iter1=L1.Primero();
                A iter2=L2.Primero();
                while(iter1!=L1.Ultimo()){
                    if(iter1!=iter2){
                        return false;
                    }
                    iter1=L1.Siguiente(iter1);
                    iter2=L2.Siguiente(iter2);
                }
                if(iter1!=iter2){
                    return false;
                }
                return true;
            }
        }
        void Copiar(ListaOrd_LSE<A> &L1, ListaOrd_LSE<A> L2){
            L1.Vaciar();
            A iter=L2.Primero();
            while(iter!=L2.Ultimo()){
                L1.Insertar(iter);
                iter=L2.Siguiente(iter);
            }
            L1.Insertar(iter);
        }
        bool Contenida(ListaOrd_LSE<A> L1, ListaOrd_LSE<A> L2){
            if(L2.NumElem()>L1.NumElem()){
                return false;
            }
            A iter1=L1.Primero();
            A iter2=L2.Primero();
            bool esElem=false;
            while(iter2!=L2.Ultimo()){
                while(iter1!=L1.Ultimo()){
                    if(iter2==iter1){
                        esElem=true;
                    }
                    iter1=L1.Siguiente(iter1);
                }
                if(iter2==iter1){
                        esElem=true;
                }
                if(!esElem){
                    return false;
                }else{
                    esElem=true;
                    iter1=L1.Primero();
                    iter2=L2.Siguiente(iter2);
                }
            }
            if(iter2==L1.Ultimo()){
                return true;
            }
            return false;
        }
        bool Pertenece(ListaOrd_LSE<A> L, A elem){
            A iter=L.Primero();
            while(iter!=L.Ultimo()){
                if(iter==elem){
                    return true;
                }
                iter=L.Siguiente(iter);
            }
            if(iter==elem){
                return true;
            }
            return false;
        }
        void Eliminar(ListaOrd_LSE<A> &L1, ListaOrd_LSE<A> L2){
            A iter=L2.Primero();
            while(iter!=L2.Ultimo()){
                if(Pertenece(L1, iter)){
                    L1.Borrar(iter);
                }
                iter=L2.Siguiente(iter);
            }
            if(Pertenece(L1, iter)){
                    L1.Borrar(iter);
            }
        }

    protected:

    private:
};

#endif // ALGORITMOSLISTORD_H
