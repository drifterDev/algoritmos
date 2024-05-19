#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
#define all(x) x.begin(), x.end()
#define F first
#define S second
#define PB push_back
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;

// Busca maximo de tareas que no se solapen
// dado su tiempo de inicio y duracion
// O(nlogn)
int main() {
	ios::sync_with_stdio(false);cin.tie(nullptr);
	vector<char> tasks={'A','B','C','D','E','F'};
	vi begins={1,2,3,6,8,12};
	vi times={3,5,9,8,2,2};
	vii ends;
	int n=sz(tasks), actualTime=0;
	for(int i=0;i<n;++i)ends.PB({begins[i]+times[i],i});
	sort(all(ends));
	for(auto act:ends){
		// Buscamos la tarea que termine primero
		int task=act.S;
		if(actualTime<=begins[task]){
			cout<<"Tarea "<<tasks[task]<<" de "<<begins[task]<<" a "<<begins[task]+times[task]<<"\n";
			actualTime=begins[task]+times[task];
		}
	}
	return 0;
}