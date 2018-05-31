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

    L.Iniciar();

    for(long long int i=0; i<5000; ++i)
    {
//        L.AgregarAlFinal(rand()%1000);
//        L.AgregarAlFinal(i);
        L.AgregarAlFinal(90987);
    }
    t = clock();
    //Burbuja Bidireccional largo
//    a.BurbujaBi(L);     // con 5000 random 667.167 s
//    a.BurbujaBi(L);     //con 5000 ordenados 0.25 s
//    a.BurbujaBi(L);     //con 5000 iguales 0.25 s

//    a.Burbuja(L);       // con 5000 random 598.975 s
//    a.Burbuja(L);       //con 5000 ordenados 0.261 s
    a.Burbuja(L);       ////con 5000 iguales 0.267 s

    t = clock() - t;
    a.Listar(L);
    cout<<endl<<"Duracion: "<<((float)t)/CLOCKS_PER_SEC<<" s";
    return 0;
}
