#include <fstream>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct informacion
{
	int x;
	int y;
};

struct nodo
{
	struct informacion info;
	struct nodo *sgte = NULL;
};

struct nodo *crearLista()
{
	struct nodo *punta;
	punta = new(struct nodo);
	punta->sgte = NULL;
	punta->info.x = 0;
	punta->info.y = 0;
	return punta;
}

void insertar(struct nodo *punta, struct informacion dato)
{
	struct nodo *nuevo,*aux;
	nuevo = new(struct nodo);
	nuevo->info = dato;
	nuevo->sgte = NULL;
	
	aux = punta;
	while(aux->sgte != NULL)
	{
		aux = aux->sgte;
	}
	aux->sgte = nuevo;

}


void insertardesdeArchivo(struct nodo *punta){
	struct informacion dato;
	char nombreArc[30];
    //cout<<"INGRESE EL NOMBRE DEL ARCHIVO CON EXTENSION .txt: ";
   // cin>>nombreArc;
    ifstream archivo;
    archivo.open("ValoresX-Y.txt", ios::in|ios::out|ios::app);
	if (archivo.is_open()){
		cout<<"ARCHIVO CARGADO CORRECTAMENTE";
		while (!archivo.eof()){
			archivo>>dato.x>>dato.y;
			insertar(punta,dato); 			
		}
		archivo.close();	
	
	}
	else {

	    cout<<" EL ARCHIVO NO HA SIDO ENCONTRADO "<<endl;
	}

}

void contador(struct nodo *punta)
{
	int contx = 1,num,i=0,j=0;
	int vector[5],vector1[5],vectorM[10];
	struct nodo *aux,*aux1;
	aux = punta;
	
		while(aux != NULL)
		{
			vector[i] = aux->info.x;
			vector1[i] = aux->info.y;
			aux = aux->sgte;
			i++;
		}
		cout<<"\n";		
		for(i=0;i<5;i++)
		{
			vectorM[i] = vector[i];
		}
		for(i=5;i<10;i++)
		{
			vectorM[i] = vector1[i-5];
		}
		cout<<"\n"<<"PASE LOS DATOS DE LA LISTA A UN VECTOR Y QUEDA ASI:\n ";
		for(i=0;i<10;i++)
		{
			cout<<vectorM[i]<<"\t";	
		}
		
	for(i=1;i<10;i++)
	{
		contx = 0;
		for(j=1;j<10;j++)
		{
			if(vectorM[i] == vectorM[j])
			{	
				contx++;
				num = vectorM[i];	
			}	
		}	
		cout<<"\nEL NUMERO "<<num<<" SE REPITE "<<contx<<" VECES";	
	}	
}

void intercambio(struct nodo *punta)
{
	struct nodo *aux,*aux1;
	struct informacion datos;
	int pos1,pos2,i=0,j=0;
	cout<<"\nINGRESE LAS POSIOCIONES A INTERCAMBIAR SEPARADAS POR UN ESPACIO: "; cin>>pos1;
	cout<<"\nINGRESE LAS POSIOCIONES A INTERCAMBIAR SEPARADAS POR UN ESPACIO: "; cin>>pos2;
	aux = punta;

	for(i=1;i<pos1;i++)
	{	
		aux1 = aux->sgte;
		for(j=1;j<pos2;i++)
		{
			if(pos1 == i and pos2 == j)
			{
				datos = aux1->info;
				aux1->info = aux->info;
				aux->info = datos;
			}
			aux1 = aux1->sgte;
		}
		aux = aux->sgte;
	}
	
}

void mostrarLista(struct nodo *punta)
{
	struct nodo *aux;
	int i=1;
	
	aux = punta;
	
	while(aux != NULL)
	{
		cout<<"\n";
		cout<<i<<") "<<aux->info.x<<"\t"<<aux->info.y;
		aux = aux->sgte;
		i++;
	}
//	system("pause");
}
