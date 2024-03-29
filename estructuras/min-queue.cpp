// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

template<typename T> struct minqueue{
	stack<pair<T,T>> s1, s2;

	T mini(){
		T mini;
		if(s1.empty() || s2.empty()){
            mini=s1.empty()?s2.top().second:s1.top().second;
        }
		else mini=min(s1.top().second, s2.top().second);
		return mini;
	}

	void add(T x){
		T mini=s1.empty()?x:min(x, s1.top().second);
		s1.push({x, mini});
	}

	void remove(){
		if(s2.empty()){
			while(!s1.empty()){
				T x=s1.top().first;
				s1.pop();
				T mini=s2.empty()?x:min(x, s2.top().second);
				s2.push({x, mini});
			}
		}
		s2.pop();
	}
};
