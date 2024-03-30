// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define len(str) ((int) str.length())
typedef vector<string> vs;

// La factorización de Lyndon de un string es una lista de strings no vacíos
// tal que el string original es la concatenación de los strings de la lista
// en orden lexicográfico. Además, cada string de la lista es un string de
// Lyndon, es decir, es un string que es lexicográficamente menor que todos
// sus sufijos no triviales. Por ejemplo "ab"<"ba". Tambien los strings estan
// ordenados de mayor a menor. 


// El algoritmo de Duval encuentra la factorización de Lyndon de un string en O(n)
vs duval(string const& s) {
	int n=len(s),i=0;
	vs factorization;
	while(i<n){
		int j=i+1,k=i;
		while(j<n && s[k]<=s[j]){
			if(s[k]<s[j])k=i;
			else k++;
			j++;
		}
		while(i<=k){
			factorization.push_back(s.substr(i, j-k));
			i+=j-k;
		}
	}
	return factorization;
}

// Casos de uso
// Encontrar el string lexicográficamente menor que es un shift de un string
string min_cyclic_string(string s) {
	s+=s;
	int n=len(s),i=0,ans=0;
	while(i<n/2){
		ans=i;
		int j=i+1,k=i;
		while(j<n && s[k]<=s[j]){
			if(s[k]<s[j])k=i;
			else k++;
			j++;
		}
		while(i<=k)
		i+=j-k;
	}
	return s.substr(ans, n/2);
}

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	string s="aabaaab";
	vs factorization=duval(s);
	for(string& factor:factorization)cout<<factor<<"\n";

	string t="ababab";
	cout<<min_cyclic_string(t)<<"\n";
	return 0;
}
