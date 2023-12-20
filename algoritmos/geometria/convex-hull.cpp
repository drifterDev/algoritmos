#include <bits/stdc++.h>
using namespace std;
#define sz(x) ((int) x.size())
#define PB push_back
typedef long long ll;

struct point{
  ll x,y;
  point(): x(0),y(0){}
  point(ll _x,ll _y): x(_x),y(_y){}
};

ll dist(point p1, point p2){
  return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

int orientation(point p, point q, point r){
  ll val=p.x*(q.y-r.y)+q.x*(r.y-p.y)+r.x*(p.y-q.y);
  if(val>0)return 1;
  if(val<0)return -1;
  return 0;
}

vector<point> convexHull(vector<point>& points, int n){
  int id=0;
  for(int i=1;i<n;++i){
    if(points[i].y<points[id].y)id=i;
    else if(points[i].y==points[id].y && points[i].x<points[id].x)id=i;
  }
  swap(points[0],points[id]);
  point p0=points[0];
  sort(points.begin()+1,points.end(),[&p0](point& p, point& q){
    int o=orientation(p0,p,q);
    if(o==0)return dist(p0,p)<dist(p0,q);
    return o>0;
  });
  vector<point> ans;
  for(int i=0;i<sz(points);++i){
    if(!ans.empty() && points[i].x==ans.back().x && points[i].y==ans.back().y)continue;
    while(sz(ans)>1 && orientation(ans[sz(ans)-2],ans.back(),points[i])!=1)ans.pop_back();
    ans.PB(points[i]);
  }
  return ans;
}


int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  int n;cin>>n;
  while(n!=0){
    vector<point> points(n);
    for(int i=0;i<n;++i)cin>>points[i].x>>points[i].y;
    vector<point> ans=convexHull(points, n);
    cout<<sz(ans)<<"\n";
    for(auto p:ans)cout<<p.x<<" "<<p.y<<"\n";
    cin>>n;
  }
  return 0;
}