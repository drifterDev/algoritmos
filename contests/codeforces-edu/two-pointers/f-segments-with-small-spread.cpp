// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
stack<long long> s1,s2,min1,min2,max1,max2;
long long k;
int n;

void add(long long x){
    s2.push(x);
    if(s2.size()==1){
        max2.push(x);
        min2.push(x);
    }else{
        max2.push(max(x, max2.top()));
        min2.push(min(x, min2.top()));
    }
}

bool good(){
    if(s1.empty() && s2.empty())return false;
    if(!s1.empty() && !s2.empty()){
        long long m1 = max(max1.top(), max2.top());
        long long m2 = min(min1.top(), min2.top());
        return k>=m1-m2;
    }else if(s2.empty() && !s1.empty()){
        return k>=max1.top()-min1.top();
    }else if(!s2.empty() && s1.empty()){
        return k>=max2.top()-min2.top();
    }
}

void remove(){
    if(s1.empty()){
        long long m1=0,m2=LONG_LONG_MAX;
        while(!s2.empty()){
            s1.push(s2.top());
            max1.push(max(m1, s2.top()));
            min1.push(min(m2, s2.top()));
            m1=max1.top();
            m2=min1.top();
            s2.pop();
        }
    }
    s1.pop();
    min1.pop();
    max1.pop();
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k;
    vector<long long> nums(n);
    for(int i=0;i<n;++i)cin>>nums[i];
    long long ans=0,j=0;
    for(long long i=0;i<n;++i){
        add(nums[i]);
        while(!good()){
            remove();
            j++;
        }
        ans+=i-j+1;
        
    }
    cout<<ans<<"\n";
    return 0;
}
