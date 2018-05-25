#ifndef LISTAPOSICIONADALDE_H
#define LISTAPOSICIONADALDE_H

#include "CajaD.h"

/** @brief Clase que contiene los operadores básicos del modelo lista posicionada implementada con la ED Lista Doblemente Enlazada
*/

typedef int Elemento;

class ListaPosicionadaLDE
{
    public:
        CajaD<Elemento>* inicio;
        CajaD<Elemento>* fin;

        void Iniciar();
        void Destruir();
        void Vaciar();
        bool Vacia();
        void Insertar(Elemento elemento, CajaD<Elemento>* pos);
        void AgregarAlFinal(Elemento elemento);
        void Borrar(CajaD<Elemento>* pos);
        Elemento Recuperar(CajaD<Elemento>* pos);
        void Modificar(Elemento elemento, CajaD<Elemento>* pos);
        void Intercambiar(CajaD<Elemento>* pos1, CajaD<Elemento>* pos2);
        CajaD<Elemento>* Primera();
        CajaD<Elemento>* Ultima();
        CajaD<Elemento>* Anterior(CajaD<Elemento>* pos);
        CajaD<Elemento>* Siguiente(CajaD<Elemento>* pos);
        int NumElem();
        void imprimir();

        ListaPosicionadaLDE();
        virtual ~ListaPosicionadaLDE();

    protected:

    private:
};


/**
* @brief Constructor de la clase.
* @param No recibe parámetros.
*/
ListaPosicionadaLDE::ListaPosicionadaLDE()
{

}

/**
* @brief Destructor de la clase.
* @param No recibe parámetros.
*/
ListaPosicionadaLDE::~ListaPosicionadaLDE()
{
    //dtor
}


/**
* @brief Inicializa la Lista
* @param No recibie parámetros
* @return void
*/
void ListaPosicionadaLDE::Iniciar()
{
    inicio=nullptr;
    fin=nullptr;
    //std::cout<<"se Inicializ[o la ListaPosicionadaLDE"<<std::endl;
}

/**
* @brief Destuye la Lista
* @param No recibe parámetros
* @return void
*/
void ListaPosicionadaLDE::Destruir()
{
    CajaD<Elemento>* next;
    while(inicio != nullptr)
    {
        //std::cout<<"Destruyendo: "<<inicio->elemento<<std::endl;
        next = inicio->ptrNext;
        delete inicio;
        inicio=next;
    }
    delete this;
}

/**
* @brief Borra todas las cajas de la Lista, sin destruirla
* @param No recibe parámetros
* @return void
*/
void ListaPosicionadaLDE::Vaciar()
{
    CajaD<Elemento>* next;
    while(inicio != nullptr)
    {
        next = inicio->ptrNext;
        delete inicio;
        inicio=next;
    }
}

/**
* @brief Verifica si la Lista se encuentra vacia
* @param No recibe parámetros
* @return True si está vacía y false si tiene al menos un elemento
*/
bool ListaPosicionadaLDE::Vacia()
{
    //std::cout<<"entra al Vacia() de la clase LDE"<<std::endl;
    if(inicio != nullptr)
        return false;
    return true;
}

/**
* @brief Inserta el elemento en la posición de la Lista, recibidos como parámetros
* @param elemento Contiene el dato de tipo Elemento por ser insertado en la Lista
* @param pos Contiene la posición donde se debe insertar el nuevo elemento\
* @return void
*/
void ListaPosicionadaLDE::Insertar(Elemento elemento, CajaD<Elemento>* pos)
{
    if(nullptr==inicio)
    {
        CajaD<Elemento> *caja=new CajaD<Elemento>(elemento);
        inicio=caja;
        fin=caja;
    }
    else
        if(pos==inicio)
        {
            CajaD<Elemento> *caja=new CajaD<Elemento>(elemento,inicio,nullptr);
            inicio=caja;
        }
        else
        {
            CajaD<Elemento> *next=inicio;
            while(next->ptrNext != pos)
            {
                next = next->ptrNext;
            }
            CajaD<Elemento> *caja=new CajaD<Elemento>(elemento, next->ptrNext,next);
            next->ptrNext=caja;
        }
}

/**
* @brief Devuelve la primera posición de la Lista
* @param No recibe parámetros
* @return puntero a la primera posición
*/
CajaD<Elemento>* ListaPosicionadaLDE::Primera()
{
    return inicio;
}

/**
* @brief Devuelve la última posición de la Lista
* @param No recibe parámetros
* @return puntero a la última posición
*/
CajaD<Elemento>* ListaPosicionadaLDE::Ultima()
{
    return fin;
}

/**
* @brief Imprime todos los elementos de la lista
* @param No recibe parámetros
* @return void
*/
void ListaPosicionadaLDE::imprimir()
{
    CajaD<Elemento> *ptr=inicio;
    while(ptr!=nullptr)
    {
        std::cout<<ptr->elemento<<" ";
        ptr=ptr->ptrNext;
    }
    //std::cout<<std::endl;
}

/**
* @brief Inserta el elemento en la última posición de la Lista
* @param elemento Contiene el dato de tipo Elementp por ser insertado en la Lista
* @return void
*/
void ListaPosicionadaLDE::AgregarAlFinal(Elemento elemento)
{
    CajaD<Elemento>* ptr=fin;
    CajaD<Elemento> *caja=new CajaD<Elemento>(elemento,nullptr,fin);
    fin->ptrNext=caja;
    fin=caja;
}

