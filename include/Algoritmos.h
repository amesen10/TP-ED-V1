#ifndef ALGORITMOS_H
#define ALGORITMOS_H
#include "ListaPosicionadaLSE.h"
#include "CajaS.h"
#include "CajaD.h"
#include "Pila.h"

//typedef CajaS* tipoPosicion;
//Se podria hacer un tipoPosicion
template <class A>
class Algoritmos
{
    public:
        void invertir(ListaPosicionadaLSE Lista){
            CajaS<A> *iter=Lista.Primera();
            CajaS<A> *iter2=Lista.Ultima();
            if((Lista.NumElem()%2)!=0){
                while(iter!=iter2){
                    Lista.Intercambiar(iter, iter2);
                    iter=iter->ptrNext;
                    iter2=Lista.Anterior(iter2);
                }
            }else{
                bool casoFinal=false;
                while(!casoFinal){
                    Lista.Intercambiar(iter, iter2);
                    iter=iter->ptrNext;
                    iter2=Lista.Anterior(iter2);
                    if((iter->ptrNext)==iter2){
                        casoFinal=true;
                    }
                }
            }
        }

        void Listar(ListaPosicionadaLSE Lista)
        {
            CajaS<A> *ptr=Lista.Primera();
            while(ptr!=nullptr)
            {
                std::cout<<Lista.Recuperar(ptr)<<" ";
                ptr=Lista.Siguiente(ptr);
            }
            //std::cout<<std::endl;
        }

        bool Simetrica(ListaPosicionadaLSE Lista){
            CajaS<A> *iter=Lista.Primera();
            CajaS<A> *iter2=Lista.Ultima();
            if((Lista.NumElem()%2)!=0){
                while(iter!=iter2){
                    if(Lista.Recuperar(iter)!= Lista.Recuperar(iter2))
                        return false;
                    iter=Lista.Siguiente(iter);
                    iter2=Lista.Anterior(iter2);
                }
            }else{
                bool casoFinal=false;
                while(!casoFinal){
                    if(iter->elemento != iter2->elemento)
                        return false;
                    iter=Lista.Siguiente(iter);
                    iter2=Lista.Anterior(iter2);
                    if(Lista.Siguiente(iter)==iter2){
                        casoFinal=true;
                    }
                }
            }
            return true;
        }

        bool BuscarElem(ListaPosicionadaLSE Lista, A elemento){
            CajaS<A> *iter=Lista.Primera();
            while(iter!=nullptr){
                if(Lista.Recuperar(iter) == elemento){
                    return true;
                }
                iter=Lista.Siguiente(iter);
            }
            return false;
        }

        void EliminarRepetidos(ListaPosicionadaLSE Lista)
        {
            CajaS<A> *ptr1=Lista.Primera();
            CajaS<A> *ptr2;
            while(Lista.Siguiente(ptr1)!=nullptr)
            {
                ptr2=Lista.Siguiente(ptr1);
                while(ptr2!=nullptr)
                {
                    if(Lista.Recuperar(ptr1) == Lista.Recuperar(ptr2))
                        Lista.Borrar(ptr2);
                    ptr2=Lista.Siguiente(ptr2);
                }
                ptr1=Lista.Siguiente(ptr1);
            }
        }

        bool Sublista(ListaPosicionadaLSE Lista1, ListaPosicionadaLSE Lista2){
            if(Lista2.NumElem()<Lista1.NumElem()){
                return false;
            }
            bool esElem=false;
            CajaS<A> *iter1=Lista1.Primera();
            CajaS<A> *iter2=Lista2.Primera();
            while(iter2!=nullptr)
            {
                iter1=Lista1.Primera();
                if(Lista1.Recuperar(iter1)==Lista2.Recuperar(iter2))
                {
                    CajaS<A> *aux=iter2;
                    esElem=true;
                    while(iter1!=Lista1.Ultima()&&esElem && aux!=Lista2.Ultima())
                    {
                        if(Lista1.Recuperar(Lista1.Siguiente(iter1))!=Lista2.Recuperar(Lista2.Siguiente(aux)))
                            esElem=false;
                        iter1=Lista1.Siguiente(iter1);
                        aux=Lista2.Siguiente(aux);
                    }
                    if(esElem)
                        return true;
                }
                iter2=Lista2.Siguiente(iter2);
            }
            return false;
        }

