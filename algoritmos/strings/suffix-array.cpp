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

vi sort_cyclic_shifts(string const& s) {
  int n=len(s);
  const int alphabet=256;
  vi p(n),c(n),cnt(max(alphabet,n),0);
  for(int i=0;i<n;i++)cnt[s[i]]++;
  for(int i=1;i<alphabet;i++)cnt[i]+=cnt[i-1];
  for(int i=0;i<n;i++)p[--cnt[s[i]]]=i;
  c[p[0]]=0;
  int classes=1;
  for(int i=1;i<n;i++) {
    if(s[p[i]]!=s[p[i-1]])classes++;
    c[p[i]]=classes-1;
  }
  vi pn(n),cn(n);
  for(int h=0;(1<<h)<n;++h) {
    for(int i=0;i<n;i++) {
      pn[i]=p[i]-(1<<h);
      if(pn[i]<0)pn[i]+=n;
    }
    fill(cnt.begin(),cnt.begin()+classes,0);
    for(int i=0;i<n;i++)cnt[c[pn[i]]]++;
    for(int i=1;i<classes;i++)cnt[i]+=cnt[i-1];
    for(int i=n-1;i>=0;i--)p[--cnt[c[pn[i]]]]=pn[i];
    cn[p[0]]=0;
    classes=1;
    for(int i = 1; i < n; i++) {
      ii cur={c[p[i]],c[(p[i]+(1<<h))%n]};
      ii prev={c[p[i-1]],c[(p[i-1]+(1<<h))%n]};
      if(cur!=prev)++classes;
      cn[p[i]]=classes-1;
    }
    c.swap(cn);
  }
  return p;
}
// O(nlogn)
vi suffix_array(string s) {
  s+="$";
  vi sorted_shifts=sort_cyclic_shifts(s);
  sorted_shifts.erase(sorted_shifts.begin());
  return sorted_shifts;
}

// Casos de uso
// ******************************
// Tambien podemos usar el suffix_array para 
// Encontrar el smallest cyclic shift
// Sin añadir ningun caracter a la cadena
// Lo obtenemos en p[0]

vi lcp_construction(string const& s, vi const& p) {
  int n=len(s);
  vi rank(n,0);
  for(int i=0;i<n;i++)rank[p[i]]=i;
  int k=0;
  vi lcp(n-1,0);
  for(int i=0;i<n;i++){
    if(rank[i]==n-1) {
      k=0;continue;
    } 
    int j=p[rank[i]+1];
    while(i+k<n && j+k<n && s[i+k]==s[j+k])k++;
    lcp[rank[i]] = k;
    if(k)k--; 
  }
  return lcp;
}
// ******************************

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
string s;cin>>s;
vi sa=suffix_array(s);
for(int i=0;i<len(s);i++)cout<<sa[i]<<" ";
cout<<"\n";

vi lcp=lcp_construction(s,sa);
for(int i=0;i<len(s)-1;i++)cout<<lcp[i]<<" ";
cout<<"\n";
return 0;
}