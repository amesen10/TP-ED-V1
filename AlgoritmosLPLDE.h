#ifndef ALGORITMOSLPLDE_H
#define ALGORITMOSLPLDE_H
#include "ListaPosicionadaLDE.h"
#include "CajaD.h"

template <class A>class AlgoritmosLPLDE
{
    public:

        void Burbuja(ListaPosicionadaLDE Lista)
        {
            CajaD<A> *ptrI;
            CajaD<A> *fin=Lista.Ultima();
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

        void BurbujaBi(ListaPosicionadaLDE Lista)
        {
            CajaD<A> *ptrI;
            CajaD<A> *ptrD;
            CajaD<A> *inicio=Lista.Primera();
            CajaD<A> *fin=Lista.Ultima();
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

        AlgoritmosLPLDE(){}
        virtual ~AlgoritmosLPLDE(){}
    protected:
    private:
};

#endif // ALGORITMOSLPLDE_H
