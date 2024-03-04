// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
typedef vector<int> vi;

// Maximizar la ecuación c1*x1 + c2*x2 + c3*x3 ...
// sujeta a restricciones a11*x1 + a12*x2 <= b1, a22*x2 + a23*x3 <= b2 ...
// A: matriz de ecuaciones, contiene los coeficientes de cada variable
// B: vector con los coeficientes de las restricciones
// C: costos de las variables
// Retorna valor optimo y valores de las variables

const double EPS = 1e-6;

struct simplex {
  vi X, Y;
  vector<vector<double>> a;
  vector<double> b, c;
  double z;
  int n, m;

  void pivot(int x, int y){
    swap(X[y], Y[x]);
    b[x]/=a[x][y];
    for(int i=0;i<m;++i){
      if(i!=y)a[x][i]/=a[x][y];
    }
    a[x][y]=1/a[x][y];
    for(int i=0;i<n;++i){
      if(i!=x && abs(a[i][y])>EPS){
        b[i]-=a[i][y]*b[x];
        for(int j=0;j<m;j++){
          if(j != y)a[i][j]-=a[i][y]*a[x][j];
        }
        a[i][y]=-a[i][y]*a[x][y];
      }
    }
    z+=c[y]*b[x];
    for(int i=0;i<m;++i){
      if(i != y)c[i]-=c[y]*a[x][i];
    }
    c[y]=-c[y]*a[x][y];
  }

  simplex(vector<vector<double>> &A,vector<double> &B,vector<double> &C){
    a=A;b=B;c=C;
    n=b.size();m=c.size();z= 0.0;
    X.resize(m);iota(X.begin(),X.end(),0);
    Y.resize(n);iota(Y.begin(),Y.end(),m);
  }

  pair<double, vector<double>> maximize(){
    while(true){
      int x=-1,y=-1;
      double mn=-EPS;
      for(int i=0;i<n;++i){
        if(b[i]<mn)mn=b[i],x=i;
      }
      if(x<0)break;
      for(int i=0;i<m;++i){
        if(a[x][i]<-EPS){ 
          y=i; 
          break; 
        }
      }
      assert(y>=0); // no hay solucion para Ax<=b
      pivot(x,y);
    }
    while(true){
      double mx=EPS;
      int x=-1,y=-1;
      for(int i=0;i<m;++i){
        if(c[i]>mx)mx=c[i],y=i;
      }
      if(y<0)break;
      double mn=1e200;
      for(int i=0;i<n;++i){
        if(a[i][y]>EPS && b[i]/a[i][y]<mn)
        mn=b[i]/a[i][y],x=i;
      }
      assert(x>=0); // unbounded
      pivot(x,y);
    }
    vector<double> r(m);
    for(int i=0;i<n;++i){
      if(Y[i]<m)r[Y[i]]=b[i];
    }
    return {z,r};
  }
};

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  vector<vector<double>> A = {
    {5,2,6},
    {2,1,0.5},
    {1,0,0},
    {0,0,-1},
    {-1,0,0},
    {0,-1,0},
    {0,0,-1},
  };
  vector<double> B = {90,50,11,-3,0,0,0};
  vector<double> C = {3,2,1};
  simplex s(A,B,C);
  auto ans = s.maximize();
  cout<<ans.first<<"\n";
  print(ans.second);
  return 0;
}