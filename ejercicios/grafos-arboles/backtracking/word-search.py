# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def exist(self, board: list[list[str]], word: str) -> bool:
        existe = False

        def dfs(board: list[list[str]], x: int, y: int, index: int):
            nonlocal existe
            if (
                x < 0
                or y < 0
                or x >= len(board)
                or y >= len(board[0])
                or word[index] != board[x][y]
            ):
                return
            board[x][y] = "#"
            if index + 1 == len(word):
                existe = True
                return
            dfs(board, x + 1, y, index + 1)
            dfs(board, x - 1, y, index + 1)
            dfs(board, x, y + 1, index + 1)
            dfs(board, x, y - 1, index + 1)
            board[x][y] = word[index]

        n = len(board)
        m = len(board[0])
        for i in range(n):
            for j in range(m):
                if word[0] == board[i][j]:
                    dfs(board, i, j, 0)
                    if existe:
                        return True
        return existe
