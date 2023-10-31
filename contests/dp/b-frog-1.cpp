// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

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
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

int dp(vi& nums,int n){
    if(n==2)return abs(nums[0]-nums[1]);
    else{
        int dpv[n];
        dpv[0]=nums[0];
        dpv[1]=abs(nums[0]-nums[1]);
        dpv[2]=min(dpv[1]+abs(nums[1]-nums[2]), abs(nums[0]-nums[2]));
        for(int i=3;i<n;i++){
            dpv[i]=min(dpv[i-2]+abs(nums[i-2]-nums[i]), dpv[i-1]+abs(nums[i-1]-nums[i]));
        }
        // for(int i=0;i<n;i++)cout<<dpv[i]<<" ";
        // cout<<"\n";
        return dpv[n-1];
    }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
int n;cin>>n;
vi nums(n,0);
for(int i=0;i<n;i++)cin>>nums[i];
int res=dp(nums,n);
cout<<res<<"\n";
return 0;
}