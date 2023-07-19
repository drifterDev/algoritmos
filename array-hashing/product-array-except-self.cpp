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
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> prefix;
        vector<int> postfix;
        int n=nums.size();
        prefix.push_back(nums[0]);
        for (int i=1;i<n;i++){
          prefix.push_back(prefix[i-1]*nums[i]);
        }
        postfix.push_back(nums[n-1]);
        for (int j=1;j<n;j++){
          postfix.push_back(postfix[j-1]*nums[n-1-j]);
        }
        vector<int> array;
        array.push_back(postfix[n-2]);
        for (int m=1;m<n-1;m++){
          array.push_back(prefix[m-1]*postfix[n-2-m]);
        }
        array.push_back(prefix[n-2]);
        return array;
    }
};