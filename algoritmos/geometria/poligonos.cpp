#include <bits/stdc++.h>
using namespace std;
#define watch(x) cout<<#x<<"="<<x<<'\n'
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
#define S second
#define F first
typedef long long ll;
typedef vector<ll> vl;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
const double EPS = 1e-9;

struct point{
  ll x,y;
  point(): x(0),y(0){}
  point(ll _x,ll _y): x(_x),y(_y){}
  bool operator == (point other) const{
    return x-other.x==0 && y-other.y==0;
  };
};

// Lado respecto una linea pq
int ccw(point p,point q,point r){
  // Devuelve 1 (izquierda), -1 (derecha), 0 (colineal)
  double res=(q.x-p.x)*(r.y-p.y)-(q.y-p.y)*(r.x-p.x);
  if(fabs(res)<EPS)return 0;
  return res>0?1:-1;
}
 
bool cw(point a, point b, point c, bool include_collinear){
  int o=ccw(a, b, c);
  return o<0 || (include_collinear && o==0);
}
 
bool collinear(point a, point b, point c){return ccw(a, b, c)==0;}
 
double dist(point p1, point p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double angle(point a, point o, point b){
  // angulo AOB
  double cos_theta=(dist(o,a)*dist(o,a)+dist(o,b)*dist(o,b)-dist(a,b)*dist(a,b))/(2*dist(o,a)*dist(o,b));
  return acos(cos_theta)*(180/M_PI);
}

struct poligono{
  vector<point> P;
  poligono(){}
  poligono(vector<point> _P): P(_P){}

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

  // Puntos dentro del poligono y en la frontera
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
};

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(2)<<fixed;
  point p1(1,0),p2(1,1),p3(0,1),p4(0,0);
  vector<point> P={p1,p2,p3,p4,p1};
  poligono Poligono(P);
  cout<<Poligono.area()<<"\n";
  cout<<Poligono.perimeter()<<"\n";

  return 0;
}