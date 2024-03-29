// Autor: Mateo Álvarez Murillo
// Fecha de creación: 2024
// 
// Este código se proporciona bajo la Licencia MIT.
// Para más información, consulta el archivo LICENSE en la raíz del repositorio.

#include <bits/stdc++.h>
using namespace std;

struct Rect {
	int x1, y1, x2, y2;
	int area() { return (y2 - y1) * (x2 - x1); }
};

int intersectArea(Rect p, Rect q) {
	int xOverlap = max(0, min(p.x2, q.x2) - max(p.x1, q.x1));
	int yOverlap = max(0, min(p.y2, q.y2) - max(p.y1, q.y1));
	return xOverlap * yOverlap;
}

bool intersect(Rect p, Rect q) {
  bool op1 = p.x1 >= q.x2 || p.x2 <= q.x1;
  bool op2 = p.y1 >= q.y2 || p.y2 <= q.y1;
  return !(op1 || op2);
}
