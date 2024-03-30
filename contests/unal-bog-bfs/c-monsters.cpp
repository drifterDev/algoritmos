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
int dirx[4] = {-1,0,1,0};
int diry[4] = {0,1,0,-1};
char dirz[4]={'U', 'R', 'D', 'L'};
int camino[1000][1000];
int maximo[1000][1000];
int minimo[1000][1000];
char mapa[1000][1000];
bool visitados[1000][1000];
bool visitados2[1000][1000];
ii termino;
 
void bfs(ii comienzo, int n, int m, bool& pasa){
queue<ii> q;q.push(comienzo);
visitados2[comienzo.first][comienzo.second]=true;
minimo[comienzo.first][comienzo.second]=1;
if (comienzo.first<=0 || comienzo.first>=n-1 || comienzo.second<=0 || comienzo.second>=m-1){
    pasa=true;termino={comienzo.first,comienzo.second};return;
}
while (!q.empty()) {
    ii anterior=q.front();q.pop();
    int x1=anterior.first,y1=anterior.second,minAnt=minimo[x1][y1];
    for (int i=0;i<4;i++) {
        int x2=x1+dirx[i],y2=y1+diry[i];
        ii actual=make_pair(x2,y2);
        if(maximo[x2][y2]<=minAnt ||maximo[x2][y2]<=minAnt+1)continue;
        if (visitados2[x2][y2]==true)continue;
        minimo[x2][y2]=minAnt+1;
        if (x2<=0 || x2>=n-1 || y2<=0 || y2>=m-1){
            pasa=true;termino={x2,y2};
            camino[x2][y2]=i+1;return;
        }
        visitados2[x2][y2]=true;
        camino[x2][y2]=i+1;
        q.push(actual);
    }
}
}
 
void bfsM(ii comienzo,int n, int m){
queue<ii> q;q.push(comienzo);
maximo[comienzo.first][comienzo.second]=1;
visitados[comienzo.first][comienzo.second]=true;
while (!q.empty()) {
    ii anterior=q.front();q.pop();
    int x1=anterior.first,y1=anterior.second;
    int maxAnt=maximo[x1][y1];int count=0;
    for (int i=0;i<4;i++) {
        int x2=x1+dirx[i], y2=y1+diry[i];
        ii actual=make_pair(x2,y2);
        if (x2<0 || x2>=n || y2<0 || y2>=m)continue;
        if(mapa[x2][y2]=='M'){
            count++;continue;
        }
        if (mapa[x2][y2]=='#')maximo[x2][y2]=0;
        if(mapa[anterior.first][anterior.second]!='#' && maximo[x2][y2]>maxAnt+1){
            maximo[x2][y2]=maxAnt+1;
            visitados[x2][y2]=false;
        }
        if (visitados[x2][y2]==true)continue;
        visitados[x2][y2]=true;
        q.push(actual);
    }if(count==2)return;
}
}
 
int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
int n,m;cin>>n>>m;
ii comienzo;
vii mons;
// Entradas
for (int i=0;i<n;i++){
for (int j=0;j<m;j++){
    cin>>mapa[i][j];
    if (mapa[i][j]=='A')comienzo=make_pair(i, j);
    else if(mapa[i][j]=='M')mons.push_back({i, j});
}
}
// Inicializando maximo
for (int i=0;i<n;i++){
for (int j=0;j<m;j++){
    maximo[i][j]=INF;
    if(mapa[i][j]=='#')maximo[i][j]=0;
}}
// Bfs por mons
for(ii mo:mons)bfsM(mo,n,m);
// for (int i=0;i<n;i++){
// for (int j=0;j<m;j++){
//     cout<<maximo[i][j]<<" ";
// }cout<<"\n";}
// Bfs principal
bool pasa=false;
bfs(comienzo, n, m, pasa);
// cout<<"\n";
// for (int i=0;i<n;i++){
// for (int j=0;j<m;j++){
//     cout<<minimo[i][j]<<" ";
// }cout<<"\n";}
	if(pasa==true){
		cout<<"YES\n";vi movimientos;
//         for (int i=0;i<n;i++){
// for (int j=0;j<m;j++){
//     cout<<camino[i][j]<<" ";
// }cout<<"\n";}
		while(termino!=comienzo){
			int move=camino[termino.first][termino.second];
			movimientos.push_back(move-1);
			termino={termino.first-dirx[move-1],termino.second-diry[move-1]};
		}
        reverse(movimientos.begin(), movimientos.end());
		cout<<movimientos.size()<<"\n";
		for(int move:movimientos)cout<<dirz[move];
		cout<<"\n";
        // }
    }
	else cout<<"NO\n";
  return 0;
}