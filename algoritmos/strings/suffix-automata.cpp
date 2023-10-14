// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef vector<string> vs;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
char const MIN_CHAR='a';
int const ALPHA=26;
 
// O(n) construcción, O(n) memoria
struct SuffixAutomaton {
  int last;
  vi len,link,firstPos;
  vl cnt;
  vector<array<int,2>> order;
  vector<array<int, ALPHA>> nxt;
  SuffixAutomaton():last(0),len(1),link(1,-1),firstPos(1),cnt(1),nxt(1){}
  SuffixAutomaton(const string &s):SuffixAutomaton(){
    for (char c:s)
      extend(c);
  }

  int getIndex(char c){
    return c-MIN_CHAR;
  }
 
  void extend(char c) {
    int act=sz(len), i=getIndex(c),p=last;
    len.push_back(len[last]+1);
    link.emplace_back();
    cnt.push_back(1);
    firstPos.emplace_back(len[last]+1);
    order.push_back({len[act],act});
    nxt.emplace_back();
    while(p != -1 && !nxt[p][i]){
      nxt[p][i]=act;
      p=link[p];
    }
    if(p!=-1){
      int q=nxt[p][i];
      if(len[p]+1==len[q]){
        link[act]=q;
      }else{
        int clone=sz(len);
        len.push_back(len[p]+1);
        link.push_back(link[q]);
        firstPos.push_back(firstPos[q]);
        cnt.push_back(0);
        order.push_back({len[clone],clone});
        nxt.push_back(nxt[q]);
        while(p!=-1 && nxt[p][i]==q){
          nxt[p][i]=clone;
          p=link[p];
        }
        link[q]=link[act]=clone;
      }
    }
    last=act;
  }

  // El k-esimo substring lexicografico con repeticiones O(n+m)
  void kthSubstr(ll k){
    sort(order.rbegin(), order.rend());
    for(auto [_,u]:order) {
      cnt[link[u]]+=cnt[u];
    }
    vl dp(last+1);
    function<void(int)>dfs=[&](int u){
      dp[u]=cnt[u];
      for(int i=0;i<26;i++){
        if(!nxt[u][i])continue;
        int v=nxt[u][i];
        if (!dp[v])dfs(v);
        dp[u]+=dp[v]; 
      }
    };
    dfs(0);
    int u=0;
    while(k>0){
      for(int i=0;i<26;i++) {
        if(!nxt[u][i])continue;
        int v=nxt[u][i];
        if(k>dp[v]) {
          k-=dp[v];
        }else{
          cout<<(char)('a' + i);
          k-=cnt[v];
          u=v;
          break;
        }
      }
    }
  }

  // La primera aparición de t en s O(t)
  int firstMatching(const string &t) {
    int act=0;
    for(char c:t){
      int cc=c-'a';
      if(!nxt[act][cc])return -1;
      act=nxt[act][cc];
    }
    return firstPos[act]-sz(t)+1;
  }
};
 
int main() {
ios::sync_with_stdio(false);
cin.tie(0);
string s;cin>>s;
SuffixAutomaton sa(s);
return 0;
}