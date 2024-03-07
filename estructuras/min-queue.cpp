#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first
typedef pair<int, int> ii;

struct minqueue{
  stack<ii> s1, s2;

  int mini(){
    int mini;
    if(s1.empty() || s2.empty())mini=s1.empty()?s2.top().S:s1.top().S;
    else mini=min(s1.top().S, s2.top().S);
    return mini;
  }

  void add(int x){
    int mini=s1.empty()?x:min(x, s1.top().S);
    s1.push({x, mini});
  }

  void remove(){
    if(s2.empty()){
      while(!s1.empty()){
        int x=s1.top().F;
        s1.pop();
        int mini=s2.empty()?x:min(x, s2.top().S);
        s2.push({x, mini});
      }
    }
    s2.pop();
  }
};