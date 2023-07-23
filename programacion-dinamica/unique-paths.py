# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        dp = [[0 for _ in range(n)] for _ in range(m)]
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if i == m - 1 and j == n - 1:
                    dp[i][j] = 1
                elif i == m - 1:
                    dp[i][j] = dp[i][j + 1]
                elif j == n - 1:
                    dp[i][j] = dp[i + 1][j]
                else:
                    dp[i][j] = dp[i + 1][j] + dp[i][j + 1]

        return dp[0][0]


solucion = Solution()
print(solucion.uniquePaths(3, 7))
print(solucion.uniquePaths(3, 2))
