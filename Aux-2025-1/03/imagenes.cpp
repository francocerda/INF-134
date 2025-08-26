#include<iostream>

using namespace std;


int** rotar_matriz(int** matriz, int fila, int columna){
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna/2;j++){
            int temp = matriz[i][j];
            matriz[i][j] = matriz[i][columna-j-1];
            matriz[i][columna-j-1] = temp;
        }
    }
    return matriz;
}

int** rotar_reflexion(int** matriz, int fila, int columna){

    //Transponer la matriz
    for(int i=0;i<fila;i++){
        for(int j=i;j<columna;j++){
            int temp = matriz[i][j];
            matriz[i][j] = matriz[j][i];
            matriz[j][i] = temp;
        }
    }

    cout<<"La matriz traspuesta es: "<<endl;
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }

    //Reflejar la matriz
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna/2;j++){
            int temp = matriz[i][j];
            matriz[i][j] = matriz[i][columna-j-1];
            matriz[i][columna-j-1] = temp;
        }
    }

    return matriz;
}


int main(){
   
    int fila,columna;
    cout<<"Ingrese la cantidad de filas: ";cin>>fila;
    cout<<"Ingrese la cantidad de columnas: ";cin>>columna;
    int** matriz = new int*[fila];
    for(int i=0;i<fila;i++){
        matriz[i] = new int[columna];
    }
    cout<<"Ingrese los elementos de la matriz: "<<endl;
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            cin>>matriz[i][j];
        }
    }
    cout<<"La matriz es: "<<endl;
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }

    //rotar_matriz(matriz,fila,columna);
    rotar_reflexion(matriz,fila,columna);
    cout<<"La matriz rotada es: "<<endl;
    for(int i=0;i<fila;i++){
        for(int j=0;j<columna;j++){
            cout<<matriz[i][j]<<" ";
        }
        cout<<endl;
    }


    return 0;
}