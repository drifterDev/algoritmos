// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const double EPS = 1e-9;

struct Point{
	ll x,y;
	Point(): x(0),y(0){}
	Point(ll _x,ll _y): x(_x),y(_y){}
};

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

double deg_to_rad(double theta){
	return theta*(M_PI/180);
}

double dist(Point p1, Point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

Point rotate(Point p, double theta){
	// rotar por theta grados respecto al origen (0,0)
	double rad=deg_to_rad(theta);
	return Point(p.x*cos(rad)-p.y*sin(rad),p.x*sin(rad)+p.y*cos(rad));
}

double angle(Point a, Point o, Point b){
	// angulo AOB
	double cos_theta=(dist(o,a)*dist(o,a)+dist(o,b)*dist(o,b)-dist(a,b)*dist(a,b))/(2*dist(o,a)*dist(o,b));
	return acos(cos_theta)*(180/M_PI);
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	Point p1(-1,1),p2(1,1),p3(0,0);
	cout<<dist(p1,p2)<<"\n";
	cout<<rotate(p2,90).x<<" "<<rotate(p2,90).y<<"\n";
	cout<<angle(p1,p3,p2)<<"\n";
	return 0;
}