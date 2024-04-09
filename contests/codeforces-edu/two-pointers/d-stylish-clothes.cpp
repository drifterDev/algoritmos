// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
vector<int> res;
stack<int> s1,s2,max1,max2,min1,min2;

bool good(){
    for(int i=0;i<4;++i){
        if(res[i]==0)return false;
    }
    return true;
}

int value(){
    if(s1.empty() && s2.empty())return INT_MAX;
    else if(!s1.empty() && s2.empty()){
        return max1.top()-min1.top();
    }else if(s1.empty() && !s2.empty()){
        return max2.top()-min2.top();
    }else{
        int m1=max(max1.top(), max2.top());
        int m2=min(min1.top(), min2.top());
        return m1-m2;
    }
}

void add(int x){
    s2.push(x);
    int m1=(s2.size()==1?0:max2.top());
    int m2=(s2.size()==1?INT_MAX:min2.top());
    max2.push(max(x, m1));
    min2.push(min(x, m2));
}

void remove(){
    if(s1.empty()){
        int m1=0,m2=INT_MAX;
        while(!s2.empty()){
            s1.push(s2.top());
            max1.push(max(m1, s1.top()));
            min1.push(min(m2, s1.top()));
            m1=max1.top();
            m2=min1.top();
            s2.pop();
            max2.pop();
            min2.pop();
        }
    }
    s1.pop();
    min1.pop();
    max1.pop();
}

int main(){
    ios::sync_with_stdio(false);cin.tie(nullptr);
    int n1,n2,n3,n4;
    cin>>n1;
    vector<pair<int, int>> nums;
    res.assign(4,0);
    for(int a,i=0;i<n1;++i){
        cin>>a;nums.push_back({a,0});
    }
    cin>>n2;
    for(int a,i=0;i<n2;++i){
        cin>>a;nums.push_back({a,1});
    }
    cin>>n3;
    for(int a,i=0;i<n3;++i){
        cin>>a;nums.push_back({a,2});
    }
    cin>>n4;
    for(int a,i=0;i<n4;++i){
        cin>>a;nums.push_back({a,3});
    }
    sort(nums.begin(), nums.end());
    int ans=INT_MAX,id1=0,id2=0;
    for(int i=0,j=0;i<n1+n2+n3+n4;++i){
        add(nums[i].first);
        res[nums[i].second]++;
        while(good()){
            int tmp=value();
            if(tmp<ans){
                ans=tmp;
                id1=j;id2=i;
            }
            remove();
            res[nums[j].second]--;
            j++;
        }
    }
    vector<int> tmp(4,-1);
    for(int i=id1;i<=id2;++i){
        if(tmp[nums[i].second]!=-1)continue;
        tmp[nums[i].second]=nums[i].first;
    }
    for(auto x:tmp)cout<<x<<" ";
    cout<<"\n";
    return 0;
}
