#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<string> vs;
typedef vector<ii> vii;
const double PI = acos(-1);
const double EPS = 1e-9;
const int MOD = 1e9+7;
const int INF = 1e9;
const ll INFL = 1e18;
int dx4[4] = {0,-1,1,0};
int dy4[4] = {-1,0,0,1};
int dx8[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dy8[8] = {0, 1, 1, 1, 0, -1, -1, -1};
const string ABC = "abcdefghijklmnopqrstuvwxyz";

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int minimo=INT_MAX,n,k,b;
  cin>>n>>k>>b;
  vi nums(n,0);
  for(int tmp,i=0;i<b;++i){
    cin>>tmp;
    nums[tmp-1]=1;
  }
  for(int i=1;i<n;++i)nums[i]+=nums[i-1];
  for(int i=0;i+k<n;++i)minimo=min(minimo, nums[i+k]-nums[i]);
  cout<<minimo<<"\n";
  
  // for(auto x:nums)cout<<x<<" ";
  // cout<<"\n";
  return 0;
}