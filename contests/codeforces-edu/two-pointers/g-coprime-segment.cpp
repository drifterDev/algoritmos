// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
stack<long long> s1,s2,gcd1,gcd2;
int n;

void add(long long x){
    s2.push(x);
    if(s2.size()==1){
        gcd2.push(x);
    }else{
        gcd2.push(__gcd(gcd2.top(), x));
    }
}

bool good(){
    if(s1.empty() && s2.empty())return false;
    else if(!s1.empty() && s2.empty()){
        return gcd1.top()==1;
    }else if(s1.empty() && !s2.empty()){
        return gcd2.top()==1;
    }else{
        return __gcd(gcd2.top(), gcd1.top())==1;
    }
}

void remove(){
    if(s1.empty()){
        while(!s2.empty()){
            s1.push(s2.top());
            if(s1.size()==1)gcd1.push(s2.top());
            else gcd1.push(__gcd(gcd1.top(), s2.top()));
            gcd2.pop();
            s2.pop();
        }
    }
    s1.pop();
    gcd1.pop();
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n;
    vector<long long> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    long long ans=LONG_LONG_MAX,j=-1;
    for(long long i=0;i<n;++i){
        add(nums[i]);
        while(good()){
            ans=min(ans, i-j);
            remove();
            j++;
        }
    }
    cout<<(ans==LONG_LONG_MAX?-1:ans)<<"\n";
    return 0;
}
