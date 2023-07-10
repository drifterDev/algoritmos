def existe_palabra(matriz: list[list[str]], palabra: str) -> bool:
    existe = False

    def dfs(matriz: list[list[str]], x: int, y: int, index: int):
        nonlocal existe
        if (
            x < 0
            or y < 0
            or x >= len(matriz)
            or y >= len(matriz[0])
            or palabra[index] != matriz[x][y]
        ):
            return
        matriz[x][y] = "#"
        if index + 1 == len(palabra):
            existe = True
            return
        dfs(matriz, x + 1, y, index + 1)
        dfs(matriz, x - 1, y, index + 1)
        dfs(matriz, x, y + 1, index + 1)
        dfs(matriz, x, y - 1, index + 1)
        matriz[x][y] = palabra[index]

    for i in range(len(matriz)):
        for j in range(len(matriz[0])):
            if palabra[0] == matriz[i][j]:
                dfs(matriz, i, j, 0)
                if existe:
                    return True
    return existe
