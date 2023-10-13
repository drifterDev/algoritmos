#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define trace(x) cerr<<#x<<"="<<x<<'\n'
#define sz(arr) ((int) arr.size())
#define len(str) ((int) str.length())
#define all(x) x.begin(), x.end()
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1}; 

// Tamaño del alfabeto
const int K = 26;

struct Vertex {
  int next[K];
  bool output=false;
  int p=-1;
  char pch;
  int link=-1;
  int go[K];

  Vertex(int p=-1, char ch='$'):p(p),pch(ch){
    fill(begin(next), end(next), -1);
    fill(begin(go), end(go), -1);
  }
};

vector<Vertex> t(1);

// Para cada string s, agregarlo al trie
void add_string(string const& s) {
  int v=0;
  for(char ch:s){
    int c=ch-'a';
    if (t[v].next[c]==-1) {
      t[v].next[c]=t.size();
      t.emplace_back(v, ch);
    }
    v=t[v].next[c];
  }
  t[v].output=true;
}

int go(int v,char ch);

int get_link(int v) {
  if (t[v].link==-1) {
    if(v == 0 || t[v].p==0)t[v].link=0;
    else t[v].link=go(get_link(t[v].p),t[v].pch);
  }
  return t[v].link;
}

int go(int v, char ch) {
  int c=ch-'a';
  if(t[v].go[c]==-1) {
      if(t[v].next[c]!=-1)t[v].go[c]=t[v].next[c];
      else t[v].go[c]=v==0?0:go(get_link(v), ch);
  }
  return t[v].go[c];
} 

void find_strings(vs& strings, string& text){
  int act=0;
  for(char ch:text){
    act=go(act,ch);
    // Verifica si el nodo actual marca el final de alguna cadena
    int tmp=act;
    while(tmp!=0) {
      // Imprime la cadena que termina en este nodo
      if(t[tmp].output)cout<<"Encontrada: "<<strings[tmp]<<"\n";
      tmp=get_link(tmp);
    }
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n;cin>>n;
vs strings(n);
for(int i=0;i<n;i++) {
  cin>>strings[i];
  add_string(strings[i]);
}
string text;cin>>text;
find_strings(strings, text);
return 0;
}