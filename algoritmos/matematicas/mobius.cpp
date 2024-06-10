#include <bits/stdc++.h>
using namespace std;
const int maxn = 1e7;
int mobius[maxn+1];

// 1 if n is 1
// 0 if n has a squared prime factor
// (-1)^k if n is a product of k distinct prime factors
int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    mobius[1]=-1;
    for(int i=1;i<=maxn;++i){
        if(mobius[i]){
            mobius[i]=-mobius[i];
            for(int j=2*i;j<=maxn;j+=i){
                mobius[j]+=mobius[i];
            }
        }
    }
    return 0;
}