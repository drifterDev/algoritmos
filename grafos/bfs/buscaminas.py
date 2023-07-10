# Se le da un tablero de matriz de m x n caracteres que representa el tablero de juego donde:

#     ‘M’ representa una mina no revelada,
#     ‘E’ representa una casilla vacía no revelada,
#     ‘B’ representa un cuadrado vacío revelado que no tiene minas adyacentes (es decir, arriba, abajo, izquierda, derecha y las 4 diagonales)
#     el dígito (‘1’ a ‘8’) representa cuántas minas están adyacentes a esta casilla revelada.
#     ‘X’ representa una mina revelada.

# También se le da un array entero click donde click = [clickr, clickc] representa la siguiente posición de click entre todas las casillas no reveladas (‘M’ o ‘E’). Devuelve el tablero después de revelar esta posición de acuerdo con las siguientes reglas:

#     Si se revela una mina ‘M’, entonces el juego ha terminado. Debes cambiarla por una ‘X’.
#     Si se revela una casilla vacía “E” sin minas adyacentes, entonces cámbiala por una “B” revelada y todas sus casillas adyacentes no reveladas deben ser reveladas recursivamente.
#     Si se revela una casilla vacía “E” con al menos una mina adyacente, entonces cámbiala por un dígito (“1” a “8”) que represente el número de minas adyacentes.

# Devuelve el tablero cuando no se revelen más casillas.

from collections import deque


class Solution:
    def updateBoard(
        self, tablero: list[list[str]], click: list[int]
    ) -> list[list[str]]:
        numeros = "B123456789"
        queue = deque([click])
        directions = [
            (-1, 0),
            (1, 0),
            (0, -1),
            (0, 1),
            (1, 1),
            (-1, -1),
            (1, -1),
            (-1, 1),
        ]
        while queue:
            i, j = queue.popleft()
            if tablero[i][j] == "B":
                continue
            if tablero[i][j] == "M":
                tablero[i][j] = "X"
                break
            contadorMinasAdyacentes = 0
            casillasAdyacentes = []  # Solo se utiliza si hay minas adyacentes
            for x, y in directions:
                x, y = i + x, j + y
                if (
                    0 <= x < len(tablero)
                    and 0 <= y < len(tablero[0])
                    and tablero[x][y] in ["M", "E"]
                ):
                    if tablero[x][y] == "M":
                        contadorMinasAdyacentes += 1
                    else:
                        casillasAdyacentes.append((x, y))
            if contadorMinasAdyacentes == 0:
                queue.extend(casillasAdyacentes)
            tablero[i][j] = numeros[contadorMinasAdyacentes]
        return tablero
