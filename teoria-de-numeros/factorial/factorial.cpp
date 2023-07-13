#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;

//Forma 1
int fact[100];
void calculateFact() {
    fact[0] = 1;
    for (int i=1; i<100; i++) fact[i] = i * fact[i-1];
    return;
}

//Forma 2
int fact[100];
const int MOD = 10007;
void calculateFact() {
    fact[0] = 1;
    for (int i=1; i<100; i++) (fact[i] = i * fact[i-1]) % MOD;
    return;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}