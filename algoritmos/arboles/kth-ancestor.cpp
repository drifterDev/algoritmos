// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
vector<vi> ancestor;
int n,q;
vi p;

int succ(int v, int k){
	for(int i=0;i<20;++i){
		if(k&(1<<i)){
			v=ancestor[v][i];
		}
	}
	return (v?v:-1);
}

void build(){
	for(int i=1;i<=n;++i){
		ancestor[i][0]=p[i];
	}
	for(int i=1;i<20;++i){
		for(int j=1;j<=n;++j){
			ancestor[j][i]=ancestor[ancestor[j][i-1]][i-1];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cin>>n>>q;
	p.assign(n+1,0);
	ancestor.assign(n+1, vi(20,0));
	for(int a,i=2;i<=n;++i)cin>>p[i];
	int v,k;
	build();
	while(q--){
		cin>>v>>k;
		cout<<succ(v,k)<<"\n";
	}
	return 0;
}