#include <bits/stdc++.h>
using namespace std;

void find_roots(double a,double b,double c){
  if(a==0 && b==0 && c==0){
    cout<<"-1\n";return;
  }else if(a==0 && b==0){
    cout<<"0\n";return;
  }
  double determinante=pow(b,2)-4*a*c;
  if(a==0){
    double root=-c/b;
    cout<<"1\n"<<root<<"\n";
  }else if(determinante<0){
    cout<<"0\n";
  }else if(determinante==0){
    double root=(-b)/(2*a);
    cout<<"1\n"<<root<<"\n";
  }else{
    double root1=(-b+sqrt(determinante))/(2*a);
    double root2=(-b-sqrt(determinante))/(2*a);
    cout<<"2\n"<<min(root1,root2)<<"\n"<<max(root1,root2)<<"\n";
  }
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  double a,b,c;
  cin>>a>>b>>c;
  find_roots(a,b,c);
  return 0;
}