#include <fstream>
#include <string.h>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>

using namespace std;

struct informacion
{
	string nombre;
	string tipoc;
	int telefono;
};

struct nodo{
       struct informacion info; // en este caso la informacion es una estructura
	   struct nodo *sgte;						    
};

struct nodo *crearLista()

{
	struct nodo *cabeza;
    cabeza = new(struct nodo);
    cabeza->sgte=cabeza;
    cabeza->info.nombre="Soy el Nodo cabecera";
    return cabeza;
}

void insertar(struct nodo *cabeza, struct informacion dato)
{
	struct nodo *nuevo,*aux;
	nuevo = new(struct nodo);
	nuevo->info = dato;
	nuevo->sgte = cabeza;
	
	aux = cabeza->sgte;
	while(aux->sgte != cabeza)
	{
		aux = aux->sgte;
	}
	aux->sgte = nuevo;

}

void insertarOrden(struct nodo *cabeza)
{
	struct informacion dato;
	cout<<"\nINGRESE LOS DATOS DEL CONTACTO (NOMBRE,TIPO DE CONTACTO,TELEFONO): "; cin>>dato.nombre>>dato.tipoc>>dato.telefono;
	insertar(cabeza,dato);
	nodo *aux1,*aux2;
	struct informacion temp;
	aux2 = aux1;
	aux1 = cabeza->sgte;

	
	while(aux1->sgte != cabeza)
	{
		aux2 = aux1->sgte;
		while(aux2 != cabeza)
		{
			if(aux1->info.nombre.compare(aux2->info.nombre)>0)
			{
				temp = aux1->info;
				aux1->info = aux2->info;
				aux2->info = temp;
				break;
			}
			aux2 = aux2->sgte;	
		}
		aux1 = aux1->sgte;
	}
	 
}

void buscarContacto(struct nodo *cabeza)
{
	nodo *aux;
	string buscado;
	aux = cabeza->sgte;
	
	cout<<"\nESCRIBA EL NOMBRE DEL CONTACTO A BUSCAR: "; cin>>buscado;
	
	if(cabeza->sgte != NULL)
	{
		while(aux->sgte != cabeza)
		{
			aux = aux->sgte;
			
			if(aux->info.nombre == buscado)
			{
				cout<<"\nCONTACTO ENCONTRADO: "<<aux->info.nombre<<"\t"<<aux->info.tipoc<<"\t"<<aux->info.telefono;
			}
			else
			{
				cout<<"EL CONTACTO NO ESTA EN LA LISTA";
			}
		}
	}
}

void borrarContacto(struct nodo *cabeza)
{
	nodo *aux,*aux1,*p,*q;
	string eliminado;
	p = cabeza->sgte;
	q = cabeza->sgte;
	cout<<"\nINGRESE EL NOMBRE DEL CONTACTO A ELIMINAR: "; cin>>eliminado;
	
	if(cabeza->sgte != NULL)
	{
		while(p != cabeza)
		{	
			if(cabeza->sgte->info.nombre == eliminado )
			{
				cabeza->sgte = p->sgte;
				delete(p);
			}
			
			if(p->info.nombre == eliminado)
			{
				aux->sgte = p->sgte;
				aux1 = p->sgte;
				delete(p);
			}
			if(p->sgte == cabeza and p->sgte->info.nombre == eliminado)
			{
				q->sgte = cabeza;
				aux1 = q->sgte;
				delete(q);
			}
			else
			{
				aux = p;
				p = p->sgte;
			}
		}
		cout<<"DATO ELIMINADO CORRECTAMENTE";
	}
}

void insertardesdeArchivo(struct nodo *cabeza){
	struct informacion dato;
	char nombreArc[30];
    //cout<<"INGRESE EL NOMBRE DEL ARCHIVO CON EXTENSION .txt: ";
   // cin>>nombreArc;
    ifstream archivo;
    archivo.open("Contactos.txt", ios::in|ios::out|ios::app);
	if (archivo.is_open()){
		cout<<"ARCHIVO CARGADO CORRECTAMENTE";
		while (!archivo.eof()){
			archivo>>dato.nombre>>dato.tipoc>>dato.telefono;
			insertar(cabeza,dato); 			
		}
		archivo.close();	
	
	}
	else {

	    cout<<" EL ARCHIVO NO HA SIDO ENCONTRADO "<<endl;
	}

}


void mostrarLista(struct nodo *cabeza)
{
     int i = 0;
     
 	struct nodo *p;
 	p=cabeza->sgte;
 	
 	if(p==cabeza)
 	{
 		cout<<"LA LISTA ESTA VACIA";
	}
	 
 	cout<<"\n INFORMACION DE LA LISTA\n";
 	
     while(p != cabeza)
     {
		  cout <<' '<< i+1 <<") " << p->info.nombre<<"\t" <<p->info.tipoc<<"\t"<<p->info.telefono;
		  cout<<"\n";
          p = p->sgte;
          i++;
     }
     //system("Pause");
}

void escribir(struct nodo *cabeza)
{
	ofstream archivo;
	struct nodo *p;
	
	p = cabeza->sgte;
	archivo.open("ListaDeContactos(Actualizada).txt",ios_base::out);
	int i = 1;
	if(archivo.fail())
	{
		cout<<"ERROR AL CREAR ARCHIVO";
	}
	
	if(p == cabeza)
	{
		cout<<"LISTA VACIA";
	}
	
	if(archivo.is_open())
	{
		while(p != cabeza)
		{
			archivo<<"\n"<<p->info.nombre<<"\t"<<p->info.tipoc<<"\t"<<p->info.telefono;
			p = p->sgte;
			i++;
		}
		archivo.close();
		cout<<"ARCHIVO CREADO CORRECTAMENTE";
	}
	else 
	{
		cout<<"PROBLEMAS CON EL ARCHIVO";
	}
} 
	


