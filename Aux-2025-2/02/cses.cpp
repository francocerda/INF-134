#include <bits/stdc++.h>
using namespace std;

int main() {

    int n;cin>>n;
    cout << n << endl;
    int suma = 0, sumatoria  = 0;
    for(int i=1;i<=n;i++){
        sumatoria+= i;
    }
    for(int i=0;i<n-1;i++){
        int x;cin >>x;
        suma+=x;
    }

    cout << sumatoria - suma << endl;

    return 0;
}