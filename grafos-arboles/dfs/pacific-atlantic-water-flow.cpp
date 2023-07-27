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
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        vector<vector<int>> res;
        int n=heights.size();
        int m=heights[0].size();
        vector<vector<bool>> atlantic(n,vector<bool>(m,false));
        vector<vector<bool>> pacific(n,vector<bool>(m,false));
        for (int i=0;i<n;i++){
            dfs(i,m-1,heights,atlantic, n,m);
            dfs(i,0,heights,pacific,n,m);
        }
        for (int i=0;i<m;i++){
            dfs(0,i,heights,pacific,n,m);
            dfs(n-1,i,heights,atlantic,n,m);
        }
        for(int y=0;y<n;y++){
            for(int x=0;x<m;x++){
                if (atlantic[y][x] && pacific[y][x]){
                    res.push_back({y,x});
                }
            }
        }
        return res;
    }

    void dfs(int y, int x, vector<vector<int>>& map, vector<vector<bool>>& visited,int& n, int& m){
        visited[y][x]=true;
        vector<pair<int,int>> dir{{0,1},{1,0},{-1,0},{0,-1}};
        for(int q=0;q<4;q++){
            int y2=y+dir[q].first;
            int x2=x+dir[q].second;
            if(y2>=0 && x2>=0 && y2<n && x2<m && map[y2][x2]>=map[y][x] && !visited[y2][x2]){
                dfs(y2,x2,map,visited,n,m);
            }
        }
    }

};