def bfs(raiz):
    if not raiz:
        return []
    respuesta = []
    cola = [raiz]
    nivel = 1
    while cola:
        for _ in range(len(cola)):
            nodo_actual = cola.pop(0)
            print("Nodo actual: " + str(nodo_actual.value))
            respuesta.append(nodo_actual)
            for hijo in nodo_actual.hijos:
                cola.append(hijo)
        nivel += 1
    print("Cantidad de niveles del arbol: " + str(nivel))
    return respuesta
