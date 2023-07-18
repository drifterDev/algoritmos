def componentes(mapa: list[list[str]]) -> int:
    dic = {}
    for i in range(len(mapa)):
        for j in range(len(mapa[0])):
            if mapa[i][j] != "#":
                guardar = mapa[i][j]
                num = dfs(i, j, mapa, mapa[i][j])
                if num > 1:
                    if guardar in dic:
                        dic[guardar] = max(dic[guardar], num)
                    else:
                        dic[guardar] = num
    return list(dic.values())


def dfs(i, j, mapa, letra):
    if 0 <= i < len(mapa) and 0 <= j < len(mapa[0]):
        if mapa[i][j] == letra:
            mapa[i][j] = "#"
            n1 = dfs(i + 1, j, mapa, letra)
            n2 = dfs(i - 1, j, mapa, letra)
            n3 = dfs(i, j + 1, mapa, letra)
            n4 = dfs(i, j - 1, mapa, letra)
            return n1 + n2 + n3 + n4 + 1
    return 0


n = int(input())
matriz = []
for i in range(n):
    matriz.append(input().split())
letras = []
numeros = []
for fila in matriz:
    l1 = []
    n1 = []
    for i in range(0, len(fila), 2):
        l1.append(fila[i])
        n1.append(int(fila[i + 1]))
    letras.append(l1)
    numeros.append(n1)
    print(l1)
    print(n1)

player1 = componentes(letras)
player2 = componentes(numeros)
res1 = 0
res2 = 0
for j in player1:
    res1 += ((j) * (j - 1)) // 2
for m in player2:
    res2 += ((m) * (m - 1)) // 2
print(int(res1), int(res2))
