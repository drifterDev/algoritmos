# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Hay n ciudades conectadas por un cierto número de vuelos. Se le da un array flights donde flights[i] = [fromi, toi, pricei] indica que hay un vuelo desde la ciudad fromi a la ciudad toi con un precioi. También se le dan tres enteros src, dst y k, devuelve el precio más barato de src a dst con un máximo de k paradas. Si no existe tal ruta, devuelve -1.

# Ejemplo 1:
# Entrada:
# n = 4
# vuelos = [[0,1,100],[1,2,100],[2,0,100],[1,3,600],[2,3,200]]
# src = 0
# dst = 3
# k = 1
# Salida: 700

# Explicación:El gráfico se muestra arriba. El camino óptimo, con un máximo de 1 parada, desde la ciudad 0 a la 3 está marcado en rojo y tiene un coste de 100 + 600 = 700. Nótese que el camino que pasa por las ciudades [0,1,2,3] es más barato pero no es válido porque utiliza 2 paradas.

from collections import defaultdict


def findCheapestPrice(
    n: int, flights: list[list[int]], src: int, dst: int, K: int
) -> int:
    graph = defaultdict(list)
    res = float("inf")
    cola = [(src, 0, 0)]
    for vuelo in flights:
        graph[vuelo[0]].append((vuelo[1], vuelo[2]))
    while cola:
        viajeActual, nivel, precioActual = cola.pop(0)
        if nivel > K + 1:
            break
        if viajeActual == dst:
            res = min(res, precioActual)
        for siguienteVuelo, precioSiguienteVuelo in graph[viajeActual]:
            if precioSiguienteVuelo + precioActual >= res:
                continue
            cola.append(
                (siguienteVuelo, nivel + 1, precioSiguienteVuelo + precioActual)
            )
    if res != float("inf"):
        return res
    else:
        return -1
