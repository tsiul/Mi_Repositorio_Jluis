#include <iostream>
#include <stdlib.h>
#define Max 100
using namespace std;

void menu();
int MatrizAdyacente[Max][Max];
class nodoa{
public:
    int ady;
    int peso;
    nodoa *siguiente;
    nodoa(int v, int p, nodoa *sig=NULL)
    {
        ady=v;
        peso=p;
        siguiente=sig;
    }
};
struct nodo{
public:
    int vertice;
    nodoa *puntero;
    nodo *siguiente;
    nodo(int v, nodo *sig = NULL, nodoa *punt=NULL)
    {
        vertice = v;
        siguiente = sig;
        puntero = punt;
    }
    class lista;
};
typedef nodo *pnodo;

class lista{
public:
    pnodo primero;
    lista(){primero = NULL;
    }
    void Insertarv(int v);
    bool ListavVacia();
    pnodo Buscarv(int v);
    bool listavexiste(int i, int f);
    void creararco(int i, int f, int peso);
    void CrearMatriz();
    void mostrarmatriz();
    int CantidadVertices();
    int ExisteArco(int i, int f);
    bool BuscarAdy(pnodo aux, int ad);
};
void lista::creararco(int i, int f, int peso){
pnodo pos;
pos=primero;
if(listavexiste(i, f)){
    while(pos!=NULL){
        if(i==pos->vertice){
            if(pos->puntero==NULL){
                pos->puntero=new nodoa(f, peso);
            }
            else{
                nodoa *temp=pos->puntero;
                while(temp->siguiente!=NULL){
                    temp=temp->siguiente;
                }
                temp->siguiente=new nodoa(f, peso);
                temp=NULL;
                delete temp;
            }
        }
        pos=pos->siguiente;
    }
}
}
bool lista::listavexiste(int i, int f){
    if(Buscarv(i)!=NULL&&Buscarv(f)!=NULL){
        return true;
    }
    else{
        return false;
    }
}
void lista::Insertarv(int v){
    pnodo anterior;
    if(ListavVacia())
    {
        primero=new nodo(v, primero);
    }else{if(v<=primero->vertice){
            primero=new nodo(v, primero);
        }else{
            anterior=primero;
            while((anterior->siguiente)&&(anterior->siguiente->vertice<=v)){
                anterior=anterior->siguiente;}

                anterior->siguiente=new nodo(v, anterior->siguiente);
        }
}
}
bool lista::ListavVacia(){
return primero==NULL;
}
int lista::CantidadVertices(){
    pnodo nodo=primero;
    int i=0;
    while(nodo!=NULL){
        i++;
        nodo=nodo->siguiente;
    }
    return i;
}
int lista::ExisteArco(int i, int f){
    pnodo nodo;
    int a=1;
    nodo=Buscarv(i);
    if(nodo){
        if(BuscarAdy(nodo, f)){
            return a;
        }else{
        return a=0;
        }
    }
}
bool lista::BuscarAdy(pnodo aux, int ad){
    nodoa *temp=aux->puntero;
    bool a;
    while(temp){
        if(ad==temp->ady){
            return a=true;
        }
        temp=temp->siguiente;
    }
    return a=false;
}
pnodo lista::Buscarv(int valor){
    int z;
    pnodo indice, n=NULL;
    indice=primero;
    while(indice!=NULL){
        if(valor==indice->vertice){
            return indice;
        }
        indice=indice->siguiente;
    }
    cout<<"\nEL VALOR BUSCADO NO ESTA EN EL GRAFO";
    return n;
}
void lista::CrearMatriz(){
    pnodo nodo=primero, nodotemp;
    int i, j, inicio, fin;
    int cant=CantidadVertices();
    for(i=0;i<cant;i++){
        nodotemp=primero;
        for(j=0;j<cant;j++){
            MatrizAdyacente[i][j]=ExisteArco(nodo->vertice, nodotemp->vertice);
            nodotemp=nodotemp->siguiente;
        }
        nodo=nodo->siguiente;
    }
    delete nodo;
    delete nodotemp;
}
void lista::mostrarmatriz(){
    int i,j,cant;
    pnodo nodo=primero;
    cant=CantidadVertices();
    cout<<"  ";
    for(i=0;i<cant;i++){
        cout<<"\t"<<nodo->vertice<<" ";
        nodo=nodo->siguiente;
    }
    nodo=primero;
    cout<<"\n\n";
    for(i=0;i<cant;i++){
        cout<<nodo->vertice;
        for(j=0;j<cant;j++){
            cout<<"\t"<<MatrizAdyacente[i][j]<<" ";
        }
        nodo=nodo->siguiente;
        cout<<"\n";
    }
}
int main(){
    system("color 07");
    menu();
    return 0;
}
void menu(){
    system("cls");
    int op1=0, valor=0;
    lista l;
        l.Insertarv(1);
        l.Insertarv(2);
        l.Insertarv(3);
        l.Insertarv(4);
        l.Insertarv(5);
        l.creararco(1,2,1);
        l.creararco(2,1,1);
        l.creararco(1,4,2);
        l.creararco(4,1,2);
        l.creararco(4,3,3);
        l.creararco(3,4,3);
        l.creararco(3,2,4);
        l.creararco(2,3,4);
        l.creararco(4,5,5);
        l.creararco(5,4,5);
        l.creararco(5,2,6);
        l.creararco(2,5,6);
        cout<<"\n";
        cout<<"\n\nGRAFO DIRIGIDO ALGORITMOS";
        cout<<"\n";
        cout<<"\n1= Mostrar Matriz adyacente";
        cout<<"\n2= Buscar";
        cout<<"\n3= Salir";
        cout<<"\n";
        cout<<"\nIngrese opcion: ";
        cin>>op1;
    switch(op1){
case 1:
    system("cls");
    cout<<"\n";
    cout<<"\n\n\tMATRIZ DE ADYACENCIA"<<"\n\n";
    l.CrearMatriz();
    l.mostrarmatriz();
    cout<<"\n";
    cout<<"\n";
    system("pause");
    menu();
break;
case 2:
    system("cls");
    cout<<"\nIngrese numero que desee buscar";
break;
}
}
