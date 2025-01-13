#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[20][20][2],n,m;
int k,d;

ll dfs(string& c, int x=0, int y=0, bool z=0){
	if(dp[x][y][z]!=-1)return dp[x][y][z];
	dp[x][y][z]=(y==k);
	if(x==(int)c.size()){
		return dp[x][y][z];
	}
	int limit=9;
	if(!z){
		limit=c[x]-'0';
	}
	dp[x][y][z]=0;
	for(int i=0;i<=limit;++i){
		if(z)dp[x][y][z]+=dfs(c, x+1, y+(i==d), z);
		else dp[x][y][z]+=dfs(c, x+1, y+(i==d), i<limit);
	}
	return dp[x][y][z];
}

int main(){
	cin>>n>>m>>k>>d;
	string s1=to_string(m);
	string s2=to_string(n-1ll);
	memset(dp, -1, sizeof(dp));
	int ans=dfs(s1);
	memset(dp, -1, sizeof(dp));
	cout<<ans-dfs(s2)<<"\n";
	return 0;
}
