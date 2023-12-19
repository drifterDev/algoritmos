#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define PB push_back
typedef long long ll;
const double EPS = 1e-9;

// Crear un poligono la idea es crearlo con algun orden ya sea horario o anti-horario y debe cerrarse
vector<point> Poligono; 

// Perimetro de un poligono
double perimeter(const vector<point>& P){
  double result=0.0;
  for(int i=0;i<sz(P)-1;i++)result+=dist(P[i],P[i+1]);
  return result;
}

// Area de un poligono
double area(const vector<point>& P){
  // la mitad del determinante
  double result=0.0,x1,y1,x2,y2;
  for(int i=0;i<sz(P)-1;i++){
    x1=P[i].x; 
    x2=P[i+1].x;
    y1=P[i].y; 
    y2=P[i+1].y;
    result+=(x1*y2-x2*y1);
  }
  return fabs(result/2.0);
}

// Comprobacion de si es Convexto un poligono
bool isConvex(const vector<point>& P){
  int sz=sz(P);
  if(sz<=3)return false;
  bool isLeft=ccw(P[0],P[1],P[2]);
  for(int i=1;i<sz-1;i++)
    if(ccw(P[i],P[i+1],P[(i+2)==sz?1:i+2])!=isLeft)return false;
  return true;
}

// Comprobar si un punto esta dentro de un poligono
bool inPoligono(point pt, const vector<point>& P){
  // P puede ser concavo/convexo
  if(sz(P)==0)return false;
  double sum=0;
  for(int i=0;i<sz(P)-1;i++){
    if(ccw(pt,P[i],P[i+1])==1)sum+=angle(P[i],pt,P[i+1]); // izquierda/anti-horario
    else sum-=angle(P[i],pt,P[i+1]);// derecha/horario
  }
  return fabs(fabs(sum)-2*M_PI)<EPS;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  point p1(1,0),p2(1,1),p3(0,1),p4(0,0);
  Poligono.PB(p1);
  Poligono.PB(p2);
  Poligono.PB(p3);
  Poligono.PB(p4);
  Poligono.PB(p1);
  cout<<perimeter(Poligono)<<"\n";
  cout<<area(Poligono)<<"\n";
  cout<<isConvex(Poligono)<<"\n";
  cout<<inPoligono(point(0.5,0.5),Poligono)<<"\n";
  cout<<inPoligono(point(1,-1),Poligono)<<"\n";
  return 0;
}