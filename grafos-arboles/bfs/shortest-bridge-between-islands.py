def shortest_bridge(mapa: list[list[str]]) -> int:
    find_island = False

    def dfs(i, j, mapa):
        if 0 <= i < len(mapa) and 0 <= j < len(mapa[0]):
            if mapa[i][j] == "1":
                mapa[i][j] = "2"
                dfs(i + 1, j, mapa)
                dfs(i - 1, j, mapa)
                dfs(i, j + 1, mapa)
                dfs(i, j - 1, mapa)

    # dfs
    for i in range(len(mapa)):
        for j in range(len(mapa[0])):
            if find_island:
                break
            if mapa[i][j] == "1":
                dfs(i, j, mapa)
                find_island = True
                break

    # bfs
    cantidad_material = 0
    cola = [[-1, -1]]
    direcciones = [[0, 1], [1, 0], [-1, 0], [0, -1]]

    while cola:
        cola_nivel_actual = []

        while cola[0] != [-1, -1]:
            casilla_actual = cola.pop(0)
            for x, y in direcciones:
                nueva_x = x + casilla_actual[0]
                nueva_y = y + casilla_actual[1]

                if 0 <= nueva_x < len(mapa) and 0 <= nueva_y < len(mapa[0]):
                    if mapa[nueva_x][nueva_y] == "1":
                        return cantidad_material
                    elif mapa[nueva_x][nueva_y] != "2":
                        cola_nivel_actual.append([nueva_x, nueva_y])
                        mapa[nueva_x][nueva_y] = "2"

        cola = cola_nivel_actual
        cantidad_material += 1

    return -1
