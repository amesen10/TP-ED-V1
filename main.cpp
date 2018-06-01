#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Algoritmos.h"
#include "Pila.h"
#include "ListaPosicionadaLSE.h"
#include "ListaPosicionadaLDE.h"
#include "ListaIndexadaLSE.h"
#include "ListaOrd_LSE.h"
#include "ListaOrd_Array.h"
#include "AlgoritmosLIndex.h"
#include "AlgoritmosListOrd.h"

#include <stdio.h>      /* printf */
#include <time.h>       /* clock_t, clock, CLOCKS_PER_SEC */
#include <math.h>       /* sqrt */

using namespace std;


int main()
{
    ListaPosicionadaLSE L;
    Algoritmos<int> a;
    clock_t t;
    double prom=0;
    srand(time(NULL));

//////////////    ListaOrd_LSE<int> Lo;
//////////////    AlgoritmosListOrd<int> ao;
//////////////
//////////////    Lo.Iniciar();
//////////////    Lo.Insertar(7);
//////////////    Lo.Insertar(7-9);
//////////////    Lo.Insertar(-7);
//////////////    Lo.Insertar(536);
//////////////
//////////////
//////////////    ListaOrd_LSE<int> Lo1;
//////////////    Lo1.Iniciar();
////////////////    Lo.Insertar(2);
////////////////    Lo.Insertar(7);
//////////////    ao.Copiar(Lo1, Lo);//?cout<<"Listo":cout<<"No";
//////////////
//////////////
//////////////    //Copiar: bien; Pertenece: solo quitar A, funciona bien;  Contenida: solo tira "NO"

//////////////////////    cout<<endl;
    L.Iniciar();
//    L.AgregarAlFinal()

//    for(long long int i=0; i<5000; ++i)
//    {
////        L.AgregarAlFinal(rand()%1000);
////        L.AgregarAlFinal(i);
//        L.AgregarAlFinal(90987);
//    }
    for(int x=1;x<=10;x++){
        for(long long int i=0; i<5000; ++i)
        {
            L.AgregarAlFinal(rand()%1000);    //RANDOM
//            L.AgregarAlFinal(i);              //ORDENADA
//            L.AgregarAlFinal(90987);        //CONSTANTE
        }
        t = clock();

        //Burbuja Bidireccional max
        //a.BurbujaBi(L);     // con 5000 random 667.167 s
        //    a.BurbujaBi(L);     //con 5000 ordenados 0.25 s
        a.BurbujaBi(L);     //con 5000 iguales 0.25 s

        //Burbuja original max
        //    a.Burbuja(L);       // con 5000 random 598.975 s
        //    a.Burbuja(L);       //con 5000 ordenados 0.261 s
        //    a.Burbuja(L);       ////con 5000 iguales 0.267 s

        t = clock() - t;
        cout<<endl<<"Duracion "<<x<<": "<<((float)t)/CLOCKS_PER_SEC<<" s"<<endl;
        prom+=((float)t)/CLOCKS_PER_SEC;
        L.Vaciar();
    }
        cout<<"Promedio de pruebas: "<<(prom/10.0)<<" s."<<endl;
    return 0;
}
