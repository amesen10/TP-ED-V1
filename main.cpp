#include <iostream>
#include <stdlib.h>
#include <time.h>
#include "Algoritmos.h"
#include "ListaPosicionadaLSE.h"
#include "ListaPosicionadaLDE.h"
#include "ListaIndexadaLSE.h"
#include "ListaOrd_LSE.h"
#include "ListaOrd_Array.h"

using namespace std;

int main()
{
    ListaPosicionadaLSE l;
    l.Iniciar();
    l.Insertar(5,l.Primera());
    l.Insertar(8, l.Siguiente(l.Primera()));
    l.AgregarAlFinal(35);
    l.AgregarAlFinal(29);
    l.AgregarAlFinal(7);
    l.AgregarAlFinal(25);
    l.AgregarAlFinal(15);
    l.AgregarAlFinal(-9);

    ListaPosicionadaLSE lp;
    lp.Iniciar();
    lp.Insertar(25, lp.Primera());
    lp.AgregarAlFinal(-1);
    lp.AgregarAlFinal(2);
    lp.AgregarAlFinal(15);
    lp.AgregarAlFinal(22);
    lp.AgregarAlFinal(9);
    lp.AgregarAlFinal(7);
    lp.AgregarAlFinal(8);

    ListaPosicionadaLSE lp2;
    lp2.Iniciar();
    lp2.Insertar(1, lp2.Primera());
    lp2.AgregarAlFinal(9);
    //lp2.AgregarAlFinal(9);
    //lp2.AgregarAlFinal(1);
    //lp2.AgregarAlFinal(5);

    cout<<"L= "; l.imprimir();
    Algoritmos<int> a;
    a.invertir(l);
    cout<<endl<<"\nL= "; a.Listar(l);
    cout<<endl<<"\nLp= "; a.Listar(lp);

    if(a.Simetrica(lp))
        cout<<"\nEs simetrica";
    else
        cout<<"\nNo simetrica";

    //a.EliminarRepetidos(lp);
    //cout<<endl<<"\nLp= "; a.Listar(lp);

    cout<<endl<<"\nLp= "; a.Listar(lp);
    cout<<endl<<"\nLp2= "; a.Listar(lp2);
    if(a.DosListasIguales(lp, lp2))
        cout<<"\nSon iguales";
    else
        cout<<"\nNo son iguales";

        if(a.BuscarElem(l, 167))
        cout<<"\nSi esta";
    else
        cout<<"\nNo esta";

        a.invertir(l);
        if(a.Sublista(lp, lp2))
        cout<<"\nSi es sub";
    else
        cout<<"\nNo es sub";
        //a.SeleccionIterativa(l);
        cout<<"L= "; l.imprimir();

    ListaPosicionadaLSE lp1;
    lp1.Iniciar();
    lp.AgregarAlFinal(22);
//    lp1.Insertar(25, lp1.Primera());
    lp1.AgregarAlFinal(-1);
    //lp1.AgregarAlFinal(2);
    lp1.AgregarAlFinal(15);
    lp1.AgregarAlFinal(7);
    lp1.AgregarAlFinal(25);

    ListaPosicionadaLSE lp3;
    lp3.Iniciar();
//    a.SeleccionIterativa(lp);
//    a.BurbujaBi(lp);
//    a.BurbujaBi(l);
//    a.SeleccionRe(lp,lp.Primera());
//    a.SeleccionRe(l, l.Primera());
    a.Insercion(lp);
    a.BurbujaBi(l);
    a.BurbujaBi(lp1);
    cout<<"\nL = "; a.Listar(l);
    cout<<"\nLp = "; a.Listar(lp);
    cout<<"\nLp1 = "; a.Listar(lp1);
    cout<<"\n\nEliminarL2deL1";
    a.EliminarL2deL1(lp,lp1);
    cout<<"\nLp = "; a.Listar(lp);
//    cout<<"\n\nInterseccion";
//    a.Interseccion(l,lp1,lp3);
//    cout<<"\nLp3 = "; a.Listar(lp3);
//    cout<<"\n\nUnion";
//    a.Union(lp,l);
//    cout<<"\nLp = "; a.Listar(lp);

cout<<"\n Prueba Ale: \n";

    ListaPosicionadaLSE lt;
    lt.Iniciar();
    lt.AgregarAlFinal(22);
//    lp1.Insertar(25, lp1.Primera());
    lt.AgregarAlFinal(1);
    //lp1.AgregarAlFinal(2);
    lt.AgregarAlFinal(15);
    lt.AgregarAlFinal(7);
    lt.AgregarAlFinal(5);
    lt.AgregarAlFinal(10);
    lt.AgregarAlFinal(18);
    lt.AgregarAlFinal(30);
    CajaS<int> *x;
    CajaS<int> *y;
    x=lt.Primera();
    y=lt.Ultima();
    a.QuickSortAho(lt, x, y);

    cout<<"\n Lista: "<<endl;
    lt.imprimir();
    return 0;
}
