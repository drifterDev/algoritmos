// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<long long> w_s, v_s;
long long s,w=0,v=0;
int n;

void add(int i){
    w+=w_s[i];
    v+=v_s[i];
}

void remove(int i){
    w-=w_s[i];
    v-=v_s[i];
}

bool good(){
    return s>=w;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>s;
    w_s.assign(n,0);
    v_s.assign(n,0);
    for(int i=0;i<n;++i)cin>>w_s[i];
    for(int i=0;i<n;++i)cin>>v_s[i];
    int j=0;
    long long ans=0;
    for(int i=0;i<n;++i){
        add(i);
        while(!good()){
            remove(j);
            j++;
        }
        ans=max(ans, v);
    }
    cout<<ans<<"\n";
    return 0;
}
