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
/**/
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (!head || !head->next || !head->next->next) {
        return;
    }
    ListNode* rapido = head->next;
    ListNode* lento = head;
    while (rapido && rapido->next) {
        rapido = rapido->next->next;
        lento = lento->next;
    }
    ListNode* comienzoSegundaMitad = lento->next;
    ListNode* actual = comienzoSegundaMitad;
    ListNode* anterior = nullptr;
    ListNode* tmp;
    while (actual) {
        tmp = actual->next;
        actual->next = anterior;
        anterior = actual;
        actual = tmp;
    }
    ListNode* p1 = head;
    ListNode* p2 = anterior;
    while (p2) {
        tmp = p1->next;
        p1->next = p2;
        p1->next->next = tmp;
        p2->next = tmp;
        p1 = tmp;
    }
    }
};





int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
    // Ejemplo de uso
    ListNode* nodo1 = new ListNode(1);
    ListNode* nodo2 = new ListNode(2);
    ListNode* nodo3 = new ListNode(3);
    ListNode* nodo4 = new ListNode(4);
    ListNode* nodo5 = new ListNode(5);

    nodo1->next = nodo2;
    nodo2->next = nodo3;
    nodo3->next = nodo4;
    nodo4->next = nodo5;

    // Solution.reverseList(nodo1);

    ListNode* nodoActual = nodo1;
    while (nodoActual) {
        cout << nodoActual->val << " ";
        nodoActual = nodoActual->next;
    }
    cout << endl;

    delete nodo5;
    delete nodo4;
    delete nodo3;
    delete nodo2;
    delete nodo1;

    return 0;
}
