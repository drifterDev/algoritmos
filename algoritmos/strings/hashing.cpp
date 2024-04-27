// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> ii;
const int MODS[] = { 1001864327, 1001265673 }; // 1000234999, 1000567999, 1000111997, 1000777121, 1001265673, 1001864327, 999727999, 1070777777
const ii BASE={257, 367}, ZERO={0, 0}, ONE={1, 1};
const int MAXN = 2*1e5;

inline int mod(int a, const int& m){return ((a%m)+m)%m;}
inline int suma(int a, int b,  const int& m){return mod(mod(a,m)+mod(b,m),m);}
inline int resta(int a, int b, const int& m){return mod(a-b,m);}
inline int multi(int a, int b, const int& m){return mod(mod(a,m)*mod(b,m),m);}

inline ii operator + (const ii a, const ii b){
  	return {suma(a.first, b.first, MODS[0]), suma(a.second, b.second, MODS[1])};
}
inline ii operator - (const ii a, const ii b) {
  	return {resta(a.first, b.first, MODS[0]), resta(a.second, b.second, MODS[1])};
}
inline ii operator * (const ii a, const ii b) {
  	return {multi(a.first, b.first, MODS[0]), multi(a.second, b.second, MODS[1])};
}

ii p[MAXN+1];
void prepare(){
	p[0]=ONE;
	for(int i=1;i<=MAXN;i++)p[i]=p[i-1]*BASE;
}

template <class type> 
struct hashing {
	vector<ii> h;
	hashing(type &t) {
		h.resize((int)t.size()+1);
		h[0]=ZERO;
		for (int i=1;i<(int)h.size();++i)
			h[i]=h[i-1]*BASE + ii{t[i-1], t[i-1]};
	}

	ii query(int l, int r){ // [l, r]
		return h[r+1]-h[l]*p[r-l+1];
	}
};
