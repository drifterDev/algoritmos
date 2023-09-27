// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;

// The number of balanced bracket sequences with only one bracket type
// can be calculated using the Catalan numbers.The number of balanced bracket 
// sequences of length 2n (n pairs of brackets)is :
// (1/(n+1))C(2n,n)

// If we allow k types of brackets, then each pair be of any of the k
// types(independently of the others), thus the number of balanced 
// bracket sequences is:
// (1/(n+1))C(2n, n)(k^n)

// Let  n be the number of bracket pairs in the sequence. We have to find the  
// k-th balanced sequence in lexicographically sorted list of all 
// balanced sequences for a given  k .

// One bracket type
string kth_balanced(int n, int k) {
vector<vi> d(2*n+1,vi(n+1,0));
d[0][0]=1;
for(int i=1;i<=2*n;i++) {
  d[i][0]=d[i-1][1];
  for (int j=1;j<n;j++)d[i][j]=d[i-1][j-1]+d[i-1][j+1];
  d[i][n]=d[i-1][n-1];
}

string ans;
int depth=0;
for(int i=0;i<2*n;i++){
  if (depth+1<=n&&d[2*n-i-1][depth+1]>=k) {
    ans+='(';depth++;
  }else{
    ans+=')';
    if(depth+1<=n)k-=d[2*n-i-1][depth+1];
    depth--;
  }
}return ans;
}

// Two bracket types
string kth_balanced2(int n, int k) {
vector<vi> d(2*n+1, vi(n+1, 0));
d[0][0]=1;
for(int i=1;i<=2*n;i++) {
  d[i][0]=d[i-1][1];
  for(int j=1;j<n;j++)d[i][j]=d[i-1][j-1]+d[i-1][j+1];
  d[i][n]=d[i-1][n-1];
}

string ans;
int shift,depth=0;
stack<char> st;
for(int i=0;i<2*n;i++){
  // '('
  shift=((2*n-i-1-depth-1)/2);
  if (shift>=0&&depth+1<=n) {
    int cnt=d[2*n-i-1][depth+1]<<shift;
    if(cnt>=k){
      ans += '(';st.push('(');
      depth++;continue;
    }
    k-=cnt;
  }

  // ')'
  shift=((2*n-i-1-depth+1)/2);
  if (shift>=0&&depth&&st.top()=='('){
    int cnt=d[2*n-i-1][depth-1]<<shift;
    if (cnt>=k) {
      ans+=')';st.pop();
      depth--;continue;
    }
    k-=cnt;
  }

  // '['
  shift=((2*n-i-1-depth-1)/2);
  if (shift>=0&&depth+1<=n) {
    int cnt=d[2*n-i-1][depth+1]<<shift;
    if(cnt>=k){
      ans+='[';st.push('[');
      depth++;continue;
    }
    k-=cnt;
  }

  // ']'
  ans+=']';st.pop();depth--;
}return ans;
}

int main(){
ios::sync_with_stdio(false);
cin.tie(0);
int n = 3; // Número de pares de paréntesis
for(int k=1;k<=5;k++) cout<<"La "<<k<<"-ésima secuencia balanceada de "<<n<<" pares de paréntesis es: "<<kth_balanced(n, k)<<"\n";
cout<<"\n";
for(int k=1;k<=5;k++)cout<<"La "<<k<<"-ésima secuencia balanceada de "<<n<<" pares de paréntesis es: "<<kth_balanced2(n, k)<<"\n";
return 0;
}