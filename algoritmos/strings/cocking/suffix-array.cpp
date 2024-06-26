// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define len(str) ((int) str.length())
#define all(x) x.begin(), x.end()
typedef pair<int, int> ii;
typedef vector<int> vi;

vi sort_cyclic_shifts(string const& s) {
	int n=len(s);
	const int alphabet=256;
	vi p(n),c(n),cnt(max(alphabet,n),0);
	for(int i=0;i<n;i++)cnt[s[i]]++;
	for(int i=1;i<alphabet;i++)cnt[i]+=cnt[i-1];
	for(int i=0;i<n;i++)p[--cnt[s[i]]]=i;
	c[p[0]]=0;
	int classes=1;
	for(int i=1;i<n;i++) {
		if(s[p[i]]!=s[p[i-1]])classes++;
		c[p[i]]=classes-1;
	}
	vi pn(n),cn(n);
	for(int h=0;(1<<h)<n;++h) {
		for(int i=0;i<n;i++) {
			pn[i]=p[i]-(1<<h);
			if(pn[i]<0)pn[i]+=n;
		}
		fill(cnt.begin(),cnt.begin()+classes,0);
		for(int i=0;i<n;i++)cnt[c[pn[i]]]++;
		for(int i=1;i<classes;i++)cnt[i]+=cnt[i-1];
		for(int i=n-1;i>=0;i--)p[--cnt[c[pn[i]]]]=pn[i];
		cn[p[0]]=0;
		classes=1;
		for(int i = 1; i < n; i++) {
			ii cur={c[p[i]],c[(p[i]+(1<<h))%n]};
			ii prev={c[p[i-1]],c[(p[i-1]+(1<<h))%n]};
			if(cur!=prev)++classes;
			cn[p[i]]=classes-1;
		}
		c.swap(cn);
	}
	return p;
}

// O(nlogn)
vi suffix_array(string s) {
	s+="$";
	vi sorted_shifts=sort_cyclic_shifts(s);
	sorted_shifts.erase(sorted_shifts.begin());
	return sorted_shifts;
}

// Casos de uso
// ******************************

vi lcp_construction(string const& s, vi const& p) {
	int n=len(s);
	vi rank(n,0);
	for(int i=0;i<n;i++)rank[p[i]]=i;
	int k=0;
	vi lcp(n-1,0);
	for(int i=0;i<n;i++){
		if(rank[i]==n-1) {
			k=0;continue;
		} 
		int j=p[rank[i]+1];
		while(i+k<n && j+k<n && s[i+k]==s[j+k])k++;
		lcp[rank[i]] = k;
		if(k)k--; 
	}
	return lcp;
}

int different_substrings(string s) {
	vi sa=suffix_array(s);
	vi lcp=lcp_construction(s,sa);
	int n=len(s);
	int act=n*(n+1);act/=2;
	for(int i=0;i<n-1;i++)act-=lcp[i];
	return act;
}

string longest_repeated_substring(string& s){
	// Si se tienen que sacar varios, entonces son todos los que sean iguales al maximo
	vi sa=suffix_array(s);
	vi lcp=lcp_construction(s,sa);
	int n=len(s);
	int max_len=0, start=0;
	for(int i=0;i<n-1;i++){
		if(lcp[i]>max_len){
			max_len=lcp[i];
			start=sa[i];
		}
	}
	return s.substr(start,max_len);
}

// ******************************

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	string s;cin>>s;int n=len(s);
	vi sa=suffix_array(s); 
	cout<<"Desde el index, el suffix array\n";
	for(int i=0;i<n;i++)cout<<sa[i]<<" ";
	cout<<"\nVa comparando de 2 en 2 y muestra el lcp:\n";
	vi lcp=lcp_construction(s,sa);
	for(int i=0;i<n-1;i++)cout<<lcp[i]<<" ";
	cout<<"\nEl número de substrings distintos\n";
	cout<<different_substrings(s)<<"\n";
	return 0;
}