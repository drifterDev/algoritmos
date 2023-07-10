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

    Nodo(int val) : valor(val), siguiente(nullptr) {}
};

class Palindrome {
public:
    bool isPalindrome(Nodo* cabeza) {
        if (cabeza == nullptr) {
            return true;
        }
        Nodo* comienzoSegundaMitad = reversarLista(cabeza);
        bool esPalindromo = true;
        Nodo* p1 = cabeza;
        Nodo* p2 = comienzoSegundaMitad;
        while (esPalindromo && p2 != nullptr) {
            if (p1->valor != p2->valor) {
                esPalindromo = false;
                break;
            }
            p1 = p1->siguiente;
            p2 = p2->siguiente;
        }
        comienzoSegundaMitad = reversarLista(comienzoSegundaMitad);
        return esPalindromo;
    }

    Nodo* encontrarMitad(Nodo* cabeza) {
        Nodo* rapido = cabeza;
        Nodo* lento = cabeza;
        while (rapido->siguiente != nullptr && rapido->siguiente->siguiente != nullptr) {
            rapido = rapido->siguiente->siguiente;
            lento = lento->siguiente;
        }
        return lento;
    }

    Nodo* reversarLista(Nodo* cabeza) {
        Nodo* anterior = nullptr;
        Nodo* actual = cabeza;
        while (actual != nullptr) {
            Nodo* siguienteTemporal = actual->siguiente;
            actual->siguiente = anterior;
            anterior = actual;
            actual = siguienteTemporal;
        }
        return anterior;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    // Ejemplo de uso
    Nodo* nodo1 = new Nodo(1);
    Nodo* nodo2 = new Nodo(2);
    Nodo* nodo3 = new Nodo(3);
    Nodo* nodo4 = new Nodo(2);
    Nodo* nodo5 = new Nodo(1);

    nodo1->siguiente = nodo2;
    nodo2->siguiente = nodo3;
    nodo3->siguiente = nodo4;
    nodo4->siguiente = nodo5;

    Palindrome palindrome;
    bool esPalindromo = palindrome.isPalindrome(nodo1);
    if (esPalindromo) {
        cout << "La lista es un palíndromo." << endl;
    } else {
        cout << "La lista no es un palíndromo." << endl;
    }

    delete nodo1;
    delete nodo2;
    delete nodo3;
    delete nodo4;
    delete nodo5;

    return 0;
}
