# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Dada una cuadrícula 2D formada por 0s (tierra) y 1s (agua). Una isla es un grupo máximo de 0s conectado en 4 direcciones y una isla cerrada es una isla totalmente (toda a la izquierda, arriba, derecha, abajo) rodeada de 1s. Devuelve el número de islas cerradas.

# Ejemplo 1:
# Input: grid = [[1,1,1,1,1,1,1,0],[1,0,0,0,0,1,1,0],[1,0,1,0,1,1,1,0],[1,0,0,0,0,1,0,1],[1,1,1,1,1,1,1,0]]
# Salida: 2
# Explicación: Las islas en gris están cerradas porque están completamente rodeadas de agua (grupo de 1s).


def closedIsland(mapa: list[list[int]]) -> int:
    if len(mapa) == 0:
        return 0

    cantidad = 0
    for i in range(len(mapa)):
        for j in range(len(mapa[0])):
            if mapa[i][j] == 0 and dfs(i, j, mapa):
                cantidad += 1
    return cantidad


def dfs(i, j, mapa):
    if not (0 <= i < len(mapa) and 0 <= j < len(mapa[0])):
        return False
    if mapa[i][j] == 1:
        return True
    mapa[i][j] = 1
    A = dfs(i + 1, j)
    B = dfs(i - 1, j)
    C = dfs(i, j + 1)
    D = dfs(i, j - 1)
    return A and B and C and D