        void SeleccionIterativa(ListaPosicionadaLSE Lista){
            CajaS<A> *iter1=Lista.Primera();
            CajaS<A> *iter2;
            CajaS<A> *menor=Lista.Primera();
            while(iter1!=nullptr){
                iter2=Lista.Siguiente(iter1);
                while(iter2!=nullptr){
                    if(Lista.Recuperar(menor)>Lista.Recuperar(iter2)){
                        menor=iter2;
                    }
                    iter2=Lista.Siguiente(iter2);
                }
                Lista.Intercambiar(iter1, menor);
                iter1=Lista.Siguiente(iter1);
                menor=iter1;
            }
        }

        bool DosListasIguales(ListaPosicionadaLSE L1, ListaPosicionadaLSE L2)
        {
            if(L1.NumElem()!= L2.NumElem())
                return false;

            CajaS<A> *ptr1=L1.Primera();
            CajaS<A> *ptr2;
            bool coincidencia;
            while(ptr1!=nullptr)
            {
                coincidencia=false;
                ptr2=L2.Primera();
                while(ptr2!=nullptr && !coincidencia)
                {
                    if(L1.Recuperar(ptr1) == L2.Recuperar(ptr2))
                        coincidencia=true;
                    ptr2=L2.Siguiente(ptr2);
                }
                if(!coincidencia)
                    return false;
                ptr1=L1.Siguiente(ptr1);
            }
            return true;

        }

        void Burbuja(ListaPosicionadaLSE Lista)
        {
            CajaS<A> *ptrI;
            CajaS<A> *fin=Lista.Ultima();
            bool cambiado=true;
            while(cambiado)
            {
                ptrI=Lista.Primera();
                cambiado=false;

                while(ptrI!=fin)
                {
                    if( (Lista.Recuperar(ptrI)) > (Lista.Recuperar(Lista.Siguiente(ptrI))) )
                    {
                        Lista.Intercambiar(ptrI,Lista.Siguiente(ptrI));
                        cambiado=true;
                    }
                    ptrI=Lista.Siguiente(ptrI);
                }
                fin=Lista.Anterior(fin);
            }
        }

        void BurbujaBi(ListaPosicionadaLSE Lista)
        {
            CajaS<A> *ptrI;
            CajaS<A> *ptrD;
            CajaS<A> *inicio=Lista.Primera();
            CajaS<A> *fin=Lista.Ultima();
            bool cambiado=true;
            while(cambiado)
            {
                ptrI=inicio;
                cambiado=false;

                while(ptrI!=fin)
                {
                    if( (Lista.Recuperar(ptrI)) > (Lista.Recuperar(Lista.Siguiente(ptrI))) )
                    {
                        Lista.Intercambiar(ptrI,Lista.Siguiente(ptrI));
                        cambiado=true;
                    }
                    ptrI=Lista.Siguiente(ptrI);

                }
                if(!cambiado)
                    break;  //No hubieron cambios, ya está ordenada la lista

                cambiado=false;
                fin=Lista.Anterior(fin);
                ptrD=fin;

                while(ptrD!=inicio)
                {
                    if(Lista.Recuperar(ptrD) < Lista.Recuperar(Lista.Anterior(ptrD)))
                    {
                        Lista.Intercambiar(ptrD,Lista.Anterior(ptrD));
                        cambiado=true;
                    }
                    ptrD=Lista.Anterior(ptrD);
                }
                inicio=Lista.Siguiente(inicio);
            }
        }

        void SeleccionRe(ListaPosicionadaLSE Lista, CajaS<A> *ptr)
        {
            CajaS<A> *menor=ptr;
            CajaS<A> *aux=Lista.Siguiente(ptr);
            while(aux!=Lista.Siguiente(Lista.Ultima()))
            {
                if(Lista.Recuperar(menor)>Lista.Recuperar(aux))
                    menor=aux;
                aux=Lista.Siguiente(aux);
            }
            Lista.Intercambiar(menor, ptr);
            if(Lista.Siguiente(ptr)!=Lista.Ultima())
                SeleccionRe(Lista, Lista.Siguiente(ptr));
        }

