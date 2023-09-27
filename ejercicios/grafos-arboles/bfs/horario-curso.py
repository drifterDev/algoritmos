# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Hay un total de numCursos cursos que tiene que tomar, etiquetados de 0 a numCursos - 1. Se le da una matriz prerrequisitos donde prerrequisitos[i] = [ai, bi] indica que debe tomar el curso bi primero si quiere tomar el curso ai. Por ejemplo, el par [0, 1], indica que para tomar el curso 0 hay que tomar primero el curso 1. Devuelve true si puedes terminar todos los cursos. En caso contrario, devuelve false.

# Ejemplo 1:
# Entrada: numCursos = 2, prerrequisitos = [[1,0]]
# Salida: true
# Explicación: Hay un total de 2 cursos para tomar. Para tomar el curso 1 debes haber terminado el curso 0. Así que es posible.

from collections import defaultdict, deque


class Node:
    def __init__(self):
        self.indegree = 0
        self.outNodes = []


class Solution:
    def canFinish(self, numCourses: int, prerequisites: list[list[int]]) -> bool:
        grafo = defaultdict(Node)
        for cursos in prerequisites:
            grafo[cursos[0]].indegree += 1
            grafo[cursos[1]].outNodes.append(grafo[cursos[0]])
        cola = deque()
        for course in grafo:
            if grafo[course].indegree == 0:
                cola.append(grafo[course])
        removerConexion = 0
        while cola:
            course = cola.popleft()
            for nextCourse in course.outNodes:
                removerConexion += 1
                nextCourse.indegree -= 1
                if nextCourse.indegree == 0:
                    cola.append(nextCourse)
        return removerConexion == len(prerequisites)
