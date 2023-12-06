// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

bool find_any_solution(ll a, ll b, ll c, ll &x0, ll &y0, ll &g){
  // Implementar la identidad de Bezout
  g=gcd(abs(a),abs(b),x0,y0);
  if(c%g)return false;
  x0*=c/g;
  y0*=c/g;
  if(a<0)x0=-x0;
  if(b<0)y0=-y0;
  return true;
}

void shift_solution(ll& x, ll& y, ll a, ll b, ll cnt){
  x+=cnt*b;y-=cnt*a;
}

ll find_all_solutions(ll a,ll b,ll c,ll minx,ll maxx,ll miny,ll maxy){
  ll x,y,g;
  if(!find_any_solution(a,b,c,x,y,g))return 0;
  a/=g;b/=g;
  ll sign_a=a>0?+1:-1;
  ll sign_b=b>0?+1:-1;
  shift_solution(x,y,a,b,(minx-x)/b);
  if(x<minx)shift_solution(x,y,a,b,sign_b);
  if(x>maxx)return 0;
  ll lx1=x;
  shift_solution(x,y,a,b,(maxx-x)/b);
  if(x>maxx)shift_solution(x,y,a,b,-sign_b);
  ll rx1=x;
  shift_solution(x,y,a,b,-(miny-y)/a);
  if(y<miny)shift_solution(x,y,a,b,-sign_a);
  if(y>maxy)return 0;
  ll lx2=x;
  shift_solution(x,y,a,b,-(maxy-y)/a);
  if(y>maxy)shift_solution(x,y,a,b,sign_a);
  ll rx2=x;
  if(lx2>rx2)swap(lx2,rx2);
  ll lx=max(lx1,lx2);
  ll rx=min(rx1,rx2);
  if(lx>rx)return 0;
  return (rx-lx)/abs(b)+1;
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  ll a,b,c,x,y,g;
  a=39,b=15,c=12;
  cout<<"Numero soluciones en el rango definido: "<<find_all_solutions(a,b,c,-100,100,-100,100)<<"\n";
  if(find_any_solution(a,b,c,x,y,g)){
    cout<<"Una solucion: "<<x<<" "<<y<<"\n";
  }else{
    cout<<"No solution\n";
  }
  return 0;
}
