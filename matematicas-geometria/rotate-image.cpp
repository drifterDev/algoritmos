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
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int top, bottom, left,right;
        left=0;
        right=n-1;
        top=0;
        bottom=n-1;
        while (left<right){
          for (int i=0;i<right-left;i++){
            int opcional=matrix[top+i][right];
            int opcional2=matrix[bottom][right-i];
            matrix[top+i][right]=matrix[top][left+i];
            matrix[bottom][right-i]=opcional;
            opcional=matrix[bottom-i][left];
            matrix[bottom-i][left]=opcional2;
            matrix[top][left+i]=opcional;
            }
          left++;
          right--;
          bottom--;
          top++;
        }
    }
};