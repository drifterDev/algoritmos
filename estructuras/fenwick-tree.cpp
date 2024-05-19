#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

// Suma de rangos y actualizacion individual
// upd O(log n), rsq O(log n), memory O(n)
struct FwTree{ 
	int n;
	vector<int> bit;
	FwTree(int n): n(n),bit(n+1){}
	int rsq(int r){
		int sum=0;
		for(++r;r;r-=r&-r)sum+=bit[r];
		return sum;
	}
	int rsq(int l, int r){
		return rsq(r)-(l==0?0:rsq(l-1));
	}
	void upd(int r, int v){
		for(++r;r<=n;r+=r&-r)bit[r]+=v;
	}
};

struct FwTree2d{ 
	int n, m;
	vector<vector<ll>> bit;
	FwTree2d(){}
	FwTree2d(int n, int m):n(n),m(m),bit(n+1, vector<ll>(m+1,0)){}
	ll sum(int x, int y){
		ll v=0;
		for(int i=x+1;i;i-=i&-i)
			for(int j=y+1;j;j-=j&-j)v+=bit[i][j];
		return v;
	}
	ll sum(int x, int y, int x2, int y2){
		return sum(x2,y2)-sum(x-1,y2)-sum(x2,y-1)+sum(x-1,y-1);
	}
	void add(int x, int y, ll dt){
		for(int i=x+1;i<=n;i+=i&-i)
			for(int j=y+1;j<=m;j+=j&-j)bit[i][j]+=dt;
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int n,m;cin>>n>>m;
	vector<vector<int>> mat(n, vector<int>(n,0));
	char c;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>c;
			if(c=='*')mat[i][j]=1;
		}
	}
	FwTree2d ft(n,n);
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			if(mat[i][j]){
				ft.add(i,j,1);
			}
		}
	}
	int op,x,y,x2,y2;
	while(m--){
		cin>>op>>x>>y;
		if(op==1){
			if(mat[x-1][y-1]){
				ft.add(x-1,y-1,-1);
				mat[x-1][y-1]=0;
			}else{
				ft.add(x-1,y-1,1);
				mat[x-1][y-1]=1;
			}
		}else{
			cin>>x2>>y2;
			cout<<ft.sum(x-1,y-1,x2-1,y2-1)<<"\n";
		}
	}
	return 0;
}