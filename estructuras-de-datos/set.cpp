// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    set<int> s;
    //Los sets son una colección de elementos unicos
    //y ordenada que nos permite realizar operaciones
    //como insertar, remover y buscar
    s.insert(3); //{3}
    s.insert(2); //{2,3}
    s.insert(5); //{5,2,3}
    cout<<s.count(3)<<"\n"; //1
    cout<<s.count(4)<<"\n"; //0
    s.erase(3);
    s.insert(4);
    cout<<s.count(3)<<"\n"; //0
    cout<<s.count(4)<<"\n"; //1
    //Podemos buscar elementos dentro del set
    ll x=99; //Elemento a buscar
    auto it=s.find(x);
    if(it==s.end()){
      //x is not found
    }
    cout<<*s.lower_bound(x)<<"\n";
    cout<<*s.upper_bound(x)<<"\n";

    //Set con multiples elementos repetidos
    multiset<int> s2;
    s2.insert(5);
    s2.insert(5);
    s2.insert(5);
    cout<<s2.count(5)<<"\n";

    //Eliminar solo uno de los elementos de un multiset
    s2.erase(s.find(5));
    cout<<s2.count(5)<<"\n"; //2

    //Eliminar todos los elementos de un multiset
    s2.erase(5);
    cout<<s2.count(5)<<"\n"; //0

    //
    unordered_set<int> s3;
    return 0;
}