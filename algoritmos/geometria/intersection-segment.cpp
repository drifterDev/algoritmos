// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
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

struct Line{
	double a,b,c;
	Line(){}
	Line(double _a,double _b,double _c): a(_a),b(_b),c(_c){}
	Line(Point p1, Point p2){
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

	double dist(Point p)const{return a*p.x+b*p.y+c;}
};

// determinante de una matriz 2x2
double det(double a, double b, double c, double d){
	return a*d-b*c;
}

// verifica si x esta entre l y r
inline bool betw(double l, double r, double x){
	return min(l,r)<=x+EPS && x<=max(l,r)+EPS;
}

inline bool helper(double a, double b, double c, double d){
	if(a>b)swap(a,b);
	if(c>d)swap(c,d);
	return max(a,c)<=min(b,d)+EPS;
}

bool intersect(Point a, Point b, Point c, Point d, Point& left, Point& right){
	if (!helper(a.x,b.x,c.x,d.x) || !helper(a.y,b.y,c.y,d.y))return false;
	Line m(a,b),n(c,d);
	double zn=det(m.a,m.b,n.a,n.b);
	if (abs(zn)<EPS){
		if(abs(m.dist(c))>EPS || abs(n.dist(a))>EPS)return false;
		if(b<a)swap(a,b);
		if(d<c)swap(c,d);
		left=max(a,c);
		right=min(b,d);
		return true;
	} else {
		left.x=right.x=-det(m.c, m.b, n.c, n.b)/zn;
		left.y=right.y=-det(m.a, m.c, n.a, n.c)/zn;
		return betw(a.x,b.x,left.x) && betw(a.y,b.y,left.y) &&
						betw(c.x,d.x,left.x) && betw(c.y,d.y,left.y);
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	int t;cin>>t;
	while(t--){
		Point p1,p2,p3,p4;
		cin>>p1.x>>p1.y>>p2.x>>p2.y>>p3.x>>p3.y>>p4.x>>p4.y;
		Point left,right;
		if(intersect(p1,p2,p3,p4,left,right)){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
	}
	return 0;
}