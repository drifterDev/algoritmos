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
    int longestConsecutive(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        long long c,n,maximo;
        maximo=0;
        n=nums.size();
        c=n==0?0:1;
        maximo=max(c, maximo);
        for (long long i=1;i<n;i++){
          if(nums[i-1]==nums[i]){
            continue;
          }
          if (nums[i-1]+1==nums[i]){
            c++;
            maximo=max(c, maximo);
          }else{
            c=1;
          }
        }
        return maximo;
    }
};