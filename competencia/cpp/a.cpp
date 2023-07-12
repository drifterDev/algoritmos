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

bool comprobar(vector<vector<char>>& mapa, vector<pair<char, ll>>& instrucciones, pair<ll, ll>& letra) {
    ll x = letra.first;
    ll y = letra.second;
    for (const auto& instruccion : instrucciones) {
        char direccion = instruccion.first;
        ll pasos = instruccion.second;
        if (direccion == 'N') {
            for (ll j = 0; j < pasos; j++) {
                if (x-1< 0 || mapa[x-1][y]=='#') {
                    return false;
                }
                x--;
            }
        } else if (direccion == 'S') {
            for (ll j = 0; j < pasos; j++) {
                if (x+1>=sz(mapa) || mapa[x+1][y]=='#') {
                    return false;
                }
                x++;
            }
        }else if (direccion == 'W') {
            for (ll j = 0; j < pasos; j++) {
                if (y-1< 0 || mapa[x][y-1]=='#') {
                    return false;
                }
                y--;
            }
        }else if (direccion == 'E'){
            for (ll j = 0; j < pasos; j++) {
                if (y+1>= sz(mapa[0]) || mapa[x][y+1]=='#') {
                    return false;
                }
                y++;
            }
        }
    }
    return true;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll n,m;cin>>n >>m;
    vector<vector<char>> mapa(n, vector<char>(m));
    vector<pair<ll, ll>> letras;
    vector<char> letrasOrigen;
    vector<char> ans;
    for (ll i=0;i<n;i++){
        for (ll j=0;j<m;j++){
            cin >> mapa[i][j];
            if (mapa[i][j] != '.' && mapa[i][j] != '#') {
                letras.push_back(make_pair(i, j));
                letrasOrigen.push_back(mapa[i][j]);
            }
        }
    }
    ll ins;cin>>ins;
    vector<pair<char, ll>> instrucciones(ins);
    for (ll q = 0; q < ins; q++) {
        cin >> instrucciones[q].first >> instrucciones[q].second;
    }
    for (ll t=0;t<sz(letras);t++){
        if (comprobar(mapa, instrucciones, letras[t])){
            ans.push_back(letrasOrigen[t]);
        }
    }
    if(ans.empty()){
        cout<<"no solution";
    }else{
        sort(ans.begin(), ans.end());
        for (char c:ans){
            cout<<c;
        }
    }
    cout<<"\n";
    return 0;
}

