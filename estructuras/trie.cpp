// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define trace(x) cerr<<#x<<"="<<x<<'\n'
#define sz(arr) ((int) arr.size())
#define len(str) ((int) str.length())
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define PB push_back
typedef vector<string> vs;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef long long ll;
typedef vector<ll> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[8] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[8] = {0, 1, 1, 1, 0, -1, -1, -1};

class TrieNode{
public:
  map<char,TrieNode*> children;
  bool isEnd=false;
  TrieNode():isEnd(false){}
  ~TrieNode(){
    for(auto& child:children)delete child.second;
  }
};

void insert(TrieNode& root,const string& word){
  TrieNode* node=&root;
  for(int i=0;i<len(word);++i){
    char c=word[i];
    if(!node->children.count(c)){
      node->children[c]=new TrieNode();                        
    }            
    node=node->children[c];                                            
  }       
  node->isEnd=true;                                                           
}

void printTrie(const TrieNode& root,string word=""){
  if(root.isEnd)cout<<word<<"\n";
  for(auto it:root.children){
    printTrie(*it.S,word+it.F);
  }
}

bool search(const TrieNode& root,const string& word){
  const TrieNode* node=&root;
  for(int i=0;i<len(word);i++){
    char c=word[i];
    auto it=node->children.find(c);
    if (it==node->children.end())return false;
    node=it->S;
  }       
  return node->isEnd;                            
}

void deleteWord(TrieNode& root,const string& word){
  TrieNode* node=&root;
  for(int i=0;i<len(word);i++){
    char c=word[i];
    auto it=node->children.find(c);
    if (it==node->children.end())return;
    node=it->S;
  }       
  node->isEnd=false;                            
}

void deleteWordWithNodes(TrieNode& root,const string& word){
  TrieNode* node=&root;
  stack<TrieNode*> st;
  for(int i=0;i<len(word);i++){
    char c=word[i];
    auto it=node->children.find(c);
    if (it==node->children.end())return;
    st.push(node);
    node=it->S;
  }       
  node->isEnd=false;
  while(!st.empty()){
    TrieNode* node=st.top();st.pop();
    if(node->children.empty() && !node->isEnd){
      delete node;
    }
  }                            
}

void dfs(const TrieNode& root, int& count, multiset<string>& res, string word = ""){
  if(root.isEnd)res.insert(word);
  for(auto it:root.children){
    dfs(*it.S,count,res,word+it.F);
  }
}

int startWithPrefix(const TrieNode& root,const string& prefix, multiset<string>& res){
  const TrieNode* node=&root;
  int count=0;
  for(int i=0;i<len(prefix);i++){
    char c=prefix[i];
    auto it=node->children.find(c);
    if (it==node->children.end())return count;
    node=it->S;
  }      
  dfs(*node,count, res); 
  return count;                           
}

string longestCommonPrefix(const TrieNode& root){
  string res="";
  const TrieNode* node=&root;
  while(node && !node->isEnd && sz(node->children)==1){
    auto it=node->children.begin();
    res+=it->F;
    node=it->S;
  }
  return res;
}

int main() {
ios::sync_with_stdio(false);
cin.tie(0);
TrieNode* root=new TrieNode();
insert(*root,"hola");
insert(*root,"holas");
insert(*root,"hol");
cout<<search(*root,"hola")<<"\n";
deleteWord(*root,"hola");
cout<<search(*root,"hola")<<"\n";
delete root;
return 0;
}