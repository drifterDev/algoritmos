#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
ll t;cin>>t;
vector<bool> criba(t+2, true);
for(ll i=2;i<=t+1;i++){
  if(criba[i]){
    for(ll j=i*i;j<=t+2;j+=i)criba[j]=false;
  }
}
if(t>2)cout<<"2\n";
else cout<<"1\n";
for(int i=2;i<t+1;i++){
  if(criba[i])cout<<"1 ";
  else cout<<"2 ";
}
if(criba[t+1])cout<<"1\n";
else cout<<"2\n";
return 0;}

