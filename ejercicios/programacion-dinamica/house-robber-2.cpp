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
    int rob(vector<int>& nums) {
      int n=nums.size();
      if(n==1){
        return nums[0];
      }else if(n==2){
        return max(nums[0], nums[1]);
      }else{
        int n=nums.size();
        vector<int> dp(n,0);
        vector<int> dp2(n,0);
        dp[1]=nums[0];
        dp2[1]=nums[1];
        for(int i=1;i<n-1;i++){
          dp[i+1]=max(dp[i], dp[i-1]+nums[i]);
          dp2[i+1]=max(dp2[i], dp2[i-1]+nums[i+1]);
        }
        int res=max(dp2[n-1], dp[n-1]);
        return res;
      }
    }
};