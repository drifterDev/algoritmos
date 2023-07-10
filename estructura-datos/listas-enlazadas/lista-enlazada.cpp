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

class Nodo {
public:
    int valor;
    Nodo* siguiente;
};

class ListaEnlazada {
protected:
    Nodo* cabeza;
    Nodo* cola;

public:
    ListaEnlazada(Nodo* primerNodo) {
        this->cabeza = primerNodo;
        this->cola = primerNodo;
    }

    void setNodo(Nodo* nodo) {
        this->cola->siguiente = nodo;
        this->cola = this->cola->siguiente;
    }

    void borrarNodo(Nodo* nodo) {
        nodo->siguiente = nullptr;
    }

    Nodo* buscarNodo(int valor) {
        Nodo* nodoActual = this->cabeza;
        while (nodoActual != nullptr) {
            if (nodoActual->valor == valor) {
                return nodoActual;
            }
            nodoActual = nodoActual->siguiente;
        }
        return nullptr;
    }

    void borrarNodoPorValor(int valor) {
        Nodo* nodoBorrar = buscarNodo(valor);
        if (nodoBorrar != nullptr) {
            nodoBorrar->siguiente = nullptr;
        }
    }
};


int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  return 0;
}