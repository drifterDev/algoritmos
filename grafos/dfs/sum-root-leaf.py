total: int


def sum_root_leaf(raiz) -> int:
    if raiz == None:
        return 0
    total = 0
    dfs(raiz, "", total)
    return total


def dfs(raiz, camino, total):
    if raiz.izquierda == None and raiz.derecha == None:
        total += int(camino + str(raiz.value))
    if raiz.izquierda != None:
        dfs(raiz.izquierda, camino + str(raiz.value), total)
    if raiz.derecha != None:
        dfs(raiz.derecha, camino + str(raiz.value), total)
