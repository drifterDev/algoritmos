// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<int>& p, vector<int>& c){
    int n=(int)p.size();
    vector<int> cnt(n, 0);
    for(auto x:c){
        cnt[x]++;
    }

    vector<int> p2(n);
    vector<int> pos(n);
    pos[0]=0;
    for(int i=1;i<n;++i)pos[i]=pos[i-1]+cnt[i-1];
    for(auto x:p){
        p2[pos[c[x]]]=x;
        pos[c[x]]++;
    }
    p=p2;
}

bool comp(string& s, string& t, int id, bool equal){
    int n=(int)s.size();
    int m=(int)t.size();
    for(int i=id%n,j=0;j<m;++j,i=(i+1)%n){
        if(s[i]<t[j])return false;
        if(t[j]<s[i])return true;
    }
    return equal;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string s;cin>>s;
    s.push_back('$');
    int n=(int)s.size();
    vector<int> p(n);
    vector<int> c(n);

    vector<pair<char, int>> tmp;
    for(int i=0;i<n;++i)tmp.push_back({s[i], i});
    sort(tmp.begin(), tmp.end());

    for(int i=0;i<n;++i)p[i]=tmp[i].second;
    c[p[0]]=0;
    for(int i=1;i<n;++i){
        if(tmp[i].first==tmp[i-1].first){
            c[p[i]]=c[p[i-1]];
        }else{
            c[p[i]]=c[p[i-1]]+1;
        }
    }

    int k=0;
    while(n>=(1<<k)){
        for(int i=0;i<n;++i){
            p[i]=(p[i]-(1<<k)+n)%n;
        }

        counting_sort(p, c);

        vector<int> c2(n);
        c2[p[0]]=0;
        for(int i=1;i<n;++i){
            pair<int, int> op1={c[p[i]], c[(p[i]+(1<<k))%n]};
            pair<int, int> op2={c[p[i-1]], c[(p[i-1]+(1<<k))%n]};
            if(op1==op2){
                c2[p[i]]=c2[p[i-1]];
            }else{
                c2[p[i]]=c2[p[i-1]]+1;
            }
        }

        c=c2;
        k++;
    }

    string t;
    int q;cin>>q;
    while(q--){
        cin>>t;
        int l=0,r=n,m=(int)t.size();
        while(l<=r){
            int m=l+(r-l)/2;
            if(comp(s,t,p[m],true))r=m-1;
            else l=m+1;
        }
        bool f=true;
        r=min(n, r+1);
        if(p[r]<=n-m){
            for(int i=p[r],j=0;j<m;++j,++i){
                if(s[i]!=t[j]){
                    f=false;
                    break;
                }
            }
        }else f=false;
        cout<<(f?"Yes":"No")<<"\n";
    }
    return 0;
}
