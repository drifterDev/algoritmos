// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

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

    Nodo(int valor = 0, Nodo* siguiente = nullptr) {
        this->valor = valor;
        this->siguiente = siguiente;
    }
};

void reorderList(Nodo* cabeza) {
    if (!cabeza || !cabeza->siguiente || !cabeza->siguiente->siguiente) {
        return;
    }
    Nodo* rapido = cabeza->siguiente;
    Nodo* lento = cabeza;
    while (rapido && rapido->siguiente) {
        rapido = rapido->siguiente->siguiente;
        lento = lento->siguiente;
    }
    Nodo* comienzoSegundaMitad = lento->siguiente;
    Nodo* actual = comienzoSegundaMitad;
    Nodo* anterior = nullptr;
    Nodo* tmp;
    while (actual) {
        tmp = actual->siguiente;
        actual->siguiente = anterior;
        anterior = actual;
        actual = tmp;
    }
    Nodo* p1 = cabeza;
    Nodo* p2 = anterior;
    while (p2) {
        tmp = p1->siguiente;
        p1->siguiente = p2;
        p1->siguiente->siguiente = tmp;
        p2->siguiente = tmp;
        p1 = tmp;
    }
}

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
    // Ejemplo de uso
    Nodo* nodo1 = new Nodo(1);
    Nodo* nodo2 = new Nodo(2);
    Nodo* nodo3 = new Nodo(3);
    Nodo* nodo4 = new Nodo(4);
    Nodo* nodo5 = new Nodo(5);

    nodo1->siguiente = nodo2;
    nodo2->siguiente = nodo3;
    nodo3->siguiente = nodo4;
    nodo4->siguiente = nodo5;

    reorderList(nodo1);

    Nodo* nodoActual = nodo1;
    while (nodoActual) {
        std::cout << nodoActual->valor << " ";
        nodoActual = nodoActual->siguiente;
    }
    cout << endl;

    delete nodo5;
    delete nodo4;
    delete nodo3;
    delete nodo2;
    delete nodo1;

    return 0;
}
