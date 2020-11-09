#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <string.h>
#include <stdio.h>
#include "Contactos.h"

using namespace std;

int main(int argc, char** argv) {
	
	struct nodo  *cabeza;
    struct informacion dato;
    cabeza = crearLista();
  	int i,op;
  	insertardesdeArchivo(cabeza);
  	
  	while(i == 0)
  	{
  		cout<<"\n\t\n\t LISTA DE CONTACTOS \n";
  		cout<<"\n";
		cout<<"1)"<<" INSERTAR UN CONTACTO (ORDENADO)\n";
		cout<<"2)"<<" BORRAR UN CONTACTO\n";
		cout<<"3)"<<" BUSCAR UN CONTACTO\n";
		cout<<"4)"<<" MOSTRAR LA LISTA DE CONTACTOS\n";
		cout<<"0)"<<" GUARDAR Y TERMINAR (AL SELECCIONAR ESTA OPCION SE CREARA UN ARCHIVO CON LA LISTA ACTUALIZADA)\n";  
		cout<<"\nINGRESE UNA OPCION: "; cin>>op;
		
		switch(op)
		{
			case 1: cout<<"HA SELCCIONADO INSERTAR UN CONTACTO :)\n";
			cout<<"\nASI ESTABA LA LISTA ANTES DE INSERTAR EL CONTACTO:\n ";
			mostrarLista(cabeza);
			insertarOrden(cabeza);
			cout<<"\nASI QUEDA LA LISTA DESPUES DE INSERTAR EL CONTACTO: \n";
			mostrarLista(cabeza);
			break;
			case 2: cout<<"\nHA SELCCIONADO BORRAR UN CONTACTO :)\n";
			cout<<"\nASI ESTABA LA LISTA ANTES DE BORRAR EL CONTACTO:\n ";
			mostrarLista(cabeza);
			borrarContacto(cabeza);
			cout<<"\nASI QUEDA LA LISTA DESPUES DE BORRAR EL CONTACTO: \n";
			mostrarLista(cabeza);
			break;
			case 3: cout<<"\nHA SELECCIONADO BUSCAR UN CONTACTO :)\n";
			buscarContacto(cabeza);
			break;
			case 4: cout<<"\nHA SELECCIONADO MOSTRAR LA LISTA DE CONTACTOS :)\n";
			mostrarLista(cabeza);
			break;
			case 0: cout<<"\nHA SELECCIONADO TERMINAR :( \n";
			escribir(cabeza);
			i = 1;
			exit(1);				
		}
	}

}
