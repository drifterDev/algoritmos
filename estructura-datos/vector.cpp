#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
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
    ll n=9;
    //Array tamaño fijo
    int array[n];
    int array[n][n];
    bool array[2][n][n];
    //Vector tamaño dinamico
    vector<int> v(n);

    v.push_back(4);
    v.pop_back();
    v.resize(n*n);
    v.assign(n, 5);

    vector<int> v2={1,2,4,54,3,5};
    //Eliminar o agregar un elemento al final es O(1)

    v.size(); //Tamaño
    v.back(); //Ultimo

    sort(v.begin(), v.end());
    reverse(v.begin(), v.end());

    lower_bound(v.begin(), v.end(), 5);
    upper_bound(v.begin(), v.end(), 5);

    for(int i=0;i<v.size();i++){
      cout<<v[i]<<"\n";
    }

    for(auto x: v){
      cout<<x<<"\n";
    }
    return 0;
}