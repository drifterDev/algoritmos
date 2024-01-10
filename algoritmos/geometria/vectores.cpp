// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
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

struct vecto{
  double x,y;
  vecto(double x,double y): x(x),y(y){}
  vecto(point p1, point p2): x(p2.x-p1.x),y(p2.y-p1.y){}

  // Escalar un vector
  vecto scale(double s){
    // s no negatico: 
    // <1 mas corto
    // 1 igual
    // >1 mas largo
    return vecto(x*s,y*s);
  }
};

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
  vecto oa=vecto(o,a);
  vecto ob=vecto(o,b);
  double ang=acos(dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
  // ang*=(180/M_PI); comentar para los poligonos
  return ang;
}

// Producto cruz
double cross(vecto a, vecto b){
  return (a.x*b.y)-(a.y*b.x);
}

// Lado respecto una linea pq
int ccw(point p,point q,point r){
  // Devuelve 1 (izquierda), -1 (derecha), 0 (colineal)
  double res=cross(vecto(p,q),vecto(p,r));
  if(fabs(res)<EPS)return 0;
  return res>0?1:-1;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  point p1(-1,1),p2(1,1),p3(0,0);
  vecto v1(p1,p2),v2(p3,p2);
  cout<<dot(v1,v2)<<"\n";
  cout<<norm_sq(v1)<<"\n";
  cout<<angle(p1,p3,p2)<<"\n";
  cout<<ccw(p1,p3,p2)<<"\n";
  return 0;
}