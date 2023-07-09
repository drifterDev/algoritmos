# Se le da un flujo de registros sobre una acción concreta. Cada registro contiene el tiempo y el precio correspondiente de la acción en esa marca.
# Por desgracia, debido a la naturaleza volátil del mercado de valores, los registros no vienen en orden y algunos registros pueden ser incorrectos. Otro registro con el mismo registro de tiempo puede aparecer más tarde en el flujo corrigiendo el precio del anterior registro erróneo.

# Diseñe un algoritmo que:
# Actualice el precio de la acción en un momento en el tiempo determinado, corrigiendo el precio de cualquier registro anterior en ese instante.
# Encuentre el último precio de la acción basado en los registros actuales. El último precio es el precio de la última marca de tiempo registrada.
# Busque el precio máximo de la acción basado en los registros actuales.
# Encuentre el precio mínimo de la acción basado en los registros actuales.

# Implementa la clase StockPrice:
# StockPrice(): inicializa el objeto sin registros de precios.
# void update(int timestamp, int price): actualiza el precio de la acción en el timestamp dado.
# int current(): devuelve el último precio de la acción.
# int maximum(): devuelve el precio máximo de la acción.
# int minimum(): devuelve el precio mínimo de la acción.

# Ejemplo:
# Entrada.
# ["StockPrice", "update", "update", "current", "maximum", "update", "maximum", "update", "minimum"]
# [[], [1, 10], [2, 5], [], [], [1, 3], [], [4, 2], []]
# Salida: [null, null, null, 5, 10, null, 5, null, 2]

# Explicación:
# StockPrice stockPrice = new StockPrice();
# stockPrice.update(1, 10); // Las marcas de tiempo son [1] con los precios correspondientes [10].
# stockPrice.update(2, 5); // Las marcas de tiempo son [1,2] con los precios correspondientes [10,5].
# stockPrice.current(); // devuelve 5, la última marca de tiempo es 2 con el precio siendo 5.
# stockPrice.maximum(); // devuelve 10, el precio máximo es 10 en el timestamp 1.
# stockPrice.update(1, 3); // El timestamp 1 anterior tenía el precio incorrecto, por lo que se actualiza a 3.
#                           // Las marcas de tiempo son [1,2] con los precios correspondientes [3,5].
# stockPrice.maximum(); // devuelve 5, el precio máximo es 5 después de la corrección.
# stockPrice.update(4, 2); // Las marcas de tiempo son [1,2,4] con los precios correspondientes [3,5,2].
# stockPrice.minimum(); // devuelve 2, el precio mínimo es 2 en el timestamp 4.


from heapq import heappop, heappush


class StockPrice:
    def __init__(self):
        self.hash_map = {}
        self.ultimo = 0
        self.minHeap = []
        self.maxHeap = []

    def update(self, t: int, p: int) -> None:
        self.ultimo = max(t, self.ultimo)
        self.hash_map[t] = p
        heappush(self.minHeap, (p, t))
        heappush(self.maxHeap, (-p, t))

    def current(self) -> int:
        return self.hash_map[self.ultimo]

    def maximum(self) -> int:
        while self.hash_map[self.maxHeap[0][1]] != -self.maxHeap[0][0]:
            heappop(self.maxHeap)
        return -self.maxHeap[0][0]

    def minimum(self) -> int:
        while self.hash_map[self.minHeap[0][1]] != self.minHeap[0][0]:
            heappop(self.minHeap)
        return self.minHeap[0][0]