        void SeleccionReConPila(ListaPosicionadaLSE Lista, Pila<CajaS<A>*> Pil){
            CajaS<A> *cambio;
            CajaS<A> *iter;
            CajaS<A> *menor;
            Pil.Poner(Lista.Primera());
            while(!Pil.Vacia()){
                cambio=Pil.Tope();
                iter=Lista.Siguiente(cambio);
                menor=cambio;
                while(iter!=nullptr){
                    if(Lista.Recuperar(menor)>Lista.Recuperar(iter)){
                        menor=iter;
                    }
                    iter=Lista.Siguiente(iter);
                }
                Lista.Intercambiar(menor, cambio);
                cambio=Lista.Siguiente(cambio);
                if(cambio==Lista.Ultima()){
                    Pil.Vaciar();
                }else{
                    Pil.Poner(cambio);
                }
            }
        }

        void QuickSortAho(ListaPosicionadaLSE Lista, CajaS<A> *minimo, CajaS<A> *maximo){
                if(minimo!=maximo){
                    CajaS<A> *posPiv=EncuentrePivote(Lista, minimo, maximo);
                    if(posPiv!=nullptr){
                        A pivote=Lista.Recuperar(posPiv);
                        CajaS<A> *k=Particion(Lista, minimo, maximo, pivote);
                        CajaS<A> *ptr=Lista.Anterior(k);
                        QuickSortAho(Lista ,minimo, ptr);
                        QuickSortAho(Lista, k, maximo);
                    }
                }
        }

        CajaS<A>* Particion(ListaPosicionadaLSE Lista, CajaS<A> *minimo, CajaS<A> *maximo, A piv){
            CajaS<A> *iter1=minimo;
            CajaS<A> *iter2=maximo;
            while(iter1!=Lista.Siguiente(iter2)){
                    Lista.Intercambiar(iter1, iter2);
                while(Lista.Recuperar(iter1)<piv){
                    iter1=Lista.Siguiente(iter1);
                }
                while(Lista.Recuperar(iter2)>=piv){
                    iter2=Lista.Anterior(iter2);
                }
            }
            return iter1;
        }

        CajaS<A>* EncuentrePivote(ListaPosicionadaLSE Lista, CajaS<A> *minimo, CajaS<A> *maximo){
            CajaS<A> *primerElem=minimo;
            CajaS<A> *iter=Lista.Siguiente(primerElem);
            while(iter!=Lista.Siguiente(maximo)){
                if(Lista.Recuperar(iter)>Lista.Recuperar(primerElem)){
                    return iter;
                }else if(Lista.Recuperar(iter)<Lista.Recuperar(primerElem)){
                    return primerElem;
                }
                iter=Lista.Siguiente(iter);
            }
            return nullptr;
        }

        void Insercion(ListaPosicionadaLSE& Lista)
        {
            CajaS<A> *ptr=Lista.Siguiente(Lista.Primera());
            CajaS<A> *aux;
            A elem;

            bool cambio=false;
            while(ptr!=nullptr)
            {
                cambio=false;
                aux=Lista.Anterior(ptr);
                if(Lista.Recuperar(ptr)<Lista.Recuperar(aux))
                {
                    elem=Lista.Recuperar(ptr);
                    CajaS<A> *aux2=ptr;
                    ptr=aux;
                    Lista.Borrar(aux2);

                    if(elem<Lista.Recuperar(Lista.Primera()))
                    {
                        Lista.Insertar(elem,Lista.Primera());
                        cambio=true;
                    }
                    while( aux!=Lista.Primera() && !cambio )
                    {
                        if(Lista.Recuperar(Lista.Anterior(aux))<elem && elem<Lista.Recuperar(aux))
                        {
                            Lista.Insertar(elem,aux);
                            cambio=true;
                        }
                        aux=Lista.Anterior(aux);
                    }
                }
                ptr=Lista.Siguiente(ptr);
            }
        }

