// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2023

// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <iostream>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	long long n;cin >> n;
	while (true) {
		
		if (n == 1) {
			cout << n;
			break;
		}
		cout << n<<" ";
		if (n % 2 == 0) {
			n = n / 2;
		}
		else {
			n = (n * 3) + 1;
		}
	}
}
 
 
