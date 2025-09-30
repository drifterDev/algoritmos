// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2025

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		int b=300;
		vector<int> a(n);
		vector<int> bl(n/b+5, 1e9+5);
		for(int i=0;i<n;++i){
			cin>>a[i];
			bl[i/b]=min(bl[i/b], a[i]);
		}
		int q,l,r;
		cin>>q;
		while(q--){
			cin>>l>>r;
			int ans=1e9+5;
			while(l<=r){
				if(l%b==0 && l+b-1<=r){
					ans=min(ans, bl[l/b]);
					l+=b;
				}else{
					ans=min(ans, a[l]);
					l++;
				}
			}
			cout<<ans<<"\n";
		}
	}
	return 0;
}
