// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef ll T;
struct line { T m, h; };
struct cht {
    vector<line> c;
    int pos = 0;
    
    T inter(line a, line b){
        T x = b.h-a.h, y = a.m-b.m;
        return x/y + (x%y ? (x>0)==(y>0) : 0); // == ceil(x/y)
    }
    
    void add(T m, T h) {
        line l = {m, h};
        if (c.size() && m == c.back().m) {
            l.h = min(h, c.back().h);
            c.pop_back(); if (pos) pos--;
        }
        while (c.size() > 1 && inter(c.back(), l) <= inter(c[c.size()-2], c.back())) {
            c.pop_back(); if (pos) pos--;
        }
        c.push_back(l);
    }
    
    inline bool fbin(T x, int m) { return inter(c[m], c[m+1]) > x; }
    
    T query(T x) {
        int l = 0, r = c.size();
        while (r-l > 1) {
            int m = (l+r)/2;
            if (fbin(x, m-1)) r = m;
            else l = m;
        }
        return c[l].m*x + c[l].h;
        while (pos > 0 && fbin(x, pos-1)) pos--;
        while (pos < (int)c.size()-1 && !fbin(x, pos)) pos++;
        return c[pos].m*x + c[pos].h;
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n;
    ll c;
    cin>>n>>c;
    vector<ll> h(n);
    for(int i=0;i<n;++i)cin>>h[i];
    vector<ll> dp(n,LONG_LONG_MAX);
    dp[0]=0;
    cht hull;
    hull.add(2*h[0], -(c+h[0]*h[0]));
    for(int i=1;i<n;++i){
        dp[i]=(h[i]*h[i])-hull.query(h[i]);
        hull.add(2*h[i], -(c+h[i]*h[i]+dp[i]));
    }
    cout<<dp[n-1]<<"\n";
    return 0;
}
