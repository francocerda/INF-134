#include <bits/stdc++.h>
#define int long long
#define vi vector<int>
#define vii vector<vector<int>>
#define pii pair<int,int>
#define forn for(int i=0;i<n;i++)
#define USM ios::sync_with_stdio(0); cin.tie(0);
#define endl '\n'
const int mod = 1e9+7;

using namespace std;


//Como ejercicio buscamos la suma de los n numeros

int suma(int n){

    if(n == 1){ return 1;}
    return n + suma(n-1);

};


signed main(){
    
    cout << suma(3) << endl;
    
    cout << suma(12) << endl;

    return 0;
}