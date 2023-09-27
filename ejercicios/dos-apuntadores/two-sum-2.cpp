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
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        for(int i=0;i<n;i++){
          int actual=target-numbers[i];
          int left=i+1;
          int rigth=n-1;
          while (left<=rigth){
            int mid=left+((rigth-left)/2);
            if (actual==numbers[mid]){
              return {i+1, mid+1};
            }else if(numbers[mid]<actual){
              left=mid+1;
            }else{
              rigth=mid-1;
            }
          }
        }
        return {};
    }
};

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& numbers, int target) {
//         int n=numbers.size();
//         for(int i=0;i<n;i++){
//           for(int j=i+1;j<n;j++){
//             if(numbers[i]+numbers[j]>target){
//               break;
//             }else if(numbers[i]==numbers[j]){
//               continue;
//             }else if(numbers[i]+numbers[j]==target){
//               return {i+1,j+1};
//             }
//           }
//         }
//     }
// };