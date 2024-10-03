#include <bits/stdc++.h>
using namespace std;
const int bits = 23;
int dp[1<<bits];

// O(n*2^n)
void sos(){
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
}