/**
* @brief Borra la "caja" de la posición en la Lista, recibida como parámetro
* @param pos Contiene la posición por ser borrada de la Lista
* @return void
*/
void ListaPosicionadaLDE::Borrar(CajaD<Elemento>* pos)
{
    if(pos==inicio)
    {
        CajaD<Elemento> *tmp=inicio;
        inicio=tmp->ptrNext;
        delete tmp;
    }
    else
    {
        if(pos==fin)
        {
            CajaD<Elemento> *tmp=fin;
            fin=fin->ptrPrev;
            fin->ptrNext=nullptr;
            delete tmp;
        }
        else
        {
            CajaD<Elemento> *next=inicio;
            while(next != nullptr )
            {
                if(next->ptrNext==pos)
                {
                    CajaD<Elemento> *tmp=next->ptrNext;
                    next->ptrNext=next->ptrNext->ptrNext;
                    delete tmp;
                    break;
                }
                else
                next = next->ptrNext;
            }

            /*CajaS<Elemento> *caja=new CajaS<Elemento>(next->ptrNext);
            next->ptrNext=caja;*/
        }
    }
}

/**
* @brief Devuelve el dato de la posición especificada
* @param pos Puntero a la posición de la cual se requiere el dato
* @return Tipo elemento
*/
Elemento ListaPosicionadaLDE::Recuperar(CajaD<Elemento>* pos)
{
    CajaD<Elemento> *ptr=inicio;
    if(pos==inicio)
        return inicio->elemento;
    if(pos==fin)
        return fin->elemento;
    while(ptr!=nullptr)
    {
        if(ptr==pos)
            return ptr->elemento;
        //std::cout<<ptr->elemento<<" NO ";
        ptr=ptr->ptrNext;
    }
    //std::cout<<ptr->elemento<<" Si ";
    return ptr->elemento;
}

/**
* @brief Actualiza el dato de la posición especificada
* @param elemento Contiene el nuevo dato para actualizar el que había
* @param pos Puntero a la posición de la cual se quiere modificar el dato
* @return void
*/
void ListaPosicionadaLDE::Modificar(Elemento elemento, CajaD<Elemento>* pos)
{
    CajaD<Elemento> *ptr=inicio;
    if(pos==inicio)
        inicio->elemento=elemento;
    else
        if(pos==fin)
         fin->elemento=elemento;
         else
            while(ptr!=nullptr)
            {
                if(ptr==pos)
                    ptr->elemento=elemento;
                ptr=ptr->ptrNext;
            }
}

/**
* @brief Intercambia los datos de las posiciones dadas
* @param pos1 Puntero a la posición que se quiere intercambiar el dato
* @param pos2 Puntero a la posición que se quiere intercambiar el dato
* @return void
*/
void ListaPosicionadaLDE::Intercambiar(CajaD<Elemento>* pos1, CajaD<Elemento>* pos2)
{
    CajaD<Elemento> *ptr1=inicio;
    CajaD<Elemento> *ptr2=inicio;
    while(ptr1!=nullptr && ptr2!=nullptr)
    {
        if(ptr1!=pos1)
            ptr1=ptr1->ptrNext;
        if(ptr2!=pos2)
            ptr2=ptr2->ptrNext;
        if(ptr1==pos1 && ptr2==pos2)
        {
            Elemento tmp=ptr1->elemento;
            ptr1->elemento=ptr2->elemento;
            ptr2->elemento=tmp;
            break;
        }
    }
}

/**
* @brief Devuelve la siguiente posición a partir de una dada en la Lista
* @param pos Puntero a la posición de la cual se quiere concocer el sucesor
* @return Puntero al sucesor
*/
CajaD<Elemento>* ListaPosicionadaLDE::Siguiente(CajaD<Elemento>* pos)
{
    CajaD<Elemento>* next=inicio;

    while(next != nullptr)
    {
        if(pos==next)
            return next->ptrNext;
        next = next->ptrNext;
    }
    return nullptr;
}

/**
* @brief Devuelve la posición anterior a partir de una dada en la Lista
* @param pos Puntero a la posición de la cual se quiere concocer el predecesor
* @return Puntero al predecesor
*/
CajaD<Elemento>* ListaPosicionadaLDE::Anterior(CajaD<Elemento>* pos)
{
    CajaD<Elemento>* prev=inicio;
    if(pos==inicio->ptrNext)
        return inicio;
    while(prev->ptrNext != nullptr)
    {
        if(prev->ptrNext==pos)
            return prev;
        prev = prev->ptrNext;
    }
    return nullptr;
}

/**
* @brief Devuelve el número de posiciones que tiene la Lista
* @param No recibe parámetros
* @return integer con la cantidad de posciones contadas
*/
int ListaPosicionadaLDE::NumElem()
{
    int conta=0;
    CajaD<Elemento> *ptr=inicio;
    while(ptr!= nullptr)
    {
        ++conta;
        ptr=ptr->ptrNext;
    }
    return conta;
}

#endif // LISTAPOSICIONADALDE_H