        void Merge(ListaPosicionadaLSE &Lista, CajaS<A> *l, CajaS<A> *m, CajaS<A>* r)
        {
//            std::cout<<"\n  m: "<<Lista.Recuperar(m);
            ListaPosicionadaLSE L1, L2;
            L1.Iniciar(); L2.Iniciar();
            CajaS<A> *ptr1=l;
            CajaS<A> *ptr2;
            CajaS<A> *ptr3;

            while(ptr1!=m)
            {
//                std::cout<<"\n   "<<ptr1<<" m "<<Lista.Recuperar(m);
                L1.AgregarAlFinal(Lista.Recuperar(ptr1));
                ptr1=Lista.Siguiente(ptr1);
            }
            L1.AgregarAlFinal(Lista.Recuperar(ptr1));
            //std::cout<<"\n   "<<ptr1<<" m "<<Lista.Recuperar(m);
            ptr1=Lista.Siguiente(ptr1);
//            std::cout<<"\nL1: "; L1.imprimir();


            ptr2=ptr1;
            while(ptr1!=r)
            {
                L2.AgregarAlFinal(Lista.Recuperar(ptr1));
                ptr1=Lista.Siguiente(ptr1);
            }
            L2.AgregarAlFinal(Lista.Recuperar(ptr1));
            ptr1=Lista.Siguiente(ptr1);
//            std::cout<<"\nL1v2 : "; L2.imprimir();

            ptr1=L1.Primera();
            ptr2=L2.Primera();
            ptr3=l;

            while(ptr1!=nullptr && ptr2!=nullptr)
            {

                if(L1.Recuperar(ptr1)<=L2.Recuperar(ptr2))
                {
//                    std::cout<<"\n l1 : "<< L1.Recuperar(ptr1)<<" l2 : "<<L2.Recuperar(ptr2);
                    Lista.Modificar(L1.Recuperar(ptr1), ptr3);
                    ptr1=L1.Siguiente(ptr1);
                }
                else
                {
                    Lista.Modificar(L2.Recuperar(ptr2), ptr3);
                    ptr2=L2.Siguiente(ptr2);
                }
                ptr3=Lista.Siguiente(ptr3);
                //std::cout<<"\n       Cambio de ptr3 ";
            }
            while(ptr1!=nullptr)
            {
                Lista.Modificar(L1.Recuperar(ptr1), ptr3);
                ptr1=L1.Siguiente(ptr1);
                ptr3=Lista.Siguiente(ptr3);
            }
            while(ptr2!=nullptr)
            {
                Lista.Modificar(L2.Recuperar(ptr2), ptr3);
                ptr2=L2.Siguiente(ptr2);
                ptr3=Lista.Siguiente(ptr3);
            }
        }

        void MergeSort(ListaPosicionadaLSE Lista, CajaS<A>* l, CajaS<A>* r)
        {
            if(l!=r)
            {
//                std::cout<<"     L:"; Lista.imprimir();
                CajaS<A>* maux=l;
                int mI=0;
                while(maux!=r)
                {
//                    std::cout<<"\n    maux: "<<maux<<" r "<<r;
                    ++mI;
                    maux=Lista.Siguiente(maux);
//                    std::cout<<"\n   SALIO "<<mI;
                }
                mI=mI/2;
                int conta=1;
//                std::cout<<"\n    mI: "<<mI<<"  "<<Lista.NumElem();
                CajaS<A>* mpos=l;
                while(conta<=mI)
                {
                    mpos=Lista.Siguiente(mpos);
                    ++conta;
                }
//                std::cout<<"\n   Centro: "<<Lista.Recuperar(mpos);
                MergeSort(Lista, l, mpos);
                MergeSort(Lista, Lista.Siguiente(mpos), r);

                Merge(Lista, l, mpos, r);
            }
        }

