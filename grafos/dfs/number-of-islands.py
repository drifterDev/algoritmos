def numero_islas(mapa: list[list[str]]) -> int:
    cantidad_islas = 0
    for i in range(len(mapa)):
        for j in range(len(mapa[0])):
            if mapa[i][j] == "1":
                dfs(i, j, mapa)
                cantidad_islas += 1
    return cantidad_islas


def dfs(i, j, mapa):
    if 0 <= i < len(mapa) and 0 <= j < len(mapa[0]):
        if mapa[i][j] == "1":
            mapa[i][j] = "2"
            dfs(i + 1, j, mapa)
            dfs(i - 1, j, mapa)
            dfs(i, j + 1, mapa)
            dfs(i, j - 1, mapa)
