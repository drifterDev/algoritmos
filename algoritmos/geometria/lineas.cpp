// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
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

// Linea forma ax+by+c=0
struct line{
  double a,b,c;
  line(){}
  line(double _a,double _b,double _c): a(_a),b(_b),c(_c){}
  // Creacion de linea con dos puntos
  // b=1 para lineas no verticales y b=0 para verticales
  line(point p1, point p2){
    if(fabs(p1.x-p2.x)<EPS){
      a=1.0;b=0.0;c=-p1.x;
    }else{
      a=-(double)(p1.y-p2.y)/(p1.x-p2.x);
      b=1.0;c=-(double)(a*p1.x)-p1.y;
    }
    norm();
  }

  void norm(){
    double z=sqrt(a*a+b*b);
    if(abs(z)>EPS)a/=z,b/=z,c/=z;
  }

  double dist(point p)const{return a*p.x+b*p.y+c;}
};

// Comprobacion de lineas paralelas
bool areParallel(line l1,line l2){
  return (fabs(l1.a-l2.a)<EPS) && (fabs(l1.b-l2.b)<EPS);
}

// Comprobacion de lineas iguales
bool areSame(line l1,line l2){
  return areParallel(l1,l2) && (fabs(l1.c-l2.c)<EPS);
}

// Distancia de un punto a una linea 
double distPointToLineaEq(line l, point p){
  return fabs(l.a*p.x + l.b*p.y + l.c)/sqrt(l.a*l.a+l.b*l.b);
}

bool areIntersect(line l1, line l2, point& p){
  if (areParallel(l1,l2)) return false;
  // resolver sistema 2x2
  p.x=(l2.b*l1.c-l1.b*l2.c)/(l2.a*l1.b-l1.a*l2.b);
  // comprobar linea vertical->div por cero
  if (fabs(l1.b)>EPS) p.y=-(l1.a*p.x + l1.c);
  else p.y=-(l2.a*p.x + l2.c);
  return true;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  point p1(-1,1),p2(1,1),p3(0,0);
  line l1(p1,p2),l2(p3,p2);
  cout<<distPointToLineaEq(l1,p3)<<"\n";
  point p4;
  areIntersect(l1,l2,p4);
  cout<<p4.x<<" "<<p4.y<<"\n";
  cout<<areParallel(l1,l2)<<"\n";
  cout<<areSame(l1,l2)<<"\n";
  cout<<l1.dist(p3)<<"\n";
  return 0;
}