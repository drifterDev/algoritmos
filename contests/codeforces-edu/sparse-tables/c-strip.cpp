// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2025

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct Table{
	vector<vector<int>> st;
	int type;
	int oper(int a, int b){
		if(type)return max(a,b);
		return min(a,b);
	}
	Table(vector<int>& a, int ty){
		st.push_back(a);
		int n=a.size();
		type=ty;
		for(int i=1;(1<<i)<=n;++i){
			st.push_back(vector<int>());
			for(int j=0;j+(1<<i)-1<n;++j){
				st[i].push_back(oper(st[i-1][j], st[i-1][j+(1<<(i-1))]));
			}
		}
	}
	int get(int l, int r){
		int lg=31-__builtin_clz(r-l+1);
		return oper(st[lg][l], st[lg][r-(1<<lg)+1]);
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,s,l;
	cin>>n>>s>>l;
	vector<int> a(n);
	for(int& x:a)cin>>x;
	Table mx(a,1);
	Table mn(a,0);
	vector<int> dp(n+1, 1e9);
	dp[n]=0;
	set<pair<int, int>> st;
	for(int j=n-1,i=n-1;i>=0;--i){
		if(i+l<=n)st.insert({dp[i+l],i+l});
		while(j>=i+l && mx.get(i,j)-mn.get(i,j)>s){
			st.erase({dp[j+1], j+1});j--;
		}
		if(mx.get(i,j)-mn.get(i,j)<=s && !st.empty()){
			dp[i]=(*st.begin()).first+1;
		}
	}
	cout<<(dp[0]>n?-1:dp[0])<<"\n";
	return 0;
}
