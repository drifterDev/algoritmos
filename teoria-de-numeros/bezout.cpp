#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int gcd(int a, int b, int& s, int& t) {
    if (b == 0) {
        s = 1;
        t = 0;
        return a;
    }
    int s1, t1;
    int d = gcd(b, a % b, s1, t1);
    s = t1;
    t = s1 - (a / b) * t1;
    return d;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, s, t;
    cin >> a >>b;
    int d = gcd(a, b, s, t);
    cout<<s<<" "<<t<<"\n";
    //a*s + b*t == 1
    return 0;
}





