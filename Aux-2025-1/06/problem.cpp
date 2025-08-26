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

    int n;
    cin >> n;
    int suma_total = 0;
    for(int i= 1;i<=n;i++){
        suma_total += i;
    }
    int suma_parcial = 0;
    int numero;
    for(int i= 1;i<n;i++){
        cin >> numero;
        suma_parcial += numero;
    }
    cout << suma_total << endl;
    cout << suma_parcial << endl;

    cout << suma_total - suma_parcial << endl;

    return 0;
}