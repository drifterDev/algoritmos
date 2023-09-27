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
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i=0;i<9;i++){
          unordered_map<char,bool> fila;
          unordered_map<char,bool> columna;
          for(int j=0;j<9;j++){
            if (board[i][j]=='.' && board[j][i]=='.'){
              continue;
            }
            if (board[i][j]!='.'){
              if (fila[board[i][j]]){
                return false;
              }else{
                fila[board[i][j]]=true;
              }
            }
            if (board[j][i]!='.'){
              if (columna[board[j][i]]){
                return false;
              }else{
                columna[board[j][i]]=true;
              }
            }
          }
        }
        for(int i=0;i<9;i++){
          unordered_map<char,bool> cuadrante;
          int x=3*(i%3);
          int y=3*(i/3);
          for(int j=0;j<9;j++){
            char actual=board[y+(j/3)][x+(j%3)];
            if (actual!='.'){
              if (cuadrante[actual]){
                return false;
              }else{
                cuadrante[actual]=true;
              }
            }
          }
        }
        return true;
    }
};