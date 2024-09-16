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

const int alpha = 14;

struct SuffixArray{ 
    vector<int> sa,rnk,lcp;
    vector<int> s;int n;
 
    void build(const vector<int> &_s){
        s=_s;s.push_back(0); 
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
        long long best=n-1,id=0,len=n-1;
        RMQ rmq;
        rmq.build(lcp);
        for(int i=1;i<n;++i){
            int l=i-1,r=n-2,lon=2;
            while(l<=r){
                int m=l+(r-l)/2;
                if(rmq.get(i-1, m)==lcp[i-1])l=m+1;
                else r=m-1;
            }
            l=max(i-1, l-1);
            lon+=l-(i-1);
            l=0,r=i-1;
            while(l<=r){
                int m=l+(r-l)/2;
                if(rmq.get(m, i-1)==lcp[i-1])r=m-1;
                else l=m+1;
            }
            r=min(i-1, r+1);
            lon+=(i-1)-r;
            long long act=1ll*lcp[i-1]*lon;
            if(best<act){
                best=act;
                id=sa[i];
                len=lcp[i-1];
            }
        }
        cout<<best<<"\n";
        cout<<len<<"\n";
        for(int i=0;i<len;++i)cout<<s[id+i]<<" ";
    }
};

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n,m;cin>>n>>m;
    vector<int> nums(n);
    for(int& x:nums)cin>>x;
    SuffixArray sa;
    sa.build(nums);
    sa.query();
    return 0;
}
