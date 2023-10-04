// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(x) x.begin(), x.end()
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;

// se recomienda usar m = pow(2,64) porque 
// m=1e9+9 no es suficiente para la multiplicacion de dos 64-bit integers
// Porque la probabilidad de colisiones es 1/m = 10^-9
// y si son 10^6 strings que hay que comparar con este entonces 1/m = 10^-3
// y comparamos unos con otros entonces 1/m = 1, si o si va a haber algun fallo
// Una solución sencilla es hacer dos hash (hash1, hash2) 
// con p diferentes para tener una probabilidad de 1/10^18
// y si comparamos unos con otros entonces 1/m = 10^-6

// O(n)
// Dos strings con mismo hash no necesariamente son iguales
// Pero si tienen distinto hash, entonces son distintos
ll compute_hash(string const& s) {
  const int p = 31; // 51 si se usan mayusculas tambien
  // Importante que m sea un numero primo
  const int m = 1e9 + 9; 
  ll hash_value=0;
  ll p_pow=1;
  for (char c:s) {
    hash_value=(hash_value+(c-'a'+1)*p_pow)%m;
    p_pow=(p_pow*p)%m;
  }
  return hash_value;
}

// Casos de uso
// ******************************
// O(nm+nlogn) = O(n(m+logn))
vector<vi> group_identical_strings(vs const& s) {
  int n=s.size();
  vector<pair<ll, int>> hashes(n);
  for(int i=0;i<n;i++)
    hashes[i]={compute_hash(s[i]),i};
  sort(all(hashes));
  vector<vi> groups;
  for(int i=0;i<n;i++) {
    // Si es el primero o si el hash es distinto al anterior entonces es un nuevo grupo
    if(i==0 || hashes[i].first!=hashes[i-1].first)groups.emplace_back();
    groups.back().push_back(hashes[i].second);
  }
  return groups;
}

// O(n^2)
int count_unique_substrings(string const& s) {
  int n = s.size();
  // Ojo con p y m
  const int p=31;
  const int m=1e9+9;
  ll p_pow[n], h[n+1];
  p_pow[0]=1;
  // Precalculo de potencias de p
  for(int i=1;i<n;i++)p_pow[i]=(p_pow[i-1]*p)%m;
  // Precalculo de hashes de prefijos de s
  for(int i=0;i<n;i++)h[i+1]=(h[i]+(s[i]-'a'+1)*p_pow[i])%m;
  int cnt=0;
  for(int l=1;l<=n;l++) {
    unordered_set<ll> hs;
    for(int i=0;i<=n-l;i++) {
      ll cur_h=(h[i+l]+m-h[i])%m;
      cur_h=(cur_h*p_pow[n-i-1])%m;
      hs.insert(cur_h);
    }
    cnt+=hs.size();
  }
  return cnt;
}
// ******************************


int main() {
ios::sync_with_stdio(false);
cin.tie(0);
cout<<"Funcion hash:\n";
cout<<compute_hash("hola")<<"\n";
cout<<compute_hash("HOLA")<<"\n";
cout<<compute_hash("hoLa")<<"\n";

// Caso de uso
cout<<"\nDiferentes strings en un vector dado:\n";
vs strings={"abc", "def", "abc", "ghi", "jkl", "def"};
vector<vi> result = group_identical_strings(strings);
for (const auto& group : result) {
  cout<<"Grupo: ";
  for(int index:group)cout<<index<<" ";
  cout<<"\n";
}

// Caso de uso
cout<<"\nCantidad de substrings unicos de un string dado:\n";
vs s={"abc","abab","aaa","","abcdabcd"};
for(int i=0;i<5;i++){
  cout<<"Caso "<<i+1<<": "<<count_unique_substrings(s[i])<<"\n";
}
return 0;
}
