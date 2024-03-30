// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
typedef long long ll;
const double EPS = 1e-9;

struct Point{
	ll x,y;
	Point(): x(0),y(0){}
	Point(ll _x,ll _y): x(_x),y(_y){}
	bool operator == (Point other) const{
		return x-other.x==0 && y-other.y==0;
	};
};

// Lado respecto una linea pq
int ccw(Point p,Point q,Point r){
	// Devuelve 1 (izquierda), -1 (derecha), 0 (colineal)
	double res=(q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x);
	if(fabs(res)<EPS)return 0;
	return res>0?1:-1;
}
 
bool cw(Point a, Point b, Point c, bool include_collinear){
	int o=ccw(a, b, c);
	return o<0 || (include_collinear && o==0);
}
 
bool collinear(Point a, Point b, Point c){return ccw(a, b, c)==0;}
 
double dist(Point p1, Point p2){
	return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double angle(Point a, Point o, Point b){
	// angulo AOB
	double cos_theta=(dist(o,a)*dist(o,a)+dist(o,b)*dist(o,b)-dist(a,b)*dist(a,b))/(2*dist(o,a)*dist(o,b));
	return acos(cos_theta)*(180/M_PI);
}

ll cross(Point a, Point b, Point c){
	return (b.x-a.x)*(c.y-a.y)-(b.y-a.y)*(c.x-a.x);
}

struct Poligono{
	vector<Point> P;
	Poligono(){}
	Poligono(vector<Point> _P): P(_P){}

	double perimeter(){
		double result=0.0;
		for(int i=0;i<sz(P)-1;i++)result+=dist(P[i],P[i+1]);
		return result;
	}
	
	// Area*2
	ll area(){
		ll res=0;
		for(int i=0;i<sz(P)-1;++i){
			res+=P[i].x*P[i+1].y-P[i+1].x*P[i].y;
		}
		return abs(res);
	}

	// Puntos dentro del Poligono y en la frontera
	pair<ll, ll> countPoints(){
		ll boundary=0,aux=0;
		for(int i=0;i<sz(P)-1;++i){
			if(P[i+1].x==P[i].x)boundary+=abs(P[i+1].y-P[i].y);
			else if(P[i+1].y==P[i].y)boundary+=abs(P[i+1].x-P[i].x);
			else boundary+=__gcd(abs(P[i+1].x-P[i].x),abs(P[i+1].y-P[i].y));
		}
		aux=area();
		return {(aux+2-boundary)/2, boundary};
	}

	bool Pointlineintersect(Point P1, Point P2, Point P3){
		ll tmp=cross(P2, P1, P3);
		if(tmp!=0)return false;
		return (min(P2.x, P3.x) <= P1.x && P1.x <= max(P2.x, P3.x))
				&& (min(P2.y, P3.y) <= P1.y && P1.y <= max(P2.y, P3.y));
	}

	void poinInPolygon(Point p0){
		int cnt=0;
		bool boundary=false;
		for(int i=0;i<sz(P)-1;++i){
			int j=i+1;
			if(Pointlineintersect(p0,P[i],P[j]))boundary=true;
			ll tmp1=cross(p0, P[i], P[j]);
			ll tmp2=cross(p0, P[j], P[i]);
			if(P[i].x<=p0.x && p0.x<P[j].x && tmp1<0)cnt++;
			else if(P[j].x<=p0.x && p0.x<P[i].x && tmp2<0)cnt++;
		}
		if(boundary)cout<<"BOUNDARY\n";
		else if(cnt&1)cout<<"INSIDE\n";
		else cout<<"OUTSIDE\n";
	}
};

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	Point p1(0,0),p2(0,1),p3(1,1),p4(1,0);
	Poligono p({p1,p2,p3,p4,p1});
	return 0;
}