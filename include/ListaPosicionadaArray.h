#ifndef LISTAPOSICIONADAARRAY_H
#define LISTAPOSICIONADAARRAY_H

template<class T> class ListaPosicionadaArray
{
    public:
        T *arreglo;
        int ultimoLleno;

        ListaPosicionadaArray();
        virtual ~ListaPosicionadaArray();

        //Operadores Basicos
        void Iniciar(size_t);
        void Destruir();
        bool Vacia()const;
        void Vaciar();
        int Primera()const;
        int Ultima()const;
        int Siguiente(int)const;
        int Anterior(int)const;
        void Insertar(T, int);
        void AgregarAlFinal(T);
        void Borrar(int);
        void Modificar(const T, const int);
        void Intercambiar(const int, const int);
        int NumElem()const;
        T Recuperar(int)const;

        void Imprimir()const;

    protected:

    private:
};

//template <class T> CajaS<T>
template<class T> ListaPosicionadaArray<T>::ListaPosicionadaArray()
{
    //ctor
}

template<class T> ListaPosicionadaArray<T>::~ListaPosicionadaArray()
{
    //dtor
}

/**
* @brief Crea un arreglo de Tipo T, el cual es referenciado por arreglo
* @param m Entero con la cantidad m�xima del arreglo
* @return void
*/
template<class T> void ListaPosicionadaArray<T>::Iniciar(const size_t m)
{
    //std::cout<<"Tamano:"<<m;
    arreglo = new T[m];
    ultimoLleno=-1;
}

/**
* @brief Destruye el arreglo de Tipo T referenciado por arreglo y el se�alador al �ltimo lleno
* @param No recibe nada
* @return void
*/
template<class T> void ListaPosicionadaArray<T>::Destruir()
{
    delete[] arreglo;
}

/**
* @brief Pregunta si el arreglo tiene al menos un elemento
* @param No recibe nada
* @return True si el arreglo est� vac�o; false si el arreglo tiene al menos un elemento
*/
template<class T> bool ListaPosicionadaArray<T>::Vacia()const
{
    if(ultimoLleno!=-1)
        return false;
    return true;
}

/**
* @brief Cambia ultima posicion llena a 0, el vaciado se da solo l�gicamente, no f�sicamente
* @param No recibe nada
* @return void
*/
template<class T> void ListaPosicionadaArray<T>::Vaciar()
{
    ultimoLleno=-1;
}

/**
* @brief Inserta el elemento recibido como par�metro en la posici�n especificada
* @param elemento De tipo T que contiene el elemento por ser insertado
* @param pos Contiene el �ndice correspondiente a la posici�n donde se debe alojar
* @return void
*/
template<class T> void ListaPosicionadaArray<T>::Insertar(T elemento, int pos)
{
    T tmp;
    int iter=pos-1;
    ++ultimoLleno;
    for(iter;iter<=ultimoLleno; ++iter)
    {
        tmp=arreglo[iter];
        arreglo[iter]=elemento;
        elemento=tmp;
    }
}

/**
* @brief Agrega el elemento recibido como par�metro en el �ltima posici�n del arreglo
* @param elemento de tipo T, el cual continene el elemento por ser insertado en el arreglo
* @return void
*/
template<class T> void ListaPosicionadaArray<T>::AgregarAlFinal(T elemento)
{
    ++ultimoLleno;
    arreglo[ultimoLleno]=elemento;
}

/**
* @brief Borra el elemento recibido como par�metro en la posici�n especificada
* @param pos Contiene el �ndice correspondiente a la posici�n que debe ser borrada
* @return void
*/
template<class T> void ListaPosicionadaArray<T>::Borrar(int pos)
{
    for(int iter=pos-1; iter<=ultimoLleno; ++iter)
    {
        arreglo[iter]=arreglo[iter+1];
    }
    --ultimoLleno;
}

/**
* @brief Actualiza el elemento de la posici�n recibida como par�metro
* @param elemento de tipo T que contiene el nuevo dato
* @param pos Contiene la posici�n indexada al elemento por actualizar
* @return void
*/
template<class T> void ListaPosicionadaArray<T>::Modificar(const T elemento, const int pos)
{
    arreglo[pos-1]=elemento;
}

/**
* @brief Intercambia los elementos entre las dos posiciones dadas
* @param pos1 Contiene la posici�n de uno de los elementos por intercambiar
* @param pos2 Contiene la otra posici�n del otro elemento por intercambiar
* @return void
*/
template<class T> void ListaPosicionadaArray<T>::Intercambiar(const int pos1, const int pos2)
{
    T tmp=arreglo[pos1-1];
    arreglo[pos1-1]=arreglo[pos2-1];
    arreglo[pos2-1]=tmp;
}

/**
* @brief Obtiene el elemento de la i-�sima posici�n
* @param pos Entero con el �ndice de la posici�n de la cual se quiere conocer el elemento asociado
* @return void
*/
template<class T> T ListaPosicionadaArray<T>::Recuperar(int pos)const
{
    return arreglo[pos-1];
}

/**
* @brief Devuelve la cantidad de elementos/posciones en el arreglo, i.e. n
* @param No recibe nada
* @return void
*/
template<class T> int ListaPosicionadaArray<T>::NumElem()const
{
    return ultimoLleno+1;
}

/**
* @brief Devuelve la primera posici�n v�lida del arreglo
* @param No recibe nada
* @return entero con la posici�n del primer elemento
*/
template<class T> int ListaPosicionadaArray<T>::Primera()const
{
    if(ultimoLleno=!-1)
        return 1;
    return ultimoLleno;
    //return arreglo[0];
}

/**
* @brief Devuelve la �ltima posici�n v�lida del arreglo
* @param No recibe nada
* @return entero con la posici�n del primer elemento
*/
template<class T> int ListaPosicionadaArray<T>::Ultima()const
{
    if(ultimoLleno=!-1)
        return ultimoLleno+1;
    return ultimoLleno;
    //return arreglo[ultimoLleno];
}

/**
* @brief Devuelve la siguiente posici�n a la solicitada
* @param pos Entero que contiene la posici�n
* @return entero con la posici�n siguiente a la recibida
*/
template<class T> int ListaPosicionadaArray<T>::Siguiente(int  pos)const
{
    return arreglo[pos+2];
}

/**
* @brief Devuelve la siguiente posici�n a la solicitada
* @param pos Entero que contiene la posici�n
* @return entero con la posici�n anterior a la recibida
*/
template<class T> int ListaPosicionadaArray<T>::Anterior(int  pos)const
{
    return arreglo[pos-2];
}

/**
* @brief Imprime todos los elementos de la Lista
* @param No recibe nada
* @return void
*/
template<class T> void ListaPosicionadaArray<T>::Imprimir()const
{
    //std::cout<<"UL: "<<ultimoLleno<<"\n";
    for(int conta=0;conta<=ultimoLleno;++conta)
    {
        std::cout<<arreglo[conta]<<"@"<<conta+1<<" ";
    }
}

#endif // LISTAPOSICIONADAARRAY_H
