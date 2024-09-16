// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

void counting_sort(vector<pair<pair<int, int>, int>>& a, int side){
    int n=(int)a.size();
    vector<vector<pair<pair<int, int>, int>>> buckets(n);
    for(int i=0;i<n;++i){
        if(side==0){
            buckets[a[i].first.first].push_back(a[i]);
        }else{
            buckets[a[i].first.second].push_back(a[i]);
        }
    }
    int i=0;
    for(auto x:buckets){
        for(auto y:x){
            a[i]=y;i++;
        }
    }
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
        vector<pair<pair<int, int>, int>> tmp;
        for(int i=0;i<n;++i){
            tmp.push_back({{c[i], c[(i+(1<<k))%n]}, i});
        }
        counting_sort(tmp, 1);
        counting_sort(tmp, 0);

        for(int i=0;i<n;++i)p[i]=tmp[i].second;
        c[p[0]]=0;
        for(int i=1;i<n;++i){
            if(tmp[i].first==tmp[i-1].first){
                c[p[i]]=c[p[i-1]];
            }else{
                c[p[i]]=c[p[i-1]]+1;
            }
        }

        k++;
    }

    for(auto x:p)cout<<x<<" ";cout<<"\n";
    return 0;
}
