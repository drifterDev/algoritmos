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
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> opc;
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = m - 1;
        int top = 0;
        int bottom = n - 1;
        int c = 1;

        while (left <= right && top <= bottom) {
            if (c == 1) {
                for (int i = left; i <= right; i++) {
                    opc.push_back(matrix[top][i]);
                }
                top++;
                c++;
            } else if (c == 2) {
                for (int i = top; i <= bottom; i++) {
                    opc.push_back(matrix[i][right]);
                }
                right--;
                c++;
            } else if (c == 3) {
                for (int i = right; i >= left; i--) {
                    opc.push_back(matrix[bottom][i]);
                }
                bottom--;
                c++;
            } else {
                for (int i = bottom; i >= top; i--) {
                    opc.push_back(matrix[i][left]);
                }
                left++;
                c = 1;
            }
        }

        if (opc.size() < n * m) {
            opc.push_back(matrix[n / 2][m / 2]);
        }

        return opc;
    }
};