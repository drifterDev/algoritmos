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

bool esValido(string numero){
  if (numero.length()==0) return false;
  if (numero.length()>1 && numero[0]=='0') return false;
  return 0<stoi(numero) && stoi(numero)<=255;
}

void crearCombinaciones(string s,vector<string>& IPsValidas,int index,int cantidadNumeros, string ipValida){
  if (cantidadNumeros>4) return;
  if (cantidadNumeros==4 && index==s.length()){
    IPsValidas.push_back(ipValida);
  } 
  for (int i=1;i<4;i++){
    if(index+i>s.length())break;
    string numero=s.substr(index, i);
    if(!esValido(numero)) continue;
    if (ipValida=="")crearCombinaciones(s, IPsValidas, index+i, cantidadNumeros+1, numero);
    else crearCombinaciones(s, IPsValidas, index+i, cantidadNumeros+1, ipValida + "." + numero);
  }
}

vector<string> restoreIpAdresses(string s){
  vector<string> IPsValidas;
  crearCombinaciones(s,IPsValidas,0,0,"");
  return IPsValidas;
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string entrada;cin>>entrada;
  vector<string> res=restoreIpAdresses(entrada);
  for(auto i: res){
    cout<<i<<"\n";
  }
  return 0;
}