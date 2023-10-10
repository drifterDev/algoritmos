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

// Calcular el prefijo sufijo de s
vi calculate_ps(string& s){
  int n=len(s);
  vi ps(n);ps[0]=0;
  for(int i=1, j=0;i<n;i++){
    if(s[i]==s[j])j++;
    else{
      while(j>0 && s[i]!=s[j])j=ps[j-1];
      if(s[i]==s[j])j++;
    }
    ps[i]=j;
  }
  return ps;
}

const int ALPHA=256; // Tamaño del alfabeto
// 102 = n+1, editar si es necesario
int automata[102][ALPHA]; // Si estoy en el estado i y leo el caracter j, a donde voy?

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
string s;cin>>s;
vi ps=calculate_ps(s);
int n=len(s);
// O(n*ALPHA)
automata[0][s[0]]=1; // Estado 0, caracter s[0]
for(int i=0;i<n+1;i++){ // Estado
  for(int j=0;j<ALPHA;j++){ // Caracter
    if(i<n && j==s[i])automata[i][j]=i+1;
    else automata[i][j]=automata[ps[i-1]][j];
  }
}
return 0;
}