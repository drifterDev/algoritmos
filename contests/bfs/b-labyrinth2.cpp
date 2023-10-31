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
int dirx[4] = {-1,0,1,0};
int diry[4] = {0,1,0,-1};
char dirz[4]={'U', 'R', 'D', 'L'};
int camino[1000][1000];
bool visitados[1000][1000];
char mapa[1000][1000];
 
void bfs(ii comienzo, ii final, int n, int m){
	queue<ii> q;q.push(comienzo);
  visitados[comienzo.first][comienzo.second]=true;
  while (!q.empty()) {
		ii anterior=q.front();q.pop();
		for (int i=0;i<4;i++) {
			ii actual=make_pair(anterior.first + dirx[i], anterior.second + diry[i]);
			if (actual.first<0 || actual.first>=n || actual.second<0 || actual.second>=m)continue;
			if (mapa[actual.first][actual.second]=='#')continue;
			if (visitados[actual.first][actual.second]==true)continue;
			visitados[actual.first][actual.second]=true;
			camino[actual.first][actual.second]=i;
			q.push(actual);
		}
	}
}
 
int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n,m;cin>>n>>m;
	ii comienzo,final;
	for (int i=0;i<n;i++) {
		for (int j=0;j<m;j++) {
			cin>>mapa[i][j];
			if (mapa[i][j]=='A')comienzo=make_pair(i, j);
			else if(mapa[i][j]=='B')final=make_pair(i, j);
		}
	}bfs(comienzo, final, n, m);
	if(visitados[final.first][final.second]==true){
		cout<<"YES\n";vi movimientos;
		while(final!=comienzo){
			int move=camino[final.first][final.second];
			movimientos.push_back(move);
			final=make_pair(final.first-dirx[move],final.second-diry[move]);
		}reverse(movimientos.begin(), movimientos.end());
		cout<<movimientos.size()<<"\n";
		for(int move:movimientos)cout<<dirz[move];
		cout<<"\n";
	} else cout<<"NO\n";
  return 0;
}
