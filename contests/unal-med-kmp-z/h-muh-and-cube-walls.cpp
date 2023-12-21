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

vi prefix_function(vi s){
  int n=sz(s);
  vi pi(n);
  for(int i=1;i<n;i++) {
    int j=pi[i-1];
    while(j>0 && s[i]!=s[j])j=pi[j-1];
    if (s[i]==s[j])j++;
    pi[i]=j;
  }
  return pi;
}

// O(|t| + |p|)
int matches=0;
void kmp(vi &t, vi &p){ 
  vi phi=prefix_function(p);
  for(int i=0,j=0;i<sz(t);i++){
    while(j>0 && t[i]!=p[j])j=phi[j-1];
    if(t[i]==p[j])j++;
    if(j==sz(p)){
      // cout<<i-j+1<<" "; 
      matches++;
      j=phi[j-1];
    }
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n,m;cin>>n>>m;
vi nums1(n),nums2(m),dif1(n-1),dif2(m-1);
for(int i=0;i<n;i++)cin>>nums1[i];
for(int i=0;i<m;i++)cin>>nums2[i];
if(m==1){
  cout<<n<<"\n";return 0;
}else if(n==1){
  cout<<"0\n";return 0;
}
for(int i=1;i<n;i++)dif1[i-1]=nums1[i-1]-nums1[i];
for(int i=1;i<m;i++)dif2[i-1]=nums2[i-1]-nums2[i];
kmp(dif1, dif2);
cout<<matches<<"\n";
return 0;
}