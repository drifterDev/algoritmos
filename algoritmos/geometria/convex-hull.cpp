// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define all(x) x.begin(),x.end()
#define PB push_back
const double EPS = 1e-9;
 
struct point{
  double x,y;
  point(): x(0),y(0){}
  point(double _x,double _y): x(_x),y(_y){}
  bool operator == (point other) const{
      return (fabs(x-other.x)<EPS) && (fabs(y-other.y)<EPS);
  };
  bool operator < (point other) const{
      return (x<other.x) || (fabs(x-other.x)<EPS && y<other.y);
  };
};

// Lado respecto una linea pq
int ccw(point p,point q,point r){
  // Devuelve 1 (izquierda), -1 (derecha), 0 (colineal)
  double res=(q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x);
  if(fabs(res)<EPS)return 0;
  return res>0?1:-1;
}
 
// imprime verdadero el punto c, esta a la derecha de la linea pb,
// tambien da true si son cololineales e include_collinear == true 
bool cw(point a, point b, point c, bool include_collinear){
  int o=ccw(a, b, c);
  return o<0 || (include_collinear && o==0);
}
 
bool collinear(point a, point b, point c){return ccw(a, b, c)==0;}
 
void convex_hull(vector<point>& a, bool include_collinear = false) {
  point p0=*min_element(all(a), [](point a, point b) {
    return make_pair(a.y, a.x)<make_pair(b.y, b.x);
  });
  sort(all(a), [&p0](const point& a, const point& b){
    int o=ccw(p0, a, b);
    if(o==0)
      return (p0.x-a.x)*(p0.x-a.x)+(p0.y-a.y)*(p0.y-a.y)
          < (p0.x-b.x)*(p0.x-b.x)+(p0.y-b.y)*(p0.y-b.y);
    return o<0;
  });
 
  // Busca donde empiezan los colineales (estan al final) e invierte su orden
  if (include_collinear) {
    int i=sz(a)-1;
    while(i>=0 && collinear(p0,a[i],a.back()))i--;
    reverse(a.begin()+i+1, a.end());
  }
  
  // Aplicacion de graham
  vector<point> st;
  for(int i=0;i<sz(a);i++){
    while(sz(st)>1 && !cw(st[sz(st)-2], st.back(), a[i], include_collinear))
      st.pop_back();
    st.PB(a[i]);
  }
  a=st;  
}
 
int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(0)<<fixed;
  int n;cin>>n;
  vector<point> points;
  for(int i=0;i<n;i++){
    double x,y;cin>>x>>y;
    points.PB(point(x,y));
  }
  convex_hull(points,true);
  cout<<sz(points)<<"\n";
  for(auto x:points)cout<<x.x<<" "<<x.y<<"\n";
  return 0;
}
