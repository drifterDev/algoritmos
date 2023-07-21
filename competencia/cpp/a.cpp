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


ll gcd(ll a, ll b) {
    while (b) {
        a %= b;
        swap(a, b);
    }
    return a;
}

ll ranas(vl& nums, ll n) {
    ll mayor = 0;
    for (ll i = 2; i <= n; i++) {
        ll count = 0;
        if (nums[i] > n) {
            break;
        }
        for (ll num : nums) {
            if(num>n){
                break;
            }
            if (num==1){
                count++;
                continue;
            }
            if (gcd(i, num) > 1) {
                count++;
            }
        }
        mayor = max(mayor, count);
    }

    return mayor;
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll cases;cin >> cases;
    for (ll i = 0; i < cases; i++) {
        ll n;cin >> n;
        vl nums(n,0);
        for (ll j = 0; j < n; j++) {
            cin >> nums[j];
        }
        sort(nums.begin(), nums.end());
        ll res=ranas(nums, n);
        cout <<res << endl;
    }
    return 0;
}


