// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef vector<string> vs;

// Usar el aho-corasick para buscar multiples strings en un texto
const static int N=5*1e5; // Maximo de strings
const static int alpha = 26; // Tamaño del alfabeto
int trie[N][alpha], fail[N], nodes, end_word[N], cnt_word[N], fail_out[N];

inline int conv(char ch) { // Funcion para indexar el alfabeto
  return ((ch >= 'a' && ch <= 'z') ? ch-'a' : ch-'A'+26);
}

// Para cada string, se agrega al trie
void add(string &s, int i) {
  int act=0;
  for(char c:s) {
    int x=conv(c);
    if(!trie[act][x]) trie[act][x]=++nodes;
    act=trie[act][x];
  }
  ++cnt_word[act];
  end_word[act]=i;
}

// Se crea el trie con bfs O(N*log(ALPHA))
void build(){ 
  queue<int> q;q.push(0);
  while(sz(q)){
    int u=q.front();q.pop();
    for(int i=0;i<alpha;++i) {
      int v=trie[u][i];
      if(!v)trie[u][i]=trie[fail[u]][i]; 
      else q.push(v);
      if(!u || !v)continue;
      fail[v]=trie[ fail[u] ][i];
      fail_out[v]=end_word[fail[v]]?fail[v]:fail_out[fail[v]];
      cnt_word[v]+=cnt_word[fail[v]];
    }
  }
}

// O(N+M) donde N es el tamaño del texto y M es la cantidad de strings
vs strings;
void searchPatterns(string &t, int q) {
  int act=0, n=len(t);
  for(int i=0;i<n;++i) {
    int x=conv(t[i]);
    act=trie[act][x]; 
    int temp=act;
    while(temp){
      if(end_word[temp])cout<<"En la posicion "<<i<<" se encontro la palabra "<<strings[end_word[temp]-1]<<"\n";
      temp=fail_out[temp];
    }
  }
}

// Por si solo se necesita saber si esta
void solve(int index, string s){
  int act=0;
  bool pass=false;
  for(auto c:s){
    int x=c-'a';
    while(act && !trie[act][x])act=fail[act];
    act=trie[act][x]; 
    pass|=end_word[act]<index;
  }
  cout<<(pass?"YES":"NO")<<"\n";
}


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  string s,x;cin>>s;
  int n;cin>>n;
  for(int i=0;i<n;i++){
    cin>>x;strings.push_back(x);
    add(x, i+1);
  }
  build();
  searchPatterns(s, n);
  return 0;
}