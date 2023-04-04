#include<iostream>

using namespace std;

class Caja{
    public:
        int dato;
        Caja *siguiente;

        Caja(int dato){
            this->dato = dato;
            this->siguiente = nullptr;
        };
};

int main(){
    Caja *Head = nullptr;
    Caja *nuevo = nullptr;
    nuevo = new Caja(10);
    Head = nuevo;
    nuevo = new Caja(20);
    Head->siguiente = nuevo;
    nuevo = new Caja(30);
    
    // Head->siguiente->siguiente = nuevo;

}