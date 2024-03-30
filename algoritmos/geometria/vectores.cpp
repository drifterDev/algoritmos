// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;

struct Point{
	double x,y;
	Point(): x(0),y(0){}
	Point(double _x,double _y): x(_x),y(_y){}
	bool operator == (Point other) const{
			return (fabs(x-other.x)<EPS) && (fabs(y-other.y)<EPS);
	};
	bool operator < (Point other) const{
			return (x<other.x) || (fabs(x-other.x)<EPS && y<other.y);
	};
};

struct Vecto{
	double x,y;
	Vecto(double x,double y): x(x),y(y){}
	Vecto(Point p1, Point p2): x(p2.x-p1.x),y(p2.y-p1.y){}

	// Escalar un Vector
	Vecto scale(double s){
		// s no negatico: 
		// <1 mas corto
		// 1 igual
		// >1 mas largo
		return Vecto(x*s,y*s);
	}
};

// Trasladar p segun v
// p(0,0) v(1,1) -> p(1,1)
Point traslate(Point p, Vecto v){
	return Point(p.x+v.x , p.y+v.y);
}

// Producto Punto
double dot(Vecto a,Vecto b){
	return (a.x*b.x + a.y*b.y);
}

// Cuadrado de la norma (distancia al cuadrado)
double norm_sq(Vecto v){
	return sqrt(v.x*v.x + v.y*v.y);
}

// Angulo formado por aob
double angle(Point a, Point o, Point b){
	Vecto oa=Vecto(o,a);
	Vecto ob=Vecto(o,b);
	double ang=acos(dot(oa,ob)/sqrt(norm_sq(oa)*norm_sq(ob)));
	// ang*=(180/M_PI); comentar para los poligonos
	return ang;
}

// Producto cruz
double cross(Vecto a, Vecto b){
	return (a.x*b.y)-(a.y*b.x);
}

// Lado respecto una linea pq
int ccw(Point p,Point q,Point r){
	// Devuelve 1 (izquierda), -1 (derecha), 0 (colineal)
	double res=cross(Vecto(p,q),Vecto(p,r));
	if(fabs(res)<EPS)return 0;
	return res>0?1:-1;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	Point p1(-1,1),p2(1,1),p3(0,0);
	Vecto v1(p1,p2),v2(p3,p2);
	cout<<dot(v1,v2)<<"\n";
	cout<<norm_sq(v1)<<"\n";
	cout<<angle(p1,p3,p2)<<"\n";
	cout<<ccw(p1,p3,p2)<<"\n";
	return 0;
}