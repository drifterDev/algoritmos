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

vi prefix_function(string s){
  int n=len(s);
  vi pi(n);
  for(int i=1;i<n;i++) {
    int j=pi[i-1];
    while(j>0 && s[i]!=s[j])j=pi[j-1];
    if (s[i]==s[j])j++;
    pi[i]=j;
  }
  return pi;
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
string s="-1";cin>>s;
while(s!="-1"){
    string s2(s);
    reverse(all(s2));
    s2+="#"+s;
    vi pi=prefix_function(s2);
    // cout<<s2<<endl;
    int m=len(s2), n=len(s);
    // for(int i=0;i<len(s2);i++)cout<<pi[i]<<"";
    string s3=s.substr(0, n-pi[m-1]);
    reverse(all(s3));
    // cout<<s3<<pi[m-1]<<"\n";
    cout<<s+s3<<"\n";
    s="-1";cin>>s;
}
return 0;
}
