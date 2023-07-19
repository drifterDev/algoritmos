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
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res={};
        map<vector<int>, bool> dic;
        map<int, int> much;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for (int k=0;k<n;k++){
          much[nums[k]]++;
        }
        if (much[0]==n){
          return {{0,0,0}};
        }
        int ultimo;
        for(int i=0;i<n-2;i++){
          if (nums[i]>0){
            break;
          }
          if(nums[i]==ultimo){
            continue;
          }
          for(int j=i+1;j<n-1;j++){
            
            int nuevo=-nums[i]-nums[j];
            if (much[nuevo]==0){
              continue;
            }
            int c=0;
            c+= nuevo==nums[i] ? 1:0;
            c+= nuevo==nums[j] ? 1:0;
            if (much[nuevo]<=c){
              continue;
            }
            vector<int> actual={nums[i],nums[j],nuevo};
            sort(actual.begin(), actual.end());
            if (dic[actual]){
              continue;
            }
            dic[actual]=true;
            res.push_back(actual);
          }
          ultimo=nums[i];
        }
        return res;
    }
};