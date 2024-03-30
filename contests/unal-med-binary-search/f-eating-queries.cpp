// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll t,n,q, query;cin>>t;
while(t--){
  cin>>n>>q;
  vi nums(n,0);for(int i=0;i<n;i++)cin>>nums[i];
  sort(nums.begin(), nums.end(), greater<int>());
  vl prefix(n+1,0);for(int i=1;i<n+1;i++)prefix[i]=prefix[i-1]+nums[i-1];
  //for(int i=0;i<n+1;i++)cout<<prefix[i]<<" ";
  //cout<<"\n";
  while(q--){
    cin>>query;
    auto r=upper_bound(prefix.begin(), prefix.end(), query);
    ll res=(r - prefix.begin());
    if(res==n+1 && prefix[res-1]<query)cout<<"-1\n";
    else if(res==n+1 || prefix[res-1]==query)cout<<res-1<<"\n";
    else cout<<res<<"\n";
    // cout<<prefix[res-1]<<"\n";
  }
}
return 0;
}