// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
stack<int> s2;
stack<long long> a1,b1,a2,b2,act1,act2;
string s;
long long k;
int n;

void add(int i){
    s2.push(i);
    if(s2.size()==1){
        a2.push((s[i]=='a'));
        b2.push((s[i]=='b'));
        act2.push(0);
    }else{
        a2.push(a2.top() + (s[i]=='a'));
        b2.push(b2.top() + (s[i]=='b'));
        act2.push(act2.top() + (s[i]=='b'?a2.top():0));
    }
}

long long good(){
    if(act1.empty() && act2.empty())return 0;
    else if(!act1.empty() && act2.empty()){
        return act1.top();
    }else if(act1.empty() && !act2.empty()){
        return act2.top();
    }else{
        long long tmp=a1.top()*b2.top();
        return tmp+act1.top()+act2.top();
    }
}

void remove(){
    if(act1.empty()){
        long long ma=0,mb=0,mc=0;
        while(!s2.empty()){
            int i=s2.top();
            a1.push(ma + (s[i]=='a'));
            b1.push(mb + (s[i]=='b'));
            act1.push(mc + (s[i]=='a'?mb:0));
            ma=a1.top();
            mb=b1.top();
            mc=act1.top();
            s2.pop();
            a2.pop();
            b2.pop();
            act2.pop();
        }
    }
    a1.pop();
    b1.pop();
    act1.pop();
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    cin>>n>>k>>s;
    int ans=0,j=0;
    for(int i=0;i<n;++i){
        add(i);
        while(good()>k){
            remove();
            j++;
        }
        ans=max(ans, i-j+1);
    }
    cout<<ans<<"\n";
    return 0;
}
