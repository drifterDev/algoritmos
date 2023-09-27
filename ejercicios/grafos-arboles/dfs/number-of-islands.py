# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def numIslands(self, grid: list[list[str]]) -> int:
        def dfs(i, j, mapa):
            if 0 <= i < len(mapa) and 0 <= j < len(mapa[0]):
                if mapa[i][j] == "1":
                    mapa[i][j] = "2"
                    dfs(i + 1, j, mapa)
                    dfs(i - 1, j, mapa)
                    dfs(i, j + 1, mapa)
                    dfs(i, j - 1, mapa)

        cantidad_islas = 0
        for i in range(len(grid)):
            for j in range(len(grid[0])):
                if grid[i][j] == "1":
                    dfs(i, j, grid)
                    cantidad_islas += 1
        return cantidad_islas
