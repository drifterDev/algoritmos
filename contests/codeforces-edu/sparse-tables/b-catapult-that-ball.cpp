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
		int n,q;
		cin>>n>>q;
		int b=300;
		vector<int> a(n);
		vector<int> bl(n/b+5, 0);
		for(int i=0;i<n;++i){
			cin>>a[i];
			bl[i/b]=max(bl[i/b], a[i]);
		}
		int l,r;
		int res=0;
		while(q--){
			cin>>l>>r;
			l--;r--;
			if(l+1>=r){
				res++;
				continue;
			}
			int mn=a[l];
			int ans=0;
			l++;r--;
			while(l<=r){
				if(l%b==0 && l+b-1<=r){
					ans=max(ans, bl[l/b]);
					l+=b;
				}else{
					ans=max(ans, a[l]);
					l++;
				}
			}
			if(ans<=mn){
				res++;
			}
		}
		cout<<res<<"\n";
	}
	return 0;
}
