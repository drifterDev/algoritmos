# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Dado varios puntos en un plano cartesiano
# devolver los k puntos más cercanos al origen
import heapq


# O(k * log(n))
def k_closest(points: list[list[int]], k: int) -> list[list[int]]:
    distancias = []
    for x, y in points:
        distancia = (x * x + y * y) ** (1 / 2)
        distancias.append(distancia, [x, y])
    heapq.heapify(distancias)
    puntos_mas_cercanos = []
    for _ in range(k):
        distancia_actual, coordenadas = heapq.heappop(distancias)
        puntos_mas_cercanos.append(coordenadas)
    return puntos_mas_cercanos
