# Tienes un arreglo de caracteres tasks que representa las tareas que debe realizar una CPU, donde cada letra representa una tarea diferente. Las tareas pueden realizarse en cualquier orden. Cada tarea se realiza en una unidad de tiempo. Por cada unidad de tiempo la CPU puede completar una tarea o simplemente estar inactiva.

# Sin embargo, existe un período de enfriamiento entre dos tareas iguales (la misma letra en la matriz) representado por la variable n, es decir que debe haber al menos n unidades de tiempo entre dos tareas iguales.

# Devuelve el menor número de unidades de tiempo que la CPU tardará en terminar todas las tareas dadas.

# Ejemplo 1:
#     Entrada: tareas = ["A", "A", "A", "B", "B", "B"], n = 2
#     Salida: 8

# Explicación:
# A -> B -> inactivo -> A -> B -> inactivo -> A -> B
# Hay al menos 2 unidades de tiempo entre dos tareas iguales.


# Ejemplo 2:
#     Entrada: tareas = ["A", "A", "A", "B", "B", "B"], n = 0
#     Salida: 6
# Explicación: En este caso cualquier permutación de tamaño 6 funcionaría ya que n = 0.
# ["A","A","A","B","B","B"]
# ["A","B","A","B","A","B"]
# ["B","B","B","A","A","A"]
# ...
# Y así sucesivamente


from collections import defaultdict
import heapq


def organizadorDeTareas(tareas: list[str], n: int) -> int:
    tiempo = 0
    ocurrenciasCaracteres = defaultdict(int)
    for caracter in tareas:
        ocurrenciasCaracteres[caracter] += 1
    heap = []
    for caracter, cuenta in ocurrenciasCaracteres.items():
        heap.append((-cuenta, caracter))
    heapq.heapify(heap)
    while heap:
        valoresTemporales = []
        for _ in range(n + 1):
            if heap:
                contadorActual, caracterActual = heapq.heappop(heap)
                valoresTemporales.append((contadorActual, caracterActual))

        for cuenta, caracter in valoresTemporales:
            if cuenta < -1:
                heapq.heappush(heap, (cuenta + 1, caracter))

        if heap:
            tiempo += n + 1
        else:
            tiempo += len(valoresTemporales)
    return tiempo
