def dfs(raiz, objetivo):
    print("En el nodo con valor: " + str(raiz.valor))
    if raiz.valor == objetivo:
        print("Valor encontrado")
        return raiz
    for hijo in raiz.hijos:
        nodo_resultado = dfs(hijo, objetivo)
        if nodo_resultado != None:
            return nodo_resultado
    return None


# Otra forma de hacerlo para arboles binarios
def dfs2(raiz, objetivo):
    print("En el nodo con valor: " + str(raiz.valor))
    if raiz.valor == objetivo:
        print("Valor encontrado")
        return raiz
    izquierda = dfs2(raiz.izquierda, objetivo)
    derecha = dfs2(raiz.derecha, objetivo)
    if izquierda != None:
        return izquierda
    elif derecha != None:
        return derecha
    return None
