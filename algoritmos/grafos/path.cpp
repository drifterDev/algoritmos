#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int n;

vi find_path(int a, int b, vi& p){
	vi path;
	for(int v=b;v!=a;v=p[v])path.push_back(v);
	path.push_back(a);
	reverse(path.begin(), path.end());
	return path;
}
