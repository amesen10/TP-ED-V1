#ifndef CAJAS_H
#define CAJAS_H

/** @brief Plantilla que crea una caja para una ED Lista SimplementeEnlazada
*/


template <class T> class CajaS
{
    public:
        T elemento;
        CajaS *ptrNext;

        CajaS();
        virtual ~CajaS();
        CajaS(T elemento);
        CajaS(T elemento, CajaS<T>* next);

    protected:

    private:
};

template <class T> CajaS<T>::CajaS()
{
}

template <class T> CajaS<T>::~CajaS()
{
}

template <class T> CajaS<T>::CajaS(T elemento)
:elemento(elemento),
ptrNext(nullptr)
{
}

template <class T> CajaS<T>::CajaS(T elemento, CajaS<T>* next)
:elemento(elemento),
ptrNext(next)
{
}

#endif // CAJAS_H
