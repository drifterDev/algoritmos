#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    long long n1, n2;
    cin>>n1 >>n2;
    long long x,y,z;
    x=max(fabs(n1), fabs(n2));
    y=min(fabs(n1), fabs(n2));
    z=x%y;
    if (z==0){
        cout<<y<<"\n";
    }else{
        while(z>0){
            x=y;
            y=z;
            z=x%y;
        }
        cout<<y<<"\n";
    }
    return 0;
}





