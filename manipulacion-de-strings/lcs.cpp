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

int n,m;
string s,t;

// int go(int i, int j, int& dp, bool& memo){
//   if (i>=n || j>=n){
//     return 0;
//   }
//   if (memo[i][j]){
//     return dp[i][j];
//   }

//   if(s[i]==t[j]){
//     dp[i][j]=go(i+1,j+1)+1;
//   }else{
//     dp[i][j]=max(go(i+1,j),go(i,j+1));
//   }
//   return dp[i][j];
// }

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll n;cin>>n;
  const int MAXIN=n;
  int dp[MAXIN][MAXIN];
  bool memo[MAXIN][MAXIN];
  return 0;
}