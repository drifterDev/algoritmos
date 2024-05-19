#include <bits/stdc++.h>
using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	priority_queue<int> q;
	q.push(3);
	q.push(5);
	q.push(7);
	q.push(2);
	cout<<q.top()<<"\n"; //7
	q.pop();
	cout<<q.top()<<"\n"; //5

	//Por defecto se toma el maximo como prioridad
	//Para tomar el minimo como prioridad sería:
	priority_queue<int, vector<int>,greater<int>> q2;
	return 0;
}