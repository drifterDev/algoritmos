// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int INF = 1e9;

// O(n^3)
int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n;cin>>n;
	vector<vi> adj(n, vi(n,INF)); // INF si no existe esa arista
	for(int k=0;k<n;++k){
		for(int i=0;i<n;++i){
			for(int j=0;j<n;++j){
				if(adj[i][k]<INF && adj[k][j]<INF){
					adj[i][j]=min(adj[i][j],adj[i][k]+adj[k][j]); 
				}
			}
		}
	}
	return 0;
}