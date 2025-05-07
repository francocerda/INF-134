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


signed main(){
    USM;

    map<int,string> lista;
    lista.insert({0,"Diego"});
    lista.insert({1,"Erick"});
    lista.insert({2,"Ignacio"});
    lista.insert({3,"Javier"});
    lista.insert({3,"Luis"});
    for(auto &p: lista){
        cout << p.first << " " << p.second << endl;
    }


    return 0;
}