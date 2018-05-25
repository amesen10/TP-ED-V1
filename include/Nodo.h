#ifndef NODO_H
#define NODO_H

template<class A>
class Nodo
{
    public:
        A dato;
        Nodo *ptrSig;
        /**
        * @brief Contructor para nodo vacio
        * @param no recibe parametros
        * @return contructor
        */
        Nodo(){

        }
        /**
        * @brief Contructor para nodo que recibe un dato
        * @param elem: elemento a guardar
        * @return constructor
        */
        Nodo(A elem){
            dato=elem;
            ptrSig=nullptr;
        }
        virtual ~Nodo(){
            delete this;
        }

    protected:

    private:
};



#endif // NODO_H
