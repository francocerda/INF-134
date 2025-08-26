#include<iostream>

using namespace std;

struct Nodo{

    int dato; // dato del nodo
    Nodo *siguiente; // puntero al siguiente nodo
};



int main(){
  
    cout << "Tamanio de un nodo: " << sizeof(Nodo) << endl;

    return 0;
}