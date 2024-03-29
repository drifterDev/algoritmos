// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
typedef pair<int, int> ii;
typedef vector<ii> vii;
map<ii, int> mp;
vii ans;

void hanoi(int x, int start, int end){
  if(x<=0)return;
  hanoi(x-1, start, mp[{start, end}]);
  ans.PB({start, end});
  hanoi(x-1, mp[{start, end}], end);
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  mp[{1,3}]=mp[{3,1}]=2;
  mp[{1,2}]=mp[{2,1}]=3;
  mp[{2,3}]=mp[{3,2}]=1;
  int n;cin>>n;
  hanoi(n,1,3);
  cout<<sz(ans)<<"\n";
  for(auto x:ans){
    cout<<x.F<<" "<<x.S<<"\n";
  }
  return 0;
}