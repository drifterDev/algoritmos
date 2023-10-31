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
const int MAX=2e5+9;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};
int pre[MAX],suf[MAX],pi[MAX];

void prefix_function(string& t, string& s, int *d){
	pi[0]=0;int m=len(t),n=len(s);
	for(int i=1,k=0;i<m;i++){
		while(k>0 && t[k]!=t[i])k=pi[k-1];
		if(t[i]==t[k])k++;
		pi[i]=k;
	}
	for(int i=0,k=0;i<n;i++){
		while(k>0 && t[k]!=s[i])k=pi[k-1];
		if(s[i]==t[k])k++;
		d[i]=k;
		if(k==m)k=pi[k-1];
	}
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
string t1,t2,p1,p2;cin>>t1;
t2=t1;reverse(all(t2));
int k,res=0,n=len(t1),m;cin>>k;
while(k--){
  cin>>p1;p2=p1;
  reverse(all(p2));
  m=len(p1);
  if(m<=1)continue;
  prefix_function(p1, t1, pre);
  prefix_function(p2, t2, suf);
  for (int i=1;i<n;i++){
    pre[i]=max(pre[i],pre[i-1]);
    suf[i]=max(suf[i-1],suf[i]);
  }
	for (int i=0;i<n-1;i++){
    if(pre[i]+suf[n-i-2]>=m){
      // cout<<k<<"Pass\n";
      res++;break;
    }
  }
  // for(int i=m+1;i<tope;i++)cout<<pre[i]<<" ";
  // cout<<"\n";
  // for(int i=m+1;i<tope;i++)cout<<suf[i]<<" ";
  // cout<<"\n\n";
}cout<<res<<"\n";
return 0;
}