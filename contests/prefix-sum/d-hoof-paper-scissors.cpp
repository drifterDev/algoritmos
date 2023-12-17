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
  map<char, char> mp;
  mp['P']='S',mp['S']='H',mp['H']='P';
  int n;cin>>n;
  vi a(n+1,0),b(n+1,0),c(n+1,0);
  char ch;
  for(int i=1;i<=n;++i){
    cin>>ch;
    if(mp[ch]=='S')a[i]++;
    else if(mp[ch]=='H')b[i]++;
    else c[i]++;
    a[i]+=a[i-1];
    b[i]+=b[i-1];
    c[i]+=c[i-1];
  }
  // for(auto x:a)cout<<x<<" ";
  // cout<<"\n";
  // for(auto x:b)cout<<x<<" ";
  // cout<<"\n";
  // for(auto x:c)cout<<x<<" ";
  // cout<<"\n";

  int res=0;
  for(int i=1;i<=n;++i){
    int op1=a[i]+max(b[n]-b[i-1], c[n]-c[i-1]);
    int op2=b[i]+max(c[n]-c[i-1], a[n]-a[i-1]);
    int op3=c[i]+max(b[n]-b[i-1], a[n]-a[i-1]);
    res=max(res, max(op1, max(op2, op3)));
  }
  cout<<res<<"\n";
  return 0;
}