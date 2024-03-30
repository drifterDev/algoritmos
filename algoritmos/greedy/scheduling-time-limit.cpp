// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define print(arr) for(auto& x:arr)cout<<x<<" ";cout<<"\n"
#define all(x) x.begin(), x.end()
#define sz(x) ((int) x.size())
#define PB push_back
typedef vector<int> vi;
typedef pair<int, int> ii;

// Tenemos n trabajos con un tiempo de duracion y un deadline
// Queremos maximizar el numero de trabajos que podemos hacer
struct Job{
	int deadline,duration,idx;

	bool operator<(Job o)const{
		return deadline < o.deadline;
	}
};

// O(nlogn)
vi compute_schedule(vector<Job> jobs){
	sort(all(jobs));
	set<ii> s;
	vi schedule;
	for(int i=sz(jobs)-1;i>=0;i--){
		int t=jobs[i].deadline-(i?jobs[i-1].deadline:0);
		s.insert({jobs[i].duration, jobs[i].idx});
		while(t && !s.empty()){
			auto it=s.begin();
			if(it->first<=t){
				t-=it->first;
				schedule.PB(it->second);
			} else {
				s.insert({it->first-t, it->second});
				t=0;
			}
			s.erase(it);
		}
	}
	return schedule;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(nullptr);
	vector<Job> jobs={{2,4,0},{5,3,1},{7,2,2},{5,4,3}};
	vi schedule=compute_schedule(jobs);
	print(schedule);
	return 0;
}