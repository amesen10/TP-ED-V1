#ifndef LISTAORD_ARRAY_H
#define LISTAORD_ARRAY_H
#include <iostream>

using namespace std;
template<class A>
class ListaOrd_Array
{
    public:
        A *arreglo;
        int ultimoLleno;

        ListaOrd_Array(){

        }
        virtual ~ListaOrd_Array(){

        }

        void Iniciar(int tamano){
            arreglo=new A[tamano];
            for(int x=0;x<tamano;x++){
                arreglo[x]=0;
            }
            ultimoLleno=-1;
        }

        void Destruir(){
            delete arreglo;
            ultimoLleno=-1;
        }

        void Vaciar(){
            ultimoLleno=-1;
        }

        bool Vacia(){
            if(ultimoLleno==-1){
                return true;
            }
            return false;
        }

        A Primero(){
            return arreglo[0];
        }

        A Ultimo(){
            if(ultimoLleno==-1){
                return -1;
            }
            return arreglo[ultimoLleno];
        }

        A Siguiente(A elemento){
            for(int x=0;x<=ultimoLleno;x++){
                if(arreglo[x]==elemento && x!=ultimoLleno){
                    return arreglo[x+1];
                }else if(arreglo[x]==elemento && x==ultimoLleno){
                    return -1;
                }
            }
        }

        A Anterior(A elemento){
            for(int x=0;x<=ultimoLleno;x++){
                if(arreglo[x]==elemento && x!=0){
                    return arreglo[x-1];
                }else if(arreglo[x]==elemento && x==0){
                    return -1;
                }
            }
        }

        int NumElem(){
            return ultimoLleno+1;
        }

        void Insertar(A dato){
            if(ultimoLleno==-1){
                ultimoLleno++;
                arreglo[ultimoLleno]=dato;
            }else{
                if(arreglo[0]>dato){
                    ultimoLleno++;
                    A temp1, temp2;
                    for(int x=0;x<=ultimoLleno;x++){
                        if(x==0){
                            temp1=arreglo[x];
                            arreglo[x]=dato;
                        }else{
                            temp2=arreglo[x];
                            arreglo[x]=temp1;
                            temp1=temp2;
                        }
                    }
                }else{
                    bool insertado=false;
                    int contador=0;
                    while(contador<=ultimoLleno && !insertado){
                        if((contador+1<=ultimoLleno)){
                            if((arreglo[contador]<dato) && (arreglo[contador+1]>dato)){
                                ultimoLleno++;
                                insertado=true;
                                A temp1, temp2;
                                for(int x=contador;x<=ultimoLleno;x++){
                                    if(x==contador){
                                        temp1=arreglo[x+1];
                                        arreglo[x+1]=dato;
                                    }else{
                                        temp2=arreglo[x+1];
                                        arreglo[x+1]=temp1;
                                        temp1=temp2;
                                    }
                                }
                            }else if(dato>ultimoLleno){
                                ultimoLleno++;
                                arreglo[ultimoLleno]=dato;
                                insertado=true;
                            }
                        }
                        contador++;
                    }
                }
            }
        }

        void Borrar(A dato){
            bool encontrado=false;
            for(int x=0;x<=ultimoLleno;x++){
                if(arreglo[x]==dato){
                    encontrado=true;
                }
                if(encontrado){
                    if(x==ultimoLleno){
                        arreglo[x]=0;
                    }else{
                        arreglo[x]=arreglo[x+1];
                    }
                }
            }
            ultimoLleno--;
        }

        void Imprimir(){
            cout<<"Lista: "<<endl;
            for(int x=0;x<=ultimoLleno;x++){
                cout<<arreglo[x]<<" ";
            }
            cout<<endl;
        }
    protected:

    private:
};

#endif // LISTAORD_ARRAY_H
