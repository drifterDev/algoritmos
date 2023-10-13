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

const int N=1e5; // Maximo de strings
int trie[N][26], nodes;
int cnt[N], end_word[N];
int fail[N], fail_out[N];

void add(string& s, int index){  
  int act=0;
  for(char c:s){
    int x=c-'a'; // Mapea a un número de 0 a 25
    if(!trie[act][x])trie[act][x]=++nodes;
    act=trie[act][x];
  }
  cnt[act]++;
  end_word[act]=index;
}

void build(){
  queue<int> q;
  q.push(0);
  while(!q.empty()){
    int u=q.front();q.pop();
    for(int i=0;i<26;i++){
      int v=trie[u][i]; // hijo de u, calcular fail
      if(v){
        q.push(v);
        if(u){ // Calcualr para v el fail y lo demas
          fail[v]=fail[u];
          while(fail[v] && !trie[fail[v]][i])fail[v]=fail[fail[v]];
          fail[v]=trie[fail[v]][i];
          cnt[v]+=cnt[fail[v]];
          fail_out[v]=end_word[fail[v]]?fail[v]:fail_out[fail[v]];
        }
      }
    } 
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n;cin>>n;
for(int i=0;i<n;i++){
  string s;cin>>s;
  add(s, i+1);
}
build();
string s;cin>>s;
int act=0, sum=0;
for(auto c:s){
  int x=c-'a';
  while(act && !trie[act][x])act=fail[act];
  act=trie[act][x]; // Termino nodo
  sum+=cnt[act];
  int tmp=act;
  while(tmp){ // O(sqrt(suma de los caracteres de los strings))
    if(end_word[tmp])cout<<end_word[tmp]<<" ";
    tmp=fail_out[tmp];
  }
}
cout<<"Numero de ocurrencias: "<<sum<<"\n";
return 0;
}