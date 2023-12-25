// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
typedef pair<int, int> ii;
typedef vector<ii> vii;

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int n;cin>>n;
  vii intervals;
  while(n--){
    int a,b;cin>>a>>b;
    intervals.PB({a,b});
  }
  sort(all(intervals));
  vii ans;
  int l=intervals[0].F,r=intervals[0].S;
  for(int i=1;i<sz(intervals);i++){
    if(intervals[i].F<=r)r=max(r,intervals[i].S);
    else{
      ans.PB({l,r});
      l=intervals[i].F;
      r=intervals[i].S;
    }
  }
  ans.PB({l,r});
  for(auto x:ans)cout<<x.F<<" "<<x.S<<"\n";
  return 0;
}