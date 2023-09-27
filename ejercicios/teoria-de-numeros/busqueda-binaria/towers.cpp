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
cin.tie(0);
ll n,val,idx,idx2,towers=0;cin>>n;vl nums;
for(ll i=0;i<n;i++){
  cin>>val;
  if(towers==0){
    nums.push_back(val);
    towers++;
  }else{
    auto it = upper_bound(nums.begin(), nums.end(), val);
    idx=(it - nums.begin());
    if (idx==towers && nums[idx-1]>val)nums[idx-1]=val;
    else if(nums[idx]>val)nums[idx]=val;
    else{
      towers++;
      nums.push_back(val);
    }
  }
  //for(int i=0;i<sz(nums);i++)cout<<nums[i]<<" ";
  //cout<<" "<<idx<<"\n";
}
cout<<towers<<"\n";
return 0;
}