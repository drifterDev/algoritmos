// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
int ld[30]={0};
int rd[30]={0};
int cl[30]={0};
int n;

// O(n!)
int ans=0;
void nQueen(vector<vi>& board, int col){
	if(col>=n){
		ans++;
		return;
	}
	for(int i=0;i<n;i++){
		if (ld[i-col+n-1]!=1 && rd[i+col]!=1 && cl[i]!=1 && board[i][col]!=-1){
			board[i][col]=1;
			ld[i-col+n-1]=rd[i+col]=cl[i]=1;
			nQueen(board, col+1);
			ld[i-col+n-1]=rd[i+col]=cl[i]=0;
			board[i][col]=0; 
		}
	}
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
	n=8;
  vector<vi> board(n,vi(n,0));
	char c;
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j){
			cin>>c;
			if(c=='*')board[i][j]=-1;
		}
	}
	nQueen(board, 0);
	cout<<ans<<"\n";
  return 0;
}