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
    int minEatingSpeed(vector<int>& piles, int h) {
        int maximo=0;
        for (int num: piles){
          maximo=max(num,maximo);
        }
        int l=1;
        int r=maximo;
        while(l<=r){
          int mid=l+(r-l)/2;
          int actual=horas(piles,mid);
          if (actual == h){
            return mid;
          }else if(actual<h){
            l=mid+1;
          }else{
            r=mid-1;
          }
        }
        return l;
    }

    int horas(vector<int>& piles, int k){
      int res=0;
      for (int num:piles){
        res+=num/k;
        if (num%k!=0){
          res+=1;
        }
      }
      return res;
    }
};