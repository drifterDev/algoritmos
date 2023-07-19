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
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int> ceros;
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>col;
        vector<int> row;
        for(int i=0;i<n;i++){
          bool fila=false;
          for(int j=0;j<m;j++){
            if (matrix[i][j]==0){
              fila=true;
              col.push_back(j);
            }
          }
          if (fila){
           matrix[i]=vector<int>(m);
           row.push_back(i);
          }
        }
        for(int i=0;i<n;i++){
          if (find(row.begin(), row.end(), i)!=row.end()){
            continue;
          }
          m=col.size();
          for(int j=0;j<m;j++){
            matrix[i][col[j]]=0;
          }
        }
    }
};