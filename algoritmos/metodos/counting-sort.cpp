// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define all(x) x.begin(), x.end()
typedef vector<int> vi;

// O(n+k)
void counting_sort(vi &a){ 
	int n=sz(a);
	int maxi=*max_element(all(a));
	int mini=*min_element(all(a));
	int k=maxi-mini+1;
	vi cnt(k,0); 
	for(int i=0;i<n;++i)++cnt[a[i]-mini];
	for(int i=0,j=0;i<k;++i)
		while(cnt[i]--)a[j++]=i+mini;
}
