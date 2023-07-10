def dfs(raiz):
    pila = []
    visitados = set()
    pila.append(raiz)

    while pila:  # comprueba si hay algo en la lista de tareas pendientes
        nodoActual = pila.pop()  # accede al nodo siguiente
        if (
            nodoActual not in visitados
        ):  # actualiza los nodos visitados si este nodo no habia sido visitado antes
            visitados.add(nodoActual)
        for nodo in nodoActual.nodosAdyacentes:  # itera sobre los nodos adyacentes
            if nodo not in visitados:
                pila.append(nodo)  # añade a la lista de tareas pendientes
