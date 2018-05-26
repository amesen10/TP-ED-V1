/** @brief Clase que contiene los operadores b�sicos del modelo lista posicionada implementada con la ED Lista Simplemente Enlazada
*/
#ifndef LISTAPOSICIONADALSE_H
#define LISTAPOSICIONADALSE_H
#include "CajaS.h"

typedef int Elemento;
//typedef CajaS<Elemento>* Ptr;

class ListaPosicionadaLSE
{
    public:
        CajaS<Elemento>* inicio;

        ListaPosicionadaLSE();
        virtual ~ListaPosicionadaLSE();

        void Iniciar();
        void Destruir();
        void Vaciar();
        bool Vacia();
        void Insertar(Elemento elemento, CajaS<Elemento>* pos);
        void AgregarAlFinal(Elemento elemento);
        void Borrar(CajaS<Elemento>* pos);
        Elemento Recuperar(CajaS<Elemento>* pos);
        void Modificar(Elemento elemento, CajaS<Elemento>* pos);
        void Intercambiar(CajaS<Elemento>* pos1, CajaS<Elemento>* pos2);
        CajaS<Elemento>* Primera();
        CajaS<Elemento>* Ultima();
        CajaS<Elemento>* Anterior(CajaS<Elemento>* pos);
        CajaS<Elemento>* Siguiente(CajaS<Elemento>* pos);
        int NumElem();
        void imprimir();

    protected:

    private:
};


/**
* @brief Constructor de la clase.
* @param No recibe par�metros.
*/
ListaPosicionadaLSE::ListaPosicionadaLSE()
{

}

/**
* @brief Destructor de la clase.
* @param No recibe par�metros.
*/
ListaPosicionadaLSE::~ListaPosicionadaLSE()
{
    //dtor
}

/**
* @brief Inicializa la Lista
* @param No recibie par�metros
* @return void
*/
void ListaPosicionadaLSE::Iniciar()
{
    inicio=nullptr;
    //std::cout<<"se Inicializ[o la ListaPosicionadaLSE"<<std::endl;
}

/**
* @brief Destuye la Lista
* @param No recibe par�metros
* @return void
*/
void ListaPosicionadaLSE::Destruir()
{
    CajaS<Elemento>* next;
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
* @param No recibe par�metros
* @return void
*/
void ListaPosicionadaLSE::Vaciar()
{
    CajaS<Elemento>* next;
    while(inicio != nullptr)
    {
        next = inicio->ptrNext;
        delete inicio;
        inicio=next;
    }
}

/**
* @brief Verifica si la Lista se encuentra vacia
* @param No recibe par�metros
* @return True si est� vac�a y false si tiene al menos un elemento
*/
bool ListaPosicionadaLSE::Vacia()
{
    //std::cout<<"entra al Vacia() de la clase LSE"<<std::endl;
    if(inicio != nullptr)
        return false;
    return true;
}

/**
* @brief Inserta el elemento en la posici�n de la Lista, recibidos como par�metros
* @param elemento Contiene el dato de tipo Elemento por ser insertado en la Lista
* @param pos Contiene la posici�n donde se debe insertar el nuevo elemento\
* @return void
*/
void ListaPosicionadaLSE::Insertar(Elemento elemento, CajaS<Elemento>* pos)
{
    if(nullptr==inicio)
    {
        CajaS<Elemento> *caja=new CajaS<Elemento>(elemento);
        inicio=caja;
    }
    else
        if(pos==inicio)
        {
            CajaS<Elemento> *caja=new CajaS<Elemento>(elemento,inicio);
            inicio=caja;
        }
    else
    {
        CajaS<Elemento>* next=inicio;
        while(next->ptrNext != pos)
        {
            next = next->ptrNext;
        }
        CajaS<Elemento> *caja=new CajaS<Elemento>(elemento, next->ptrNext);
        next->ptrNext=caja;
    }
}

/**
* @brief Inserta el elemento en la �ltima posici�n de la Lista
* @param elemento Contiene el dato de tipo Elemento por ser insertado en la Lista
* @return void
*/
void ListaPosicionadaLSE::AgregarAlFinal(Elemento elemento)
{
    if(nullptr==inicio)
    {
        CajaS<Elemento> *caja=new CajaS<Elemento>(elemento);
        inicio=caja;
    }
    else
    {
        CajaS<Elemento>* next=inicio;
        while(next->ptrNext != nullptr)
        {
            next = next->ptrNext;
        }
        CajaS<Elemento> *caja=new CajaS<Elemento>(elemento);
        next->ptrNext=caja;
    }


}

/**
* @brief Borra la "caja" de la posici�n en la Lista, recibida como par�metro
* @param pos Contiene la posici�n por ser borrada de la Lista
* @return void
*/
void ListaPosicionadaLSE::Borrar(CajaS<Elemento>* pos)
{
    if(pos==inicio)
    {
        CajaS<Elemento> *tmp=inicio;
        inicio=tmp->ptrNext;
        delete tmp;
    }
    else
    {
        CajaS<Elemento> *next=inicio;
        while(next != nullptr )
        {
            if(next->ptrNext==pos)
            {
                CajaS<Elemento> *tmp=next->ptrNext;
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

/**
* @brief Devuelve la primera posici�n de la Lista
* @param No recibe par�metros
* @return puntero a la primera posici�n
*/
CajaS<Elemento>* ListaPosicionadaLSE::Primera()
{
    return inicio;
}

/**
* @brief Imprime todos los elementos de la lista
* @param No recibe par�metros
* @return void
*/
void ListaPosicionadaLSE::imprimir()
{
    CajaS<Elemento> *ptr=inicio;
    while(ptr!=nullptr)
    {
        std::cout<<ptr->elemento<<" ";
        ptr=ptr->ptrNext;
    }
    //std::cout<<std::endl;
}

/**
* @brief Devuelve el dato de la posici�n especificada
* @param pos Puntero a la posici�n de la cual se requiere el dato
* @return Tipo elemento
*/
Elemento ListaPosicionadaLSE::Recuperar(CajaS<Elemento>* pos)
{
    CajaS<Elemento> *ptr=inicio;
    if(pos==inicio)
        return inicio->elemento;
    while(ptr!=nullptr)
    {
        if(ptr==pos)
            return ptr->elemento;
        //std::cout<<ptr->elemento<<" NO ";
        ptr=ptr->ptrNext;
    }
    //std::cout<<ptr->elemento<<" Si ";
}

/**
* @brief Actualiza el dato de la posici�n especificada
* @param elemento Contiene el nuevo dato para actualizar el que hab�a
* @param pos Puntero a la posici�n de la cual se quiere modificar el dato
* @return void
*/
void ListaPosicionadaLSE::Modificar(Elemento elemento, CajaS<Elemento>* pos)
{
    CajaS<Elemento> *ptr=inicio;
    while(ptr!=nullptr)
    {
        if(ptr==pos)
            ptr->elemento=elemento;
        ptr=ptr->ptrNext;
    }
}

/**
* @brief Intercambia los datos de las posiciones dadas
* @param pos1 Puntero a la posici�n que se quiere intercambiar el dato
* @param pos2 Puntero a la posici�n que se quiere intercambiar el dato
* @return void
*/
void ListaPosicionadaLSE::Intercambiar(CajaS<Elemento>* pos1, CajaS<Elemento>* pos2)
{
    CajaS<Elemento> *ptr1=inicio;
    CajaS<Elemento> *ptr2=inicio;
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
* @brief Devuelve la �ltima posici�n de la Lista
* @param No recibe par�metros
* @return puntero a la �ltima posici�n
*/
CajaS<Elemento>* ListaPosicionadaLSE::Ultima()
{
    CajaS<Elemento>* next=inicio;
    while(next->ptrNext != nullptr)
    {
        next = next->ptrNext;
    }
    return next;
}

/**
* @brief Devuelve la siguiente posici�n a partir de una dada en la Lista
* @param pos Puntero a la posici�n de la cual se quiere concocer el sucesor
* @return Puntero al sucesor
*/
CajaS<Elemento>* ListaPosicionadaLSE::Siguiente(CajaS<Elemento>* pos)
{
    CajaS<Elemento>* next=inicio;

    while(next != nullptr)
    {
        if(pos==next)
            return next->ptrNext;
        next = next->ptrNext;
    }
    return nullptr;
}

/**
* @brief Devuelve la posici�n anterior a partir de una dada en la Lista
* @param pos Puntero a la posici�n de la cual se quiere concocer el predecesor
* @return Puntero al predecesor
*/
CajaS<Elemento>* ListaPosicionadaLSE::Anterior(CajaS<Elemento>* pos)
{
    CajaS<Elemento>* prev=inicio;
    if(pos==inicio->ptrNext)
        return prev;
    else
        while(prev->ptrNext != nullptr)
        {
            if(prev->ptrNext==pos)
                return prev;
            prev = prev->ptrNext;
        }
    return nullptr;
}

/**
* @brief Devuelve el n�mero de posiciones que tiene la Lista
* @param No recibe par�metros
* @return integer con la cantidad de posciones contadas
*/
int ListaPosicionadaLSE::NumElem()
{
    int conta=0;
    CajaS<Elemento> *ptr=inicio;
    while(ptr!= nullptr)
    {
        ++conta;
        ptr=ptr->ptrNext;
    }
    return conta;
}

#endif // LISTAPOSICIONADALSE_H
