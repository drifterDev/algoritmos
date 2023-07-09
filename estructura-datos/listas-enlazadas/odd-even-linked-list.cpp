#include <bits/stdc++.h>
using namespace std;
#define sz(arr) ((int) arr.size())
typedef long long ll;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
typedef vector<long long> vl;
const int INF = 1e9;
const ll INFL = 1e18;
const int MOD = 1e9+7;
int dirx[4] = {0,-1,1,0};
int diry[4] = {-1,0,0,1};
int dr[] = {1, 1, 0, -1, -1, -1, 0, 1};
int dc[] = {0, 1, 1, 1, 0, -1, -1, -1};

struct Nodo{
  int valor;
  Nodo *siguiente;
  Nodo(): valor(0), siguiente(nullptr){}
  Nodo(int x): valor(x), siguiente(nullptr){}
  Nodo(int x, Nodo *sig): valor(x), siguiente(sig){}
};

ListNode* oddEvenList(ListNode* cabeza){
  if (cabeza==nullptr || cabeza->siguiente==nullptr) {
    return cabeza;
  }
  Nodo* impar = cabeza;
  Nodo* par=cabeza->siguiente;
  Nodo* cabezaPar=par;
  while(par!=nullptr && par.siguiente != null){
    impar->siguiente = par->siguiente;
    impar=impar->siguiente;
    par->siguiente=impar->siguiente;
    par=par->siguiente;
  }
  impar->siguiente=cabezaPar;

  return cabeza;

}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}