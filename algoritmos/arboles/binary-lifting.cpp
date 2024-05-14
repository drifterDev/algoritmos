// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi> ancestor;
const int log2max=30;
int n;
vi p;

void build(){
	for(int i=1;i<=n;++i){
		ancestor[i][0]=p[i];
	}
	for(int i=1;i<log2max;++i){
		for(int j=1;j<=n;++j){
			ancestor[j][i]=ancestor[ancestor[j][i-1]][i-1];
		}
	}
}

int succ(int v, int k){
	for(int i=0;i<log2max;++i){
		if(k&(1<<i)){
			v=ancestor[v][i];
		}
	}
	return (v?v:-1);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	p.assign(n+1,0);
	ancestor.assign(n+1, vi(log2max,0));
	for(int i=2;i<=n;++i)cin>>p[i];
	return 0;
}