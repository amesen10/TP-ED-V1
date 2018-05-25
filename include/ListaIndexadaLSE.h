/** @brief Clase que contiene los operadores básicos del modelo lista indexada implementada con la ED Lista SimplementeEnlazada
*/

#ifndef LISTAINDEXADALSE_H
#define LISTAINDEXADALSE_H
#include "CajaS.h"

typedef int Elemento;

class ListaIndexadaLSE
{
    public:
        CajaS<Elemento>* inicio;

        ListaIndexadaLSE();
        virtual ~ListaIndexadaLSE();

        void Iniciar();
        void Destruir();
        void Vaciar();
        bool Vacia();
        void Insertar(Elemento elemento, int pos);
        void Borrar(int pos);
        Elemento Recuperar(int pos);
        void Modificar(Elemento elemento, int pos);
        void Intercambiar(int pos1, int pos2);
        int NumElem();
        void imprimir();
    protected:

    private:
};

/**
* @brief Constructor de la clase.
* @param No recibe parámetros.
*/
ListaIndexadaLSE::ListaIndexadaLSE()
{

}

/**
* @brief Destructor de la clase.
* @param No recibe parámetros.
*/
ListaIndexadaLSE::~ListaIndexadaLSE()
{
    //dtor
}

/**
* @brief Inicializa la Lista
* @param No recibie parámetros
* @return void
*/
void ListaIndexadaLSE::Iniciar()
{
    inicio=nullptr;
    //std::cout<<"se Inicializ[o la ListaIndexadaLSE"<<std::endl;
}

/**
* @brief Destuye la Lista
* @param No recibe parámetros
* @return void
*/
void ListaIndexadaLSE::Destruir()
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
* @param No recibe parámetros
* @return void
*/
void ListaIndexadaLSE::Vaciar()
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
* @param No recibe parámetros
* @return True si está vacía y false si tiene al menos un elemento
*/
bool ListaIndexadaLSE::Vacia()
{
    //std::cout<<"entra al Vacia() de la clase LSE"<<std::endl;
    if(inicio != nullptr)
        return false;
    return true;
}

/**
* @brief Inserta el elemento en la índice de la Lista, recibidos como parámetros
* @param elemento Contiene el dato de tipo Elemento por ser insertado en la Lista
* @param pos Entero con el índice donde se debe insertar el nuevo elemento
* @return void
*/
void ListaIndexadaLSE::Insertar(Elemento elemento, int pos)
{
    int conta=1;
    if(nullptr==inicio)
    {
        CajaS<Elemento> *caja=new CajaS<Elemento>(elemento);
        inicio=caja;
    }
    else
        if(pos==1)
        {
            CajaS<Elemento> *caja=new CajaS<Elemento>(elemento,inicio);
            inicio=caja;
        }
        else
        {
            CajaS<Elemento>* next=inicio;
            while(next->ptrNext != nullptr)
            {
                ++conta;
                if(pos==conta)
                {
                    CajaS<Elemento> *caja=new CajaS<Elemento>(elemento, next->ptrNext);
                    next->ptrNext=caja;
                    break;
                }
                next = next->ptrNext;
            }
            //Condicion para agregar al fnal de la lista
            if(next->ptrNext == nullptr&&conta==pos-1)
            {
                CajaS<Elemento> *caja=new CajaS<Elemento>(elemento, next->ptrNext);
                next->ptrNext=caja;
            }
        }
}

/**
* @brief Borra la "caja" indexada al parametro recibido
* @param pos Contiene el índice por ser borrada de la Lista
* @return void
*/
void ListaIndexadaLSE::Borrar(int pos)
{
    int conta=1;
    if(pos==1)
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
            if(conta==pos-1)
            {
                CajaS<Elemento> *tmp=next->ptrNext;
                next->ptrNext=next->ptrNext->ptrNext;
                delete tmp;
                break;
            }
            else
            {
                next = next->ptrNext;
                ++conta;
            }
        }
    }
}

/**
* @brief Devuelve el dato en el índice especificado
* @param pos Entero con el índice del cual se quiere conocer el contenido
* @return Tipo elemento
*/
Elemento ListaIndexadaLSE::Recuperar(int pos)
{
    int conta=1;
    CajaS<Elemento> *ptr=inicio;
    while(ptr != nullptr )
    {
        if(conta==pos)
        {
            return ptr->elemento;
        }
        else
        {
            ptr = ptr->ptrNext;
            ++conta;
        }
    }
}

/**
* @brief Actualiza el dato de la posición(índice) especificada
* @param elemento Contiene el nuevo dato para actualizar el que había
* @param pos Entero con el índice del cual se quiere modificar el contenido
* @return void
*/
void ListaIndexadaLSE::Modificar(Elemento elemento, int pos)
{
    int conta=1;
    CajaS<Elemento> *ptr=inicio;
    while(ptr != nullptr )
    {
        if(conta==pos)
        {
            ptr->elemento=elemento;
            break;
        }
        else
        {
            ptr = ptr->ptrNext;
            ++conta;
        }
    }

}

/**
* @brief Imprime todos los elementos de la lista
* @param No recibe parámetros
* @return void
*/
void ListaIndexadaLSE::imprimir()
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
* @brief Intercambia los datos de los índices dados en la Lista
* @param pos1 Entero con el índice que se quiere intercambiar el dato
* @param pos2 Entero con el índice que se quiere intercambiar el dato
* @return void
*/
void ListaIndexadaLSE::Intercambiar(int pos1, int pos2)
{
    CajaS<Elemento> *ptr1=inicio;
    CajaS<Elemento> *ptr2=inicio;
    int conta1=1;
    int conta2=1;
    while(ptr1!=nullptr && ptr2!=nullptr)
    {
        if(conta1!=pos1)
        {
            ptr1=ptr1->ptrNext;
            ++conta1;
        }
        if(conta2!=pos2)
        {
            ptr2=ptr2->ptrNext;
            ++conta2;
        }

        if(conta1==pos1 && conta2==pos2)
        {
            Elemento tmp=ptr1->elemento;
            ptr1->elemento=ptr2->elemento;
            ptr2->elemento=tmp;
            break;
        }
    }
}

/**
* @brief Devuelve el número de índices que tiene la Lista
* @param No recibe parámetros
* @return integer con la cantidad de posciones contadas
*/
int ListaIndexadaLSE::NumElem()
{
    int conta=0;
    CajaS<Elemento> *ptr=inicio;
    while(ptr != nullptr )
    {
        ++conta;
        ptr=ptr->ptrNext;
    }
    return conta;
}


#endif // LISTAINDEXADALSE_H
