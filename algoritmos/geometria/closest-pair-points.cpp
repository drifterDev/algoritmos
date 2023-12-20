// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define S second
#define F first
typedef long long ll;
typedef pair<int, int> ii;
const double EPS = 1e-9;
const ll INFL = 1e18;

struct point{
  int id;
  double x,y;
  point(): x(0),y(0),id(0){}
  point(double _x,double _y, int _id): x(_x),y(_y),id(_id){}
  bool operator == (point other) const{
      return (fabs(x-other.x)<EPS) && (fabs(y-other.y)<EPS);
  };
};

ii best_pair;
double best_dist=INFL;

bool cmp(point a,point b){
  if(fabs(a.x-b.x)<EPS)return a.y<b.y;
  return a.x<b.x;
}

double dist(point p1, point p2){
  return sqrt((p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y));
}

double combine(point a[],int low,int mid,int high,double min_left,double min_right){
  double d=(min_left<min_right)?min_left:min_right;
  double line=(double)(a[mid].x+a[mid+1].x)*0.5;
  best_dist=min(best_dist,d);
  for(int i=mid+1;a[i].x<line+d && i<=high;++i){ 
    for(int j=mid;a[j].x>line-d && j>=low;--j){
      double temp=dist(a[i],a[j]);
      if(temp<best_dist){
        best_dist=temp;
        best_pair={a[i].id,a[j].id};
      }
    }
  }
  return best_dist;
}

double divide(point a[],int low,int high){
  if(low>=high)return INFL;  
  int mid=(low+high)/2;
  double min_left=divide(a,low,mid);
  double min_right=divide(a,mid+1,high);
  return combine(a,low,mid,high,min_left,min_right);
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(6)<<fixed;
  int n;cin>>n;
  point points[50001];
  for(int i=0;i<n;i++){
    cin>>points[i].x>>points[i].y;
    points[i].id=i;
  }
  sort(points,points+n,cmp);
  divide(points,0,n-1);
  int id1=best_pair.F,id2=best_pair.S;
  if(id1>id2)swap(id1,id2);
  cout<<id1<<" "<<id2<<" "<<best_dist<<"\n";
  return 0;
}