#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define S second
#define F first
typedef long long ll;
typedef pair<int, int> ii;
const double EPS = 1e-9;

struct Point{
	ll x,y,id;
	Point(): x(0),y(0),id(0){}
	Point(ll _x,ll _y,ll _id): x(_x),y(_y),id(_id){}
};

ll dist(Point p1, Point p2){
	return (p1.x-p2.x)*(p1.x-p2.x)+(p1.y-p2.y)*(p1.y-p2.y);
}

bool order_x(Point a, Point b){
	return a.x<b.x || (a.x==b.x && a.y<b.y);
}

bool order_y(Point a, Point b){
	return a.y<b.y;
}

vector<Point> points;
ll res;
ii ids;
int n;

void upd(const Point& a, const Point& b){
	ll dist1=dist(a,b);
	if(dist1<res){
		res=dist1;
		ids={a.id, b.id};
	}
}

vector<Point> aux;

void rec(int l, int r){
	if(r-l<=3){
		for(int i=l;i<r;++i){
			for(int j=i+1;j<r;++j){
				upd(points[i],points[j]);
			}
		}
		sort(points.begin()+l, points.begin()+r, order_y);
		return;
	}
	
	int m=(l+r)>>1;
	int midx=points[m].x;
	rec(l,m);
	rec(m,r);
	merge(points.begin()+l, points.begin()+m, points.begin()+m, points.begin()+r, aux.begin(), order_y);
	copy(aux.begin(), aux.begin()+r-l, points.begin()+l);

	int tsz=0;
	for(int i=l;i<r;++i){
		if(abs(points[i].x-midx)<res){
			for(int j=tsz-1;j>=0 && points[i].y-aux[j].y<res;--j)upd(points[i],aux[j]);
			aux[tsz++]=points[i];
		}
	}
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	cout<<setprecision(6)<<fixed;
	cin>>n;
	points.resize(n);
	for(int i=0;i<n;i++){
		ll x,y;cin>>x>>y;
		points[i]=Point(x,y,i);
	}
	aux.resize(n);
	sort(all(points), order_x);
	res=1E20;
	rec(0,n);
	cout<<min(ids.F,ids.S)<<" "<<max(ids.F,ids.S)<<" "<<sqrt(res)<<"\n";
	return 0;
}