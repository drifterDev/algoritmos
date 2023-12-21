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

struct dsu{
  vl parents,sizes;
  ll cantSets;
  ll maxSz;

  dsu(ll sz){
    parents.assign(sz, 0);
    sizes.assign(sz, 1);
    cantSets=sz;
    maxSz=1;
    for (int i = 0; i<sz; i++) parents[i] = i;}

  ll findSet(ll v) {
    if (v == parents[v]) return v;
    return parents[v] = findSet(parents[v]);}

  bool isSameSet(ll i, ll j) {return findSet(i) == findSet(j);}

  void unionSets(ll a, ll b) {
    a = findSet(a);
    b = findSet(b);
    if (a!=b) {
        if (sizes[a] < sizes[b]) swap(a, b);
        parents[b] = a;
        sizes[a] += sizes[b];
        maxSz = max(maxSz,sizes[a]);
        cantSets--;
    }
  }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}