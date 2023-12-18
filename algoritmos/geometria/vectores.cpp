// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;

struct point{
    ll x,y;
    point(ll x,ll y): x(x),y(y){}
};

struct vecto{
  double x,y;
  vecto(double x,double y): x(x),y(y){}
};

// Puntos a vector
vecto tovecto(point a,point b){
  return vecto(b.x-a.x , b.y-a.y);
}

// Escalar un vector
vecto scale(vecto v, double s){
  // s no negatico: 
  // <1 mas corto
  // 1 igual
  // >1 mas largo
  return vecto(v.x*s,v.y*s);
}

// Trasladar p segun v
// p(0,0) v(1,1) -> p(1,1)
point traslate(point p, vecto v){
  return point(p.x+v.x , p.y+v.y);
}

// Producto Punto
double dot(vecto a,vecto b){
  return (a.x*b.x + a.y*b.y);
}

// Cuadrado de la norma (distancia al cuadrado)
double norm_sq(vecto v){
  return sqrt(v.x*v.x + v.y*v.y);
}

// Angulo formado por aob
double angle(point a, point o, point b){
  vecto oa=tovecto(o,a);
  vecto ob=tovecto(o,b);
  double ang=acos(dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
  return ang*(180/M_PI);
}

// Producto cruz
double cross(vecto a, vecto b){
  return (a.x*b.y)-(a.y*b.x);
}

// Lado respecto una linea pq
int ccw(point p,point q,point r){
  // Devuelve 1 (izquierda), -1 (derecha), 0 (colineal)
  double res=cross(tovecto(p,q),tovecto(p,r));
  if(fabs(res)<EPS)return 0;
  return res>0?1:-1;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  point p1(-1,1);
  vecto v1(2,2);
  cout<<traslate(p1,v1).x<<" "<<traslate(p1,v1).y<<"\n";
  vecto v2(4,2),v3(1,2);
  cout<<cross(v2,v3)<<"\n";
  point p2(1,1),p3(0,0);
  cout<<angle(p1,p3,p2)<<"\n";
  cout<<norm_sq(v1)<<"\n";
  cout<<ccw(p1,p2,p3)<<"\n"; // derecha
  cout<<ccw(p1,p3,p2)<<"\n"; // izquierda
  point p4(0,1);
  cout<<ccw(p1,p2,p4)<<"\n"; // colineal
  return 0;
}