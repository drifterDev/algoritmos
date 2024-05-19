#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	// Triángulo de Pascal O(n^2)
	const int n=10;
	int pascal[n+1][n+1];
	pascal[0][0] = 1;
	for(int i=1;i<=n;++i){
		pascal[i][0]=pascal[i][i]=1;
		for (int k=1;k<i;++k)
			pascal[i][k]=pascal[i-1][k-1]+pascal[i-1][k];
	}

	// Visualizar
	for(int i=0;i<=n;i++){
		for(int k=0;k<=i;k++)cout<<pascal[i][k]<<" ";
		cout<<"\n";
	}
	return 0;
}