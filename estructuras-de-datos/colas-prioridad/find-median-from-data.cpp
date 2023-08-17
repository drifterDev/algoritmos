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

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    return 0;
}

class MedianFinder {
public:
    MedianFinder() {}
    
    void addNum(int num) {
        if (colaMin.empty()) {
            colaMin.push(num);
            return;
        }
        
        if (colaMin.size() > colaMax.size()) {
            if (colaMin.top() > num) {
                colaMax.push(colaMin.top());
                colaMin.pop();
                colaMin.push(num);
            } else {
                colaMax.push(num);
            }
        } else {
            if (num > colaMax.top()) {
                colaMin.push(colaMax.top());
                colaMax.pop();
                colaMax.push(num);
            } else {
                colaMin.push(num);
            }
        }
    }
    
    double findMedian() {
        double res = 0.0;
        
        if (colaMin.size() == colaMax.size()) {
            res = colaMin.top() + (colaMax.top() - colaMin.top()) / 2.0;
        } else {
            if (colaMin.size() > colaMax.size()) {
                res = colaMin.top();
            } else {
                res = colaMax.top();
            }
        }
        
        return res;
    }
private:
    priority_queue<int> colaMin;
    priority_queue<int, vector<int>, greater<int>> colaMax;
};

