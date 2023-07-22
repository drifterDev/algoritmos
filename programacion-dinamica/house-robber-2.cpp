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
        vector<int> dp(n+1,0);
        dp[0]=0;
        dp[1]=nums[n-1];
        dp[2]=max(dp[0],nums[0]);
        for(int i=1;i<n-2;i++){
          dp[i+2]=max(dp[i+1], dp[i]+nums[i]);
        }
        dp[n]=max(dp[n-1], dp[n-2]+nums[n-2]);
        return dp[n];
      }
    }
};