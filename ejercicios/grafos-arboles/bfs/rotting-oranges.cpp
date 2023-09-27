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

class RottingOranges {
public:
    int rotting(vector<vector<int>>& cultivo) {
        if (cultivo.empty() || cultivo[0].empty()) {
            return 0;
        }
        
        int cantidadFrescas = 0;
        queue<pair<int, int>> cola;
        vector<pair<int, int>> direcciones = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < cultivo.size(); i++) {
            for (int j = 0; j < cultivo[0].size(); j++) {
                if (cultivo[i][j] == 2) {
                    cola.push({i, j});
                } else if (cultivo[i][j] == 1) {
                    cantidadFrescas++;
                }
            }
        }
        
        if (cantidadFrescas == 0) {
            return 0;
        }
        
        int dias = 0;
        while (!cola.empty()) {
            dias++;
            int size = cola.size();
            for (int i = 0; i < size; i++) {
                pair<int, int> posicionActual = cola.front();
                cola.pop();
                
                for (auto direccion : direcciones) {
                    int x = direccion.first + posicionActual.first;
                    int y = direccion.second + posicionActual.second;
                    
                    if (x >= 0 && x < cultivo.size() && y >= 0 && y < cultivo[0].size() && cultivo[x][y] == 1) {
                        cultivo[x][y] = 2;
                        cola.push({x, y});
                        cantidadFrescas--;
                    }
                }
            }
        }
        
        return (cantidadFrescas == 0) ? (dias - 1) : -1;
    }
};

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<vector<int>> cultivo = {{2, 1, 1}, {1, 1, 0}, {0, 1, 1}};
  RottingOranges ro;
  int resultado = ro.rotting(cultivo);
  cout << "Resultado: " << resultado << "\n";
  return 0;
}