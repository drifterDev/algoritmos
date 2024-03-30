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
string abc="abcdefghijklmnopqrstuvwxyz";

vi prefix_function(string s){
  int n=len(s);
  vi pi(n);
  for(int i=1;i<n;i++) {
    int j=pi[i-1];
    while(j>0 && s[i]!=s[j])j=pi[j-1];
    if (s[i]==s[j])j++;
    pi[i]=j;
  }
  return pi;
}

int matches=0;
void kmp(string &t, string &p){ 
  vi phi=prefix_function(p);
  for(int i=0,j=0;i<sz(t);i++){
    while(j>0 && t[i]!=p[j])j=phi[j-1];
    if(t[i]==p[j])j++;
    if(j==sz(p)){
    //   cout<<i-j+1<<" "; 
      matches++;
      j=phi[j-1];
    }
  }
}

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);
string s1="#",s2;cin>>s1;
while(s1!="#"){
	cin>>s2;matches=0;
	string str1="",str2="";bool pass=false;
	for(int i=0;i<len(s1);i++){
		char act=s1[i];
		size_t found = abc.find(act);
		if(act=='/' || act=='*' || act=='+' || act=='-'){
			str1+="y";pass=false;
		}
		else if(found != string::npos){
			str1+="x";pass=false;
		}
		else if(act=='(' || act==')'){
			str1+=act;pass=false;
		}else if(pass)continue;
		else{
			str1+="x";pass=true;
		}
	}
	// cout<<str1<<"\n";
	pass=false;
	for(int i=0;i<len(s2);i++){
		char act=s2[i];
		size_t found = abc.find(act);
		if(act=='/' || act=='*' || act=='+' || act=='-'){
			str2+="y";pass=false;
		}else if(act=='(' || act==')'){
			str2+=act;pass=false;
		}else if(found != string::npos){
			str2+="x";pass=false;
		}else if(pass)continue;
		else{
			str2+="x";pass=true;
		}
	}
	// cout<<str2<<"\n";
	kmp(str2, str1);cout<<matches<<"\n";
	s1="#";cin>>s1;
}
return 0;
}