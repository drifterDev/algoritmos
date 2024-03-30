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
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
ll val,n,x;cin>>n>>x;int l,r,target;
vector<pair<ll,ll>> nums;
for(int i=0;i<n;i++){
  cin>>val;nums.push_back({val, i});
}
sort(nums.begin(), nums.end());
for(int i=0;i<n;i++){
  l=0;
  r=n-1;
  target=x-nums[i].first;
  while(l!=r){
    if(l!=i && r!=i && nums[l].first+nums[r].first==target){
      cout<<nums[i].second+1<<" "<<nums[l].second+1<<" "<<nums[r].second+1<<"\n";
      return 0;
    }else if(nums[l].first+nums[r].first<target)l++;
    else r--;
  }
}
cout<<"IMPOSSIBLE\n";
return 0;
}