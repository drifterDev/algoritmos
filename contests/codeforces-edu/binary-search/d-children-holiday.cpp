// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<int> t,z,y,ans;
int n,m;

bool f(int x){
    int act=0;
    for(int i=0;i<n;++i){
        int x2=x;
        int tmp=x2/(t[i]*z[i]+y[i]);
        x2%=(t[i]*z[i]+y[i]);
        int mod=min(z[i], x2/(t[i]));
        ans[i]=min((tmp*z[i])+mod, m-act);
        act+=min((tmp*z[i])+mod, m-act);
        if(act==m)break;
    }
    return act>=m;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>m>>n;
    ans.assign(n,0);
    t.assign(n,0);
    z.assign(n,0);
    y.assign(n,0);
    for(int i=0;i<n;++i){
        cin>>t[i]>>z[i]>>y[i];
    }
    int l=0,r=1e7;
    while(l<=r){
        int m=l+(r-l)/2;
        if(f(m)){
            r=m-1;
        }else{
            l=m+1;
        }
    }
    cout<<r+1<<"\n";
    f(r+1);
    int act=0;
    for(int i=0;i<n;++i){
        cout<<min(ans[i], m-act)<<" ";
        act+=ans[i];
    }
    cout<<"\n";
    return 0;
}
