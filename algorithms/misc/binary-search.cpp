vector<int> a;
int x;

// O(log(n))
bool check(int x);
void binary_search(){
	int l=0,r=(int)a.size()-1;
	while(l<=r){
		int m=l+(r-l)/2;
		if(check(m))l=m+1;
		else r=m-1;
	}
}

void santa_binaria(){
	int l=-1; // the last 0
	int r=a.size(); // the first 1
	while(r-l>1){
		int m=l+(r-l)/2;
		if(check(m))l=m;
		else r=m;
	}
}

int main() {
	vector<int> v={1, 2, 4, 4, 5, 6, 7, 7, 8, 9};x=6;
	int id=lower_bound(v.begin(), v.end(),x)-v.begin();
	cout<<"Lower Bound de "<<x<<" en el índice: "<<id<<"\n";
	cout<<"Lower Bound de "<<x<<": "<<v[id]<<"\n";
	id=upper_bound(v.begin(), v.end(),x)-v.begin();
	cout<<"Upper Bound de "<<x<<" en el índice: "<<id<<"\n";
	cout<<"Upper Bound de "<<x<<": "<<v[id]<<"\n";
	return 0;
}