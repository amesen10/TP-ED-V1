#ifndef CAJAD_H
#define CAJAD_H


/** @brief Plantilla que crea una caja para una ED Lista Doblemente Enlazada
*/

template <class T> class CajaD
{
    public:
        T elemento;
        CajaD<T>* ptrNext;
        CajaD<T>* ptrPrev;
        CajaD();
        CajaD(T elemento);
        CajaD(T elemento, CajaD<T>* next , CajaD<T>* prev);
        virtual ~CajaD();

    protected:

    private:
};

template <class T> CajaD<T>::CajaD()
{
}

template <class T> CajaD<T>::~CajaD()
{
}

template <class T> CajaD<T>::CajaD(T elemento)
:elemento(elemento),
ptrNext(nullptr),
ptrPrev(nullptr)
{
}

template <class T> CajaD<T>::CajaD(T elemento, CajaD<T>* next, CajaD<T>* prev)
:elemento(elemento),
ptrNext(next),
ptrPrev(prev)
{
}

#endif // CAJAD_H
