// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
stack<bitset<1001>> act1,act2;
stack<int> s1,s2;
int n,s;

void add(int x){
    s2.push(x);
    bitset<1001> bs;
    if(s2.size()!=1){
        bs=act2.top();
    }
    bs.set(0,true);
    act2.push(bs | (bs<<x));
}

bool good(){
    if(s1.empty() && s2.empty())return false;
    else if(!s1.empty() && s2.empty()){
        return (act1.top().test(s));
    }else if(s1.empty() && !s2.empty()){
        return (act2.top().test(s));
    }else{
        for(int i=0;i<=min(s,1000);++i){
            if(act1.top()[i] && act2.top()[s-i])return true;
        }
        return false;
    }
}

void remove(){
    if(s1.empty()){
        bitset<1001> bs;
        while(!s2.empty()){
            s1.push(s2.top());
            if(s1.size()!=1){
                bs=act1.top();
            }
            bs.set(0,true);
            act1.push(bs | (bs<<s1.top()));
            s2.pop();
            act2.pop();
        }
    }
    s1.pop();
    act1.pop();
}


int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>s;
    vector<int> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    int ans=INT_MAX;
    for(int i=0,j=0;i<n;++i){
        add(nums[i]);
        while(good() && j<=i){
            ans=min(ans, i-j+1);
            remove();
            j++;
        }
    }
    cout<<(ans==INT_MAX?-1:ans)<<"\n";
    return 0;
}
