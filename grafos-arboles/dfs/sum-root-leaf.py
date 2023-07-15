# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

class Response:
    def __init__(self, total=0):
        self.total = total

    def dfs(self, node, valor_actual):
        parcial = valor_actual + str(node.valor)

        if node.izquierda is None and node.derecha is None:
            self.total = self.total + int(parcial)
        if node.derecha is not None:
            self.dfs(node.derecha, parcial)
        if node.izquierda is not None:
            self.dfs(node.izquierda, parcial)


def sum_numbers(node, valor_actual=""):
    response = Response(0)
    response.dfs(node, valor_actual)
    return response.total
