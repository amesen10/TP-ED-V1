#ifndef ALGORITMOSLINDEX_H
#define ALGORITMOSLINDEX_H
#include "ListaIndexadaLSE.h"
#include "Pila.h"
#include "CajaS.h"


template <class A> class AlgoritmosLIndex
{
    public:
        void Listar( ListaIndexadaLSE L)const
        {
            int indice=1;
            int num=L.NumElem();
            while(indice<=num)
            {
                std::cout<<L.Recuperar(indice)<<" ";
                ++indice;
            }
        }

        bool Simetrica(ListaIndexadaLSE L) const
        {
            int inicio=1;
            int fin=L.NumElem();
            int num=L.NumElem();
            while(fin>num/2)
            {
                if(L.Recuperar(inicio)!=L.Recuperar(fin))
                    return false;
                ++inicio;
                --fin;
            }
            return true;
        }

        void Invertir(ListaIndexadaLSE L)
        {
            int inicio=1;
            int fin=L.NumElem();
            int num=L.NumElem();
            while(fin>num/2)
            {
                L.Intercambiar(inicio, fin);
                ++inicio;
                --fin;
            }
        }

        bool Buscar(ListaIndexadaLSE L, A elemento)
        {
            int indice=1;
            int num=L.NumElem();
            while(indice<=num)
            {
                if(L.Recuperar(indice)==elemento)
                    return true;
                ++indice;
            }
            return false;
        }

        void EliminarRepetidos(ListaIndexadaLSE L)
        {
            int indice=1, aux, num=L.NumElem();
            while(indice<num)
            {
                aux=indice+1;
                if(L.Recuperar(indice)==L.Recuperar(aux))
                    L.Borrar(aux);
                ++indice;
            }
        }

        bool Sublista(ListaIndexadaLSE L1, ListaIndexadaLSE L2)
        {
            if(L1.NumElem()>L2.NumElem())
                return false;

            int indice1=1, indice2=1, num1=L1.NumElem(), num2=L2.NumElem();
            bool sub=false;
            while(indice2<=num2)
            {
//                std::cout<<"\n  Entra ciclo";
                if(L1.Recuperar(1)==L2.Recuperar(indice2))
                {
//                    std::cout<<"\n  Primeros elems iguales   ";
                    if(indice2-1+num1<=num2)
                    {
//                        std::cout<<"\n  indice2+num1<=num2   ";
                        int aux=1;
                        sub=true;
                        while(sub&&aux<num1)
                        {
//                            std::cout<<"\n L1: "<<L1.Recuperar(1+aux)<< "L2: "<<L2.Recuperar(indice2+aux);
                            if(L1.Recuperar(1+aux)!=L2.Recuperar(indice2+aux))
                                sub=false;
                            ++aux;
                        }
                        if(sub)
                        {
//                            std::cout<<"\n     SUB ES TRUE\n";
                            return true;
                        }
                    }
                }
                ++indice2;
            }
            return false;
        }

        bool Iguales(ListaIndexadaLSE L1, ListaIndexadaLSE L2)
        {
            if(L1.NumElem()!=L2.NumElem())
                return false;
            int indice=1, num=L1.NumElem();

            while(indice<=num)
            {
                if(L1.Recuperar(indice)!=L2.Recuperar(indice))
                    return false;
                ++indice;
            }
            return true;

        }

        void Burbuja(ListaIndexadaLSE L)
        {
            int indice, num=L.NumElem();
            bool cambiado=true;
            while(cambiado)
            {
                indice=1;
                cambiado=false;

                while(indice<num)
                {
                    if(L.Recuperar(indice)> L.Recuperar(indice+1))
                    {
                        L.Intercambiar(indice, indice+1);
                        cambiado=true;
                    }
                    ++indice;
                }
                --num;
            }
        }

        void BurbujaBi(ListaIndexadaLSE L)
        {
            int indice1, indice2, num=L.NumElem(), inicio=1;
            bool cambiado=true;
            while(cambiado)
            {
                indice1=1;
                cambiado=false;

                while(indice1<num)
                {
                    if(L.Recuperar(indice1)>L.Recuperar(indice1+1))
                    {
                        L.Intercambiar(indice1, indice1+1);
                        cambiado=true;
                    }
                    ++indice1;
                }
                if(!cambiado)
                    break;      //No hubieron cambios, ya está ordenada la lista
                cambiado=false;
                --num;
                indice2=num;
                while(indice2>inicio)
                {
                    if(L.Recuperar(indice2)<L.Recuperar(indice2-1))
                    {
                        L.Intercambiar(indice2, indice2-1);
                        cambiado=true;
                    }
                    --indice2;
                }
                ++inicio;
            }
        }

        void SeleccionIterativa(ListaIndexadaLSE L)
        {
            int indice=1, aux, num=L.NumElem(), menor;
            while(indice<num)
            {
                menor=indice;
                aux=indice+1;
                while(aux<=num)
                {
                    if(L.Recuperar(menor)>L.Recuperar(aux))
                        menor=aux;
                    ++aux;
                }
                L.Intercambiar(indice, menor);
                ++indice;
            }
        }

        void SeleccionRe(ListaIndexadaLSE L, int indice)
        {
            int num=L.NumElem();
            int menor=indice;
            int aux=indice+1;
            while(aux<=num)
            {
                if(L.Recuperar(menor)>L.Recuperar(aux))
                    menor=aux;
                ++aux;
            }
            L.Intercambiar(indice, menor);
            if(indice+1!=num)
                SeleccionRe(L, indice+1);
        }

        void SeleccionReConPila(ListaIndexadaLSE L, Pila<int> P)
        {

            int indice, aux, menor, num=L.NumElem();
            P.Poner(1);
            while(!P.Vacia())
            {
                indice=P.Tope();
                aux=indice+1;
                menor=indice;
                while(aux<=num)
                {
                    if(L.Recuperar(menor)>L.Recuperar(aux))
                        menor=aux;
                    ++aux;
                }
                L.Intercambiar(indice, menor);
                ++indice;
                if(indice==num-1)
                    P.Vaciar();
                else
                    P.Poner(indice);
            }
        }

        void Insercion(ListaIndexadaLSE& L)
        {
            int indice=2, aux, num=L.NumElem();
            A elem;

            bool cambio;
            while(indice<=num)
            {
                cambio=false;
                aux=indice-1;
                if(L.Recuperar(indice)<L.Recuperar(aux))
                {
                    elem=L.Recuperar(indice);
                    int aux2=indice;
                    indice=aux;
                    L.Borrar(aux2);

                    if(elem<L.Recuperar(1))
                    {
                        L.Insertar(elem, 1);
                        cambio=true;
                    }
                    while(aux>1 && !cambio)
                    {
                        if(L.Recuperar(aux-1)<elem && L.Recuperar(aux)>elem)
                        {
                            L.Insertar(elem, aux);
                            cambio=true;
                        }
                        --aux;
                    }
                }
                ++indice;
            }
        }

        void Merge(ListaIndexadaLSE& L, int l, int m, int r)
        {
            int indice1=0, indice2=0, indiceL;
            int num1=m-l+1;
            int num2=r-m;

            ListaIndexadaLSE L1, L2;
            L1.Iniciar(); L2.Iniciar();

            //Llenado de sublistas
            while(indice1<num1)
            {
                L1.Insertar(L.Recuperar(l+indice1), indice1+1);
                ++indice1;
            }
            while(indice2<num2)
            {
                L2.Insertar(L.Recuperar(m+indice2+1), indice2+1);
                ++indice2;
            }
            indice1=1;
            indice2=1;
            indiceL=l;

            while(indice1<=num1 && indice2<=num2)
            {
                if(L1.Recuperar(indice1)<=L2.Recuperar(indice2))
                {
                    L.Modificar(L1.Recuperar(indice1), indiceL);
                    ++indice1;
                }
                else
                {
                    L.Modificar(L2.Recuperar(indice2), indiceL);
                    ++indice2;
                }
                ++indiceL;
            }
            while(indice1<=num1)
            {
                L.Modificar(L1.Recuperar(indice1), indiceL);
                ++indice1;
                ++indiceL;
            }
            while(indice2<=num2)
            {
                L.Modificar(L2.Recuperar(indice2), indiceL);
                ++indice2;
                ++indiceL;
            }

        }

        void MergeSort(ListaIndexadaLSE& L, int l, int r)
        {
            if(l<r)
            {
                int m=l+(r-l)/2;
                MergeSort(L, l, m);
                MergeSort(L, m+1, r);
                Merge(L, l, m, r);
            }
        }

        void Union(ListaIndexadaLSE& L1, ListaIndexadaLSE L2)
        {
            int indice1=1, indice2=1, num1=L1.NumElem(), num2=L2.NumElem();
            bool insertado;

                while(indice2<=num2)
                {
                    insertado=false;
                    while(!insertado && indice1<=num1)
                    {
//                        std::cout<<"\n En L2 "<<L2.Recuperar(indice2)<<" i1: "<<indice1;
                        if(L2.Recuperar(indice2)==L1.Recuperar(indice1))
                        {
                            insertado=true;
                            ++indice1;
                            ++indice2;
                        }
                        else
                        {
                            if(L2.Recuperar(indice2)<L1.Recuperar(indice1))
                            {
                                //std::cout<<"\n   Insertar pos "<<indice1<<" Elem "<<L2.Recuperar(indice1);
                                L1.Insertar(L2.Recuperar(indice2), indice1);
                                insertado=true;
                                //--indice1;
                                ++num1;
                                ++indice2;
                            }
                            if(L2.Recuperar(indice2)>L1.Recuperar(indice1))
                            {
//                                std::cout<<"\n   "<<L2.Recuperar(indice2)<<"<"<<L1.Recuperar(indice1);
                                ++indice1;
                            }
                        }
                    }

                    //++indice2;
                    if(indice1==num1+1)
                    {
                        int aux=indice1;
//                        std::cout<<"   Deberia entrar :"<<L2.Recuperar(indice2);
                        while(indice2<=num2)
                        {
                            L1.Insertar(L2.Recuperar(indice2), aux);
                            ++aux;
                            ++indice2;
                        }
                    }
                }
//                std::cout<<"\n    num1: "<<num1<<" indice1: "<<indice1<< " indice2: "<<indice2;
            }

        void UnionSinOrd(ListaIndexadaLSE& L1, ListaIndexadaLSE L2)
        {
            int indice2=1, num1=L1.NumElem(), num2=L2.NumElem();

            while(indice2<=num2)
            {
                if(!Buscar(L1, L2.Recuperar(indice2)))
                {
                    L1.Insertar(L2.Recuperar(indice2), num1);
                    ++num1;
                }
                ++indice2;
            }
        }

        void Interseccion(ListaIndexadaLSE L1, ListaIndexadaLSE L2, ListaIndexadaLSE& L3)
        {
            int indice1=1, indice2=1, indice3=1, num1=L1.NumElem(), num2=L2.NumElem();

            while(indice1<=num1 && indice2<=num2)
            {
                if(L1.Recuperar(indice1)==L2.Recuperar(indice2))
                {
                    L3.Insertar(L1.Recuperar(indice1),indice3);
                    ++indice1; ++indice2; ++indice3;
                }
                else
                    if(L2.Recuperar(indice2)<L1.Recuperar(indice1))
                        ++indice2;
                    else
                        if(L2.Recuperar(indice2)>L1.Recuperar(indice1))
                        ++indice1;

            }
        }

        void InterseccionSinOrd(ListaIndexadaLSE L1, ListaIndexadaLSE L2, ListaIndexadaLSE& L3)
        {
            int indice2=1, indice3=1, num2=L2.NumElem();

            while(indice2<=num2)
            {
                if(Buscar(L1, L2.Recuperar(indice2)))
                {
                    L3.Insertar(L2.Recuperar(indice2), indice3);
                    ++indice3;
                }
                ++indice2;
            }
        }

        void EliminarL2deL1(ListaIndexadaLSE& L1, ListaIndexadaLSE L2)
        {
            int indice1=1, indice2=1, aux, num1=L1.NumElem(), num2=L2.NumElem();

            while(indice1<=num1 && indice2<=num2)
            {
                if(L1.Recuperar(indice1)==L2.Recuperar(indice2))
                {
                    aux=indice1;
//                    ++indice1;
                    ++indice2;
                    L1.Borrar(aux);
                }
                else
                    if(L2.Recuperar(indice2)<L1.Recuperar(indice1))
                        ++indice2;
                    else
                        if(L2.Recuperar(indice2)>L1.Recuperar(indice1))
                        ++indice1;
            }
        }

        void EliminarL2deL1SinOrd(ListaIndexadaLSE& L1, ListaIndexadaLSE L2)
        {
            int indice=1, num1=L1.NumElem(), aux;
            while(indice<=num1)
            {
                if(Buscar(L2, L1.Recuperar(indice)))
                {
                    aux=indice;
                    L1.Borrar(aux);
                }
                else
                    ++indice;
            }
        }



        AlgoritmosLIndex(){}
        virtual ~AlgoritmosLIndex(){}

    protected:

    private:
};

#endif // ALGORITMOSLINDEX_H
