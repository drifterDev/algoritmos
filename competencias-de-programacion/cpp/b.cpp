#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;


void criba(vector<vi>& lista, int tope){
  for(int i=2;i<=tope;i++){
    if(sz(lista[i])==0){
      for(int k=2;k*i<=tope;k++)lista[k*i].push_back(i);
    }
  }
//   for(int i=0;i<=tope;i++){
//     cout<<i<<" = ";
//     for (const int &elemento:lista[i])cout<<elemento<<" ";
//     cout<<"\n";
//   }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
ll n;cin>>n;
vector<vi> crib(n+2, vi());
criba(crib, n+1);
cout<<(n+1)/2<<"\n";
unordered_map<int, int> factos;
for(int i=2;i<=n+1;i++){
    if(sz(crib[i])==0){
        factos[i]=1;
        cout<<"1 ";
    }
    else{
        int ulti=0,ultimo=0;
        for(const int& fac:crib[i]){
            if(ulti<=factos[fac]){
                ulti=factos[fac]+1;
                ultimo=fac;
            }
        }
        factos[ultimo]+=1;
        cout<<ulti<<" ";
    }
}
return 0;
}