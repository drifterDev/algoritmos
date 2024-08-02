#include <bits/stdc++.h>
using namespace std;

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int bits=23;
    vector<int> a(1<<bits, -1);
	vector<int> dp(1<<bits, -1);
	for(int i=0;i<(1<<bits);++i){
        dp[i]=a[i];
    }
    // top - down
	for(int i=0;i<bits;++i){
		for(int s=0;s<(1<<bits);++s){
			if(s&(1<<i)){
				dp[s]+=dp[s^(1<<i)];
			}
		}
	} 
    // bottom - up
    for(int i=0;i<bits;++i){
		for(int s=(1<<bits)-1;s>=0;--s){
			if(s&(1<<i)){
				dp[s^(1<<i)]+=dp[s];
			}
		}
	}
    return 0;
}
