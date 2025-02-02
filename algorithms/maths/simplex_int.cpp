#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef __int128 T;
struct Fraction{
	T num,den;
	Fraction():num(0),den(1){}
	Fraction(T n):num(n),den(1){}
	Fraction(T n,T d):num(n),den(d){reduce();}
	void reduce(){
		// assert(den!=0);
		T gcd=__gcd(num,den); // <-
		num/=gcd,den/=gcd;
		if(den<0)num=-num,den=-den;
	}
	Fraction fractional_part()const{ // x - floor(x)
		Fraction fp=Fraction(num%den,den);
		if(fp<Fraction(0))fp+=Fraction(1);
		return fp;
	}
	T compare(Fraction f)const{return num*f.den-den*f.num;}
	Fraction operator + (const Fraction& f){return Fraction(num*f.den+den*f.num,den*f.den);}
	Fraction operator - (const Fraction& f){return Fraction(num*f.den-den*f.num,den*f.den);}
	Fraction operator * (const Fraction& f){
		Fraction a=Fraction(num,f.den);
		Fraction b=Fraction(f.num,den);
		return Fraction(a.num*b.num,a.den*b.den);
	}
	Fraction operator / (const Fraction& f){return *this*Fraction(f.den,f.num);}
	Fraction operator += (const Fraction& f){return *this=*this+f;}
	Fraction operator -= (const Fraction& f){return *this=*this-f;}
	Fraction operator *= (const Fraction& f){return *this=*this*f;}
	Fraction operator /= (const Fraction& f){return *this=*this/f;}
	bool operator == (const Fraction& f)const{return compare(f)==0;}
	bool operator != (const Fraction& f)const{return compare(f)!=0;}
	bool operator >= (const Fraction& f)const{return compare(f)>=0;}
	bool operator <= (const Fraction& f)const{return compare(f)<=0;}
	bool operator > (const Fraction& f)const{return compare(f)>0;}
	bool operator < (const Fraction& f)const{return compare(f)<0;}
};
Fraction operator - (const Fraction& f){return Fraction(-f.num,f.den);}
ostream& operator << (ostream& os, const Fraction& f){return os<<"("<<(ll)f.num<<"/"<<(ll)f.den<<")";}

// Maximizar c1*x1 + c2*x2 + c3*x3 ...
// Restricciones a11*x1 + a12*x2 <= b1, a22*x2 + a23*x3 <= b2 ...
// Retorna valor optimo y valores de las variables

// O(c^2*b), O(c*b) - variables c, restricciones b (tle)
typedef Fraction lf;
const lf ZERO(0),INF(1e18);
struct Simplex{
	vector<vector<lf>> A;
	vector<lf> B,C;
	vector<int> X,Y;
	lf z;
	int n,m;

	Simplex(vector<vector<lf>> _a, vector<lf> _b, vector<lf> _c){
		A=_a;B=_b;C=_c;
		n=B.size();m=C.size();z=ZERO;
		X=vector<int>(m);Y=vector<int>(n);
		for(int i=0;i<m;++i)X[i]=i;
		for(int i=0;i<n;++i)Y[i]=i+m;
	}

	void pivot(int x,int y){
		swap(X[y],Y[x]);
		B[x]/=A[x][y];
		for(int i=0;i<m;++i)if(i!=y)A[x][i]/=A[x][y];
		A[x][y]=Fraction(1)/A[x][y];
		for(int i=0;i<n;++i)if(i!=x && A[i][y]!=ZERO){ 
			B[i]-=A[i][y]*B[x];
			for(int j=0;j<m;++j)if(j!=y)A[i][j]-=A[i][y]*A[x][j];
			A[i][y]=-A[i][y]*A[x][y];
		}
		z+=C[y]*B[x];
		for(int i=0;i<m;++i)if(i!=y)C[i]-=C[y]*A[x][i];
		C[y]=-C[y]*A[x][y];
	}
	
	pair<lf, vector<lf>> maximize(){
		while(1){
			int x=-1,y=-1;
			lf mn=ZERO; 
			for(int i=0;i<n;++i)if(B[i]<mn)mn=B[i],x=i;
			if(x<0)break;
			for(int i=0;i<m;++i)if(A[x][i]<ZERO){y=i;break;} 
			// assert(y>=0) -> y<0, no solution to Ax<=B
			pivot(x,y);
		}
		while(1){
			lf mx=ZERO; 
			int x=-1,y=-1;
			for(int i=0;i<m;++i)if(C[i]>mx)mx=C[i],y=i;
			if(y<0)break;
			lf mn=INF;
			for(int i=0;i<n;++i)if(A[i][y]>ZERO && B[i]/A[i][y]<mn)mn=B[i]/A[i][y],x=i; 
			// assert(x>=0) -> x<0, unbounded
			pivot(x,y);
		}
		vector<lf> r(m);
		for(int i=0;i<n;++i)if(Y[i]<m)r[Y[i]]=B[i];
		return {z,r};
	}

	pair<Fraction, vector<Fraction>> maximize_int(){
		while(1){
			auto sol=maximize();
			bool all_int=true;
			for(auto &x:sol.second)all_int&=x.fractional_part()==ZERO;
			if(all_int)return sol;
			Fraction nw_b=ZERO;
			int id=-1;
			for(int i=0;i<n;++i){
				Fraction fp=B[i].fractional_part();
				if(fp>=nw_b)nw_b=fp,id=i;
			}
			vector<Fraction> nw_a;
			for(auto &x:A[id])nw_a.push_back(-x.fractional_part());
			A.push_back(nw_a);
			B.push_back(-nw_b);
			Y.push_back(n+m);n++;
		}
	}
};
