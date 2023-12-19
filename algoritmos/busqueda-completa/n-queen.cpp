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

void printSolution(vector<vi>& board){
	for(int i=0;i<n;++i){
		for(int j=0;j<n;++j)cout<<(board[i][j]==1?"Q":".")<<" ";
		cout<<"\n";
	}
}

// O(n!)
bool nQueen(vector<vi>& board, int col){
	if(col>=n)return true;
	for(int i=0;i<n;i++){
		// Check if the queen can be placed on board[i][col]
		if ((ld[i-col+n-1]!=1 && rd[i+col]!=1) && cl[i]!=1){
			// Place this queen in board[i][col]
			board[i][col]=1;
			ld[i-col+n-1]=rd[i+col]=cl[i]=1;
			// Recur to place rest of the queens
			if(nQueen(board, col+1))return true;
			// If placing queen in board[i][col] doesn't lead to a solution, then remove queen from board[i][col]
			board[i][col]=0; // BACKTRACK
			ld[i-col+n-1]=rd[i+col]=cl[i]=0;
		}
	}
	return false;
}

int main(){
  ios::sync_with_stdio(false);cin.tie(0);
  cout<<setprecision(20)<<fixed;
  cin>>n;
  vector<vi> board(n,vi(n,0));
	if(nQueen(board, 0))printSolution(board);
	else cout<<"Solution does not exist";
  return 0;
}