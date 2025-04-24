#include<iostream>
#include<stack>
#include<queue>

using namespace std;  


//Balance de parantesis

int main(){

    string s;cin >> s;
    stack<char> pila;
    for(char &c:s){
        if(c == '('){
            pila.push(c);
        }
        else if(c == ')'){
            if(pila.empty()){
                cout << "NO" << endl;
                return 0;
            }
            pila.pop();
        }    

    }
    if(pila.empty()){
        cout << "YES" << endl;
    }
    else{
        cout << "NO" << endl;
    }
    return 0;
    
}   