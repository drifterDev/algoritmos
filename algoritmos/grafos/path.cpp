#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define PB push_back
typedef vector<int> vi;
int n;

vi find_path(int a, int b, vi& p){
	vi path;
	for(int v=b;v!=a;v=p[v])path.PB(v);
	path.PB(a);
	reverse(all(path));
	return path;
}
