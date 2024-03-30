// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())

// La creación del automata es O(n)
struct state {
	int len,link;
	map<char,int>next;
};

const int N=100000;
state st[N*2];
int sz,last;

void sa_init(){
	st[0].len=0;
	st[0].link=-1;
	sz++;
	last=0;
}

void sa_extend(char c){
	int act=sz++;
	st[act].len=st[last].len+1;
	int p=last;
	while(p!=-1 && !st[p].next.count(c)){
		st[p].next[c]=act;
		p=st[p].link;
	}
	if(p==-1){
		st[act].link=0;
	}else{
		int q=st[p].next[c];
		if(st[p].len+1==st[q].len){
			st[act].link=q;
		}else{
			int clone=sz++;
			st[clone].len=st[p].len+1;
			st[clone].next=st[q].next;
			st[clone].link=st[q].link;
			while(p!=-1 && st[p].next[c]==q){
				st[p].next[c]=clone;
				p=st[p].link;
			}
			st[q].link=st[act].link=clone;
		}
	}
	last=act;
}

// Retorna la subcadena común más larga entre S y T O(S+T)
string lcs(string S,string T){
	sa_init();
	for(int i=0;i<sz(S);i++)sa_extend(S[i]);
	int v=0,l=0,best=0,bestpos=0;
	for (int i=0;i<sz(T);i++){
		while(v && !st[v].next.count(T[i])){
			v=st[v].link;
			l=st[v].len;
		}
		if(st[v].next.count(T[i])){
			v=st[v].next[T[i]];
			l++;
		}
		if(l>best){
			best=l;
			bestpos=i;
		}
	}
	return T.substr(bestpos-best+1,best);
} 

int main() {
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string s, t;cin>>s>>t;
    cout<<lcs(s, t)<<"\n";
    return 0;
}