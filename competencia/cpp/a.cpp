#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

string cadenaBinaria(string cadena){
    ll n=cadena.length();
    ll ceros=0;
    ll unos=0;
    string seg1,seg2,seg3;
    if (cadena[0]=='1'){
        seg1="0";
        unos++;
    }else {
        ceros++;
    }
    for (int i = 1; i < n; i++) {
        if(cadena[i]=='1'){
            unos++;
        }else{
            ceros++;
        }
        if(cadena[i-1]=='0' && cadena[i]=='1' && seg1==""){
            seg1=to_string(i);
        }else if(cadena[i-1]=='1' && cadena[i]=='0' && seg2==""){
            seg2=to_string(i);
        }else if(cadena[i-1]=='0' && cadena[i]=='1' && seg3==""){
            seg3=to_string(i);
        }
    }
    if(ceros==n){
        seg1=to_string(n);
        seg2=to_string(n);
        seg3=to_string(n);
    }else if(unos==n || seg2==""){
        seg2=to_string(n);
        seg3=to_string(n);
    }else if(seg3==""){
        seg3=to_string(n);
    }
    return seg1+" "+seg2+" "+seg3;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    string entrada, imprime;cin>>entrada;
    imprime=cadenaBinaria(entrada);
    cout<<imprime<<"\n";
    return 0;
}