# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Dado un tablero de m x n donde cada celda es un acorazado ‘X’ o un vacío ‘.’, devuelva el número de los barcos en el tablero. Los barcos sólo pueden colocarse horizontal o verticalmente en el tablero. En otras palabras, sólo pueden tener la forma 1 x k (1 fila, k columnas) o k x 1 (k filas, 1 columna), donde k puede ser de cualquier tamaño. Al menos una celda horizontal o vertical separa dos barcos (es decir, no hay barcos adyacentes).

# Ejemplo 1:
# Entrada: tablero = [[“X”,".",".", “X”],[".",".", “X”],[".",".", “X”]
# Salida: 2

# Ejemplo 2:
# Entrada: tablero = [["."]]
# Salida: 0


def countBattleships(tablero: list[list[str]]) -> int:
    cantidad = 0
    for i in range(len(tablero)):
        for j in range(len(tablero[0])):
            if tablero[i][j] == "X":
                dfs(i, j, tablero)
                cantidad += 1
    return cantidad


def dfs(i, j, tablero):
    if 0 <= i < len(tablero) and 0 <= j < len(tablero[0]) and tablero[i][j] == "X":
        tablero[i][j] = "."
        dfs(i + 1, j)
        dfs(i - 1, j)
        dfs(i, j - 1)
        dfs(i, j + 1)