        void Union(ListaPosicionadaLSE& L1, ListaPosicionadaLSE L2)
        {
            CajaS<A> *ptr1=L1.Primera();
            CajaS<A> *ptr2=L2.Primera();
            bool insertado;

            while(ptr2!=nullptr)
            {
                insertado=false;
                while(!insertado && ptr1!=nullptr)
                {
                    if(L2.Recuperar(ptr2)==L1.Recuperar(ptr1))
                    {
                        insertado=true;
                        ptr2=L2.Siguiente(ptr2);
                        ptr1=L1.Siguiente(ptr1);
                    }

                    if(L2.Recuperar(ptr2)<L1.Recuperar(ptr1))
                    {
                        L1.Insertar(L2.Recuperar(ptr2), ptr1);
                        insertado=true;
                        ptr2=L2.Siguiente(ptr2);
                    }
                    else
                        ptr1=L1.Siguiente(ptr1);
                }
                if(ptr1==nullptr)//Elementos restantes en L2 que son mayores que el último de L1
                {
                    L1.AgregarAlFinal(L2.Recuperar(ptr2));
                    ptr2=L2.Siguiente(ptr2);
                }
               // ptr2=L2.Siguiente(ptr2);
            }
        }

        void UnionSinOrd(ListaPosicionadaLSE& L1, ListaPosicionadaLSE L2){
            CajaS<A> *ptr2=L2.Primera();
            while(ptr2!=nullptr){
                if(!BuscarElem(L1, L2.Recuperar(ptr2))){
                    L1.AgregarAlFinal(L2.Recuperar(ptr2));
                }
                ptr2=L2.Siguiente(ptr2);
            }
        }

        void Interseccion(ListaPosicionadaLSE L1, ListaPosicionadaLSE L2, ListaPosicionadaLSE& L3)
        {
            CajaS<A> *ptr1=L1.Primera();
            CajaS<A> *ptr2=L2.Primera();
            while(ptr2!=nullptr&&ptr1!=nullptr)
            {
                if(L2.Recuperar(ptr2)==L1.Recuperar(ptr1))
                {
                    L3.AgregarAlFinal(L2.Recuperar(ptr2));
                    ptr1=L1.Siguiente(ptr1);
                    ptr2=L2.Siguiente(ptr2);
                }
                else
                    if(L2.Recuperar(ptr2)<L1.Recuperar(ptr1))
                    {
                        ptr2=L2.Siguiente(ptr2);
                    }
                    else
                        if(L2.Recuperar(ptr2)>L1.Recuperar(ptr1))
                        {
                            ptr1=L1.Siguiente(ptr1);
                        }
            }
        }

        void InterseccionSinOrd(ListaPosicionadaLSE L1, ListaPosicionadaLSE L2, ListaPosicionadaLSE& L3){
            CajaS<A> *ptr2=L2.Primera();
            while(ptr2!=nullptr){
                if(BuscarElem(L1, L2.Recuperar(ptr2))){
                    L3.AgregarAlFinal(L2.Recuperar(ptr2));
                }
                ptr2=L2.Siguiente(ptr2);
            }
        }

        void EliminarL2deL1(ListaPosicionadaLSE& L1, ListaPosicionadaLSE L2)
        {
            CajaS<A> *ptr1=L1.Primera();
            CajaS<A> *ptr2=L2.Primera();
            CajaS<A> *aux;
            while(ptr2!=nullptr&&ptr1!=nullptr)
            {
                if(L2.Recuperar(ptr2)==L1.Recuperar(ptr1))
                {
                    aux=ptr1;
                    ptr1=L1.Siguiente(ptr1);
                    ptr2=L2.Siguiente(ptr2);
                    L1.Borrar(aux);
                }
                else
                    if(L2.Recuperar(ptr2)<L1.Recuperar(ptr1))
                    {
                        ptr2=L2.Siguiente(ptr2);
                    }
                    else
                        if(L2.Recuperar(ptr2)>L1.Recuperar(ptr1))
                        {
                            ptr1=L1.Siguiente(ptr1);
                        }
            }
        }

        void EliminarL2deL1SinOrd(ListaPosicionadaLSE& L1, ListaPosicionadaLSE L2){
            CajaS<A> *ptr=L1.Primera();
            CajaS<A> *temp;
            while(ptr!=nullptr){
                if(BuscarElem(L2, L1.Recuperar(ptr))){
                    temp=ptr;
                    ptr=L1.Siguiente(ptr);
                    L1.Borrar(temp);
                }else{
                    ptr=L1.Siguiente(ptr);
                }

            }
        }

        Algoritmos(){}
        virtual ~Algoritmos(){}

    protected:

    private:
};

#endif // ALGORITMOS_H
