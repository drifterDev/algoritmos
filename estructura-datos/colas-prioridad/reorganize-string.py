# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Dado un string retornar un string en el cual
# no haya dos letras iguales adyacentes
# Si no se puede imprimir una cadena vacia
# entrada: "aacba"
# salido: "acaba"

# Para evitar usar try except se usar defaultdict
from collections import defaultdict
import heapq


def reorganize_string(s: str) -> str:
    ocurrencias_caracter = defaultdict(int)
    lens = len(s)
    for char in s:
        ocurrencias_caracter[char] += 1
        if ocurrencias_caracter[char] > (lens + 1) / 2:
            return ""
    cola_prioridad = []
    for key, value in ocurrencias_caracter:
        cola_prioridad.append((-value, key))
    heapq.heapify(cola_prioridad)

    string_ordenado = []
    while 2 <= len(cola_prioridad):
        ocurrencia1, caracter1 = heapq.heappop(cola_prioridad)
        ocurrencia2, caracter2 = heapq.heappop(cola_prioridad)
        string_ordenado.append(caracter1)
        string_ordenado.append(caracter2)
        if ocurrencia1 + 1:
            heapq.heappush(cola_prioridad, (ocurrencia1 + 1, caracter1))

        if ocurrencia2 + 1:
            heapq.heappush(cola_prioridad, (ocurrencia2 + 1, caracter2))
    if cola_prioridad:
        return "".join(string_ordenado) + cola_prioridad[0][1]
    return "".join(string_ordenado)
