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
  return 0;
}

class Solution {
public:
    int maxProduct(vector<int>& nums) {
      int n=nums.size();
      vector<int> maximo(n+1,0);
      vector<int> minimo(n+1,0);
      maximo[0]=1;
      minimo[0]=1;
      int res=INT_MIN;
      for (int i=0;i<n;i++){
        maximo[i+1]=max(max(maximo[i]*nums[i], minimo[i]*nums[i]),nums[i]);
        minimo[i+1]=min(min(maximo[i]*nums[i], minimo[i]*nums[i]), nums[i]);
        res=max(res, maximo[i+1]);
      }
      return res;
    }
}; 