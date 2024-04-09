// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<int> tmp,res;
string s,t;
int n,m;

void add(char c){
    tmp[c-'a']++;
}

void remove(char c){
    tmp[c-'a']--;
}

bool good(){
    for(int i=0;i<26;++i){
        if(tmp[i]>res[i])return false;
    }
    return true;
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>m;
    cin>>s>>t;
    tmp.assign(26, 0);
    res.assign(26, 0);
    for(auto x:t){
        res[x-'a']++;
    }
    long long ans=0,j=0;
    for(long long i=0;i<n;++i){
        add(s[i]);
        while(!good()){
            remove(s[j]);
            j++;
        }
        ans+=i-j+1;
    }
    cout<<ans<<"\n";
    return 0;
}
