// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

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

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int t;cin>>t;
while(t--){
  int n;cin>>n;
  vs strings(n);
  map<string,bool> mapa;
  string res="";
  for(int i=0;i<n;i++){
    cin>>strings[i];
    mapa[strings[i]]=true;
  }
  for(int i=0;i<n;i++){
    int m=len(strings[i]);
    bool flag=false;
    for(int j=0;j<m;j++){
      string s1=strings[i].substr(0,j);
      string s2=strings[i].substr(j,m-j);
      if(mapa[s1] && mapa[s2]){
        flag=true;break;
      }
    }
    if(flag)res+="1";
    else res+="0";
  }cout<<res<<"\n";
}
return 0;
}