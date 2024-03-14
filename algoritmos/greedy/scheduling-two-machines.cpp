// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
#define PB push_back
#define F first
#define S second
typedef pair<int, int> ii;

// Tenemos dos maquinas y cada trabajo debe hacerse primero en a y luego en b
// dado su tiempo en cada maquina, da la agenda optima que minimiza los tiempos
struct Job {
  int a,b,idx;
  bool operator<(Job o) const{
    return min(a, b)<min(o.a, o.b);
  }
};

// Agenda de trabajos optima O(nlogn)
vector<Job> johnsons_rule(vector<Job> jobs){
  sort(all(jobs));
  vector<Job> a, b;
  for(Job j:jobs){
    if(j.a<j.b)a.PB(j);
    else b.PB(j);
  }
  // Los de menor tiempo en a primero
  // Luego los de menor tiempo en b, pero en orden inverso
  a.insert(a.end(), b.rbegin(), b.rend());
  return a;
}

// El tiempo en que acaban ambas maquinas
ii finish_times(vector<Job> const& jobs) {
  int t1=0,t2=0;
  for(Job j:jobs){
    t1+=j.a;
    t2=max(t2, t1)+j.b;
  }
  return {t1, t2};
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  // freopen("file.in", "r", stdin);
  // freopen("file.out", "w", stdout);
  vector<Job> jobs={{2,3,0},{1,5,1},{3,4,2},{5,6,3}};
  vector<Job> optimal= johnsons_rule(jobs);
  ii times=finish_times(optimal);
  cout<<"Tiempos: "<<times.F<<" "<<times.S<<"\n";
  for(Job j:optimal)cout<<j.idx<<" ";
  return 0;
}