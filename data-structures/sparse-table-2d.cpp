#include <bits/stdc++.h>
using namespace std;
typedef long long T;

// O(n*m*log(n)*log(m)) - O(1)
T op(T a, T b); // max, min, gcd ...
const int logn = 10;
struct Table2D{ 
	vector<vector<vector<vector<T>>>> st;
	vector<int> lg2;

	void build(int n, int m, vector<vector<T>>& a){ 
		st.assign(
			n, vector<vector<vector<T>>>(
				m, vector<vector<T>>(
					logn, vector<T>(logn)
				)
			)
		);
		lg2.assign(max(n,m),0);
		for(int i=2;i<max(n,m);++i)lg2[i]=lg2[i>>1]+1;
		for(int i=0;i<n;++i){
			for(int j=0;j<m;++j){
				st[i][j][0][0]=a[i][j];
			}
		}
		for(int a=0;a<logn;++a){
			for(int b=0;b<logn;++b){
				if(a+b==0)continue;
				for(int i=0;i+(1<<a)<=n;++i){
					for(int j=0;j+(1<<b)<=m;++j){
						if(!a){
							st[i][j][a][b]=op(st[i][j][a][b-1], st[i][j+(1<<(b-1))][a][b-1]);
						}else{
							st[i][j][a][b]=op(st[i][j][a-1][b], st[i+(1<<(a-1))][j][a-1][b]);
						}
					}
				}
			}
		}
	}

	int get(int x1, int y1, int x2, int y2){
		x2++;y2++;
		int a=lg2[x2-x1],b=lg2[y2-y1];
		return op(
				op(st[x1][y1][a][b], 
					st[x2-(1<<a)][y1][a][b]),
				op(st[x1][y2-(1<<b)][a][b], 
					st[x2-(1<<a)][y2-(1<<b)][a][b])
			);
	}
};