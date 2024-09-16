// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

typedef int T;
T oper(T a, T b){return min(a,b);}
struct RMQ {
    vector<vector<T>> table;
    void build(vector<T>& v){
        int n=v.size();
        table.assign(20, vector<T>(n));
        for(int i=0;i<n;++i)table[0][i]=v[i];
        for(int j=1;(1<<j)<=n;++j)
            for(int i=0;i+(1<<(j-1))<n;++i)
                table[j][i]=oper(table[j-1][i],table[j-1][i+(1<<(j-1))]);
    }
    T get(int l, int r){
        int j=31-__builtin_clz(r-l+1);
        return oper(table[j][l], table[j][r-(1<<j)+1]);
    }
};

const int alpha = 256;

struct SuffixArray{ 
    vector<int> sa,rnk,lcp;
    string s;int n;
 
    void build(const string &_s){
        s=_s;s.push_back((char)32); 
        n=(int)s.size();
        sa.assign(n, 0);
        rnk.assign(n, 0);
        lcp.assign(n-1, 0);
        buildSA();
    }
 
    void buildSA() {
        vector<int> cnt(max(alpha, n),0);
        for(int i=0;i<n;++i)cnt[s[i]]++;
        for(int i=1;i<max(alpha,n);++i)cnt[i]+=cnt[i-1];
        for(int i=n-1;i>=0;--i)sa[--cnt[s[i]]]=i;
        for(int i=1;i<n;++i)rnk[sa[i]]=rnk[sa[i-1]]+(s[sa[i]]!=s[sa[i-1]]);
 
        for(int k=1;k<n;k*=2){
            vector<int> nsa(n),nrnk(n),ncnt(n);
            for(int i=0;i<n;++i)sa[i]=(sa[i]-k+n)%n;
            for(int i=0;i<n;++i)ncnt[rnk[i]]++;
            for(int i=1;i<n;++i)ncnt[i]+=ncnt[i-1];
            for(int i=n-1;i>=0;--i)nsa[--ncnt[rnk[sa[i]]]]=sa[i];
            for(int i=1;i<n;++i){
                pair<int,int> op1={rnk[nsa[i]], rnk[(nsa[i]+k)%n]};
                pair<int,int> op2={rnk[nsa[i-1]], rnk[(nsa[i-1]+k)%n]};
                nrnk[nsa[i]]=nrnk[nsa[i-1]]+(op1!=op2);
            }
            swap(sa, nsa);swap(rnk, nrnk);
        }

        for(int i=0,k=0;i<n-1;++i){
            while(s[i+k]==s[sa[rnk[i]-1]+k])k++;
            lcp[rnk[i]-1]=k;
            if(k)k--;
        }
    }

    void query(){
        RMQ rmq;
        rmq.build(lcp);
        long long ans=0;
        vector<int> cnt(n, 1);
        for(int i=1;i<n;++i){
            ans+=n-1-sa[i];
            if(lcp[i-1]==0)continue;
            if(rmq.get(i-1, n-2)==lcp[i-1]){
                ans+=1ll*lcp[i-1]*cnt[i]*(n-i);
                continue;
            }
            int l=i,r=n-2;
            while(l<=r){
                int m=l+(r-l)/2;
                if(rmq.get(i-1, m)==lcp[i-1])l=m+1;
                else r=m-1;
            }
            ans+=1ll*lcp[i-1]*cnt[i]*(l-i+1);
            cnt[l+1]+=cnt[i];
        }
        cout<<ans<<"\n";
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    string s;cin>>s;
    SuffixArray sa,sr;
    sa.build(s);
    sa.query();
    return 0;
}
