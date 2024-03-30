// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define len(str) ((int) str.length())
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// El algoritmo encuentra todas las repeticiones de un string

// En esta implementacion guarda el inicio y el final 
// de cada repeticion. Lo que da O(n^2)

vi z_function(string const& s) {
	int n=len(s);
	vi z(n);
	for(int i=1,l=0,r=0;i<n;i++) {
		if(i<=r)z[i]=min(r-i+1, z[i-l]);
		while(i+z[i]<n && s[z[i]]==s[i+z[i]])z[i]++;
		if(i+z[i]-1>r){
			l=i;
			r=i+z[i]-1;
		}
	}
	return z;
}

int get_z(vi const& z, int i) {
	if (0<=i && i<sz(z))return z[i];
	else return 0;
}

vii repetitions;

void convert_to_repetitions(int shift, bool left, int cntr, int l, int k1, int k2){
	for(int l1=max(1,l-k2);l1<=min(l,k1);l1++) {
		if(left && l1==l)break;
		int l2=l-l1;
		int pos=shift+(left?cntr-l1:cntr-l-l1+1);
		repetitions.emplace_back(pos,pos+2*l-1);
	}
}

void find_repetitions(string s, int shift=0){
	int n=len(s);
	if(n==1)return;
	int nu=n/2;
	int nv=n-nu;
	string u=s.substr(0,nu);
	string v=s.substr(nu);
	string ru(u.rbegin(), u.rend());
	string rv(v.rbegin(), v.rend());
	find_repetitions(u, shift);
	find_repetitions(v, shift+nu);
	vi z1=z_function(ru);
	vi z2=z_function(v+'#'+u);
	vi z3=z_function(ru+'#'+rv);
	vi z4=z_function(v);
	for (int cntr=0;cntr<n;cntr++) {
		int l, k1, k2;
		if(cntr<nu) {
			l=nu-cntr;
			k1=get_z(z1, nu-cntr);
			k2=get_z(z2, nv+1+cntr);
		}else{
			l=cntr-nu+1;
			k1=get_z(z3,nu+1+nv-1-(cntr-nu));
			k2=get_z(z4,(cntr-nu)+1);
		}
		if(k1+k2>=l)convert_to_repetitions(shift, cntr<nu, cntr, l, k1, k2);
	}
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	string s="aababcbcabab";
	find_repetitions(s);
	for(auto& rep:repetitions){
		cout<<rep.first<<" "<<rep.second<<"\n";
		cout<<s.substr(rep.first,rep.second-rep.first)<<"\n";
	}
	return 0;
}

