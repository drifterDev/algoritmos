// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first

int main(){
	ios::sync_with_stdio(false);cin.tie(0);
	map<string, int> m;

	if (m.count("Mango")){
		//La llave existe
	}

	//Recorrer un map
	for(auto x:m){
		cout<<x.F<<" "<<x.S<<"\n";
	}

	// Eliminar un elemento
	m.erase("Mango");

	map<int, int> m2;
	m2[3]=5; // [(3, 5)]
	m2[11]=4; // [(3, 5); (11, 4)]
	m2[10]=491; // [(3, 5); (10, 491); (11, 4)]
	cout<<m2.lower_bound(10)->F<<" "<<m2.lower_bound(10)->S<<"\n"; //,→ 10 491
	cout<<m2.upper_bound(10)->F<<" "<<m2.upper_bound(10)->S<<"\n"; //,→ 11 4

	// Usa hashing y es O(1), desventaja: no esta ordenado
	unordered_map<int,int> m3;
	return 0;
}
