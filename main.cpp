#include <iostream>
#include <conio.h>
#include <stdio.h>
#include <stdlib.h>
using namespace std;

struct nodo{
int dato;
nodo *siguiente;
};
 nodo *lista=NULL;

void insertarlista(nodo *&,int);
void mostrarlista(nodo *);
void eliminarnodo(nodo *&,int);


void menu();
void ingresar();
void borrar();
void eliminar_lista(nodo *&,int &);
void buscar_elemento(nodo *,int );


 int dato;

int main(int argc, char const *argv[]){
    menu();



    return 0;
}



void insertarlista(nodo *&lista,int n){
nodo *nuevo_nodo=new nodo();
nuevo_nodo->dato=n;
nodo *aux1=lista;
nodo *aux2;

while((aux1 != NULL)&&(aux1->dato<n)){
    aux2=aux1;
    aux1=aux1->siguiente;
    }
    if(lista==aux1){
        lista=nuevo_nodo;
    }else{
        aux2->siguiente=nuevo_nodo;
    }
    nuevo_nodo->siguiente=aux1;
    printf("\n\t\tdato %d isertado con exito\n\n",n);
    system("pause");

}


void mostrarlista(nodo *lista){

nodo *actual =new nodo();
actual = lista;
while(actual!=NULL){
    printf("\t\t\t%d\n",actual->dato);
    actual=actual->siguiente;

    }

    system("pause");
}

void eliminarnodo(nodo *&lista,int n){
if(lista != NULL){
    nodo *aux_borrar;
    nodo *anterior=NULL;
    aux_borrar=lista;

    while((aux_borrar!=NULL)&&(aux_borrar->dato!=n)){
        anterior=aux_borrar;
        aux_borrar=aux_borrar->siguiente;
    }
    if(aux_borrar==NULL){
        printf("\n\t\tel elemento no existe\n");
    }else if(anterior==NULL){
    lista=lista->siguiente;
    printf("\n\t\telemento %d eliminado \n",n);
    delete aux_borrar;
    }else{
    anterior->siguiente=aux_borrar->siguiente;
    printf("\n\t\telemento %d eliminado \n",n);
    delete aux_borrar;
    }
}

system("pause");
}

void menu(){
    int b;
int opc;
do{ system("cls");
    printf("\t\tMENU PRINCIPAL\n");
    printf("\n\t\t1. insertar\n");
    printf("\n\t\t2. mostrar\n");
    printf("\n\t\t3. buscar\n");
    printf("\n\t\t4. borrar elemento\n");
    printf("\n\t\t5. borrar todo\n");
    printf("\n\t\t6. salir\n");
    printf("\n\t\tingrese una opcion: ");
    scanf("%d",&opc);
    switch(opc){
    case 1:ingresar();
        break;
    case 2:mostrarlista(lista);
        break;
    case 3:printf("\n\t\tingrese el numero a buscar: ");
            scanf("%d",&b);
            buscar_elemento(lista,b);
            system("pause");

        break;
    case 4:borrar();
        break;
    case 5:while(lista!=NULL){
            eliminar_lista(lista,dato);
            }
            printf("\n\t\tlista eliminada\n\n");
            system("pause");
        break;
    case 6:exit(0);
        break;


    }


}while(opc!=0);
}

void ingresar(){
printf("\n\t\tdigite un dato: ");

    scanf("%d",&dato);
    insertarlista(lista,dato);

}

void borrar(){
    int dato3=0;
printf("\n\t\tingrese el elemento a borrar: ");
scanf("%d",&dato3);
eliminarnodo(lista,dato3);

}

void eliminar_lista(nodo *&,int &n){
    nodo *aux=lista;
    n=aux->dato;
    lista=aux->siguiente;
    delete aux;
}
void buscar_elemento(nodo *lista,int n){
    bool ban=false;
    nodo *actual =new nodo();
    actual=lista;
    while((actual!=NULL)&&(actual->dato<=n)){
        if(actual->dato==n){
            ban=true;

        }
        actual=actual->siguiente;
    }

    if(ban==true){
        printf("\n\t\telemento %d SI ha sido encontrado en  la lista\n\n",n);
    }else{
        printf("\n\t\telemento %d NO ha sido econtrado en la lista\n\n",n);
        }

}
