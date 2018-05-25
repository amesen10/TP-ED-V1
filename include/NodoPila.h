#ifndef NODO_H
#define NODO_H

template<class A>
class Nodo
{
    public:
        A dato;
        Nodo *ptrNext;
        Nodo();
        Nodo(A);
        virtual ~Nodo();

    protected:

    private:
};

#endif // NODOPILA_H
