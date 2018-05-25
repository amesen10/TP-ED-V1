#ifndef NODOL_H
#define NODOL_H

template<class A>
class NodoL
{
    public:
        A elemento;
        NodoL *ptrSig;
        /**
        * @brief Constructor para el nodo con elemento
        * @param dato: elemento a ser almacenado
        * @return constructor
        */
        NodoL(A dat){
            elemento=dat;
            ptrSig=nullptr;
        }
        /**
        * @brief Constructor para el nodo vacio
        * @param no recibe parametros
        * @return constructor
        */
        NodoL(){

        }
        virtual ~NodoL(){

        }

    protected:

    private:
};

#endif // NODOL_H
