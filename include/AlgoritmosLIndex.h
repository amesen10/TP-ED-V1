#ifndef ALGORITMOSLINDEX_H
#define ALGORITMOSLINDEX_H
#include "ListaIndexadaLSE.h"
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



        AlgoritmosLIndex(){}
        virtual ~AlgoritmosLIndex(){}

    protected:

    private:
};

#endif // ALGORITMOSLINDEX_H
