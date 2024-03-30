// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
const int INF = 1e9;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	vi coins={1,3,4};
	int n=5;
	int count[n+1], value[n+1], first[n+1];
	value[0]=0;
	for(int x=1;x<=n;++x){
		value[x]=INF;
		for(auto c:coins){
			if(x-c>=0 && value[x-c]+1<value[x]){
				value[x]=value[x-c]+1;
				first[x]=c;
			}
		}
	}
	cout<<"Coins: "<<value[n]<<"\n";

	// Una solución
	while(n>0){
		cout<<first[n]<<" ";
		n-=first[n];
	}cout<<"\n";

	// Cantidad de formas
	n=5;
	count[0]=1;
	for(int x=1;x<=n;++x){
		count[x]=0;
		for(auto c:coins){
			if(x-c>=0){
				count[x]+=count[x-c];
			}
		}
	}
	cout<<"Cantidad de formas: "<<count[n]<<"\n";
	return 0;
}