#include <fstream>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include "ListaSimple.h"
using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char** argv) {
	struct informacion dato;
	struct nodo *punta;
	int op,i=1;
	punta = crearLista();
	insertardesdeArchivo(punta);
	//mostrarLista(punta);
	cout<<"MENU\n";
	while(i)
	{
		cout<<"\n1) MOSTRAR NUMERO DE VECES QUE SE REPITE UN NUMERO";
		cout<<"\n2) INTERCAMBIAR INFORMACION DE DOS NODOS (NO FUI CAPAZ :( ))";
		cout<<"\n3) SALIR";
		cout<<"\n4) MOSTRAR LISTA";
		cout<<"\nINGRESE UNA OPCION: ";cin>>op;
		
		switch(op)
		{
			case 1: contador(punta);
					break;
			case 2: mostrarLista(punta);
					intercambio(punta);
					break;
			case 4: mostrarLista(punta);
					break;	
		}
	}

//	mostrarLista(punta);
	system("pause");
	return 0;
}
