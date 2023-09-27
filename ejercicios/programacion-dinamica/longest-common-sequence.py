# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def longestCommonSubsequence(self, text1: str, text2: str) -> int:
        n = len(text1)
        m = len(text2)
        dp = [[0 for _ in range(n + 1)] for _ in range(m + 1)]
        for i in range(m - 1, -1, -1):
            for j in range(n - 1, -1, -1):
                if text1[j] == text2[i]:
                    dp[i][j] = 1 + dp[i + 1][j + 1]
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j + 1])
        return dp[0][0]


# solucion = Solution()
# print(solucion.longestCommonSubsequence("abcde", "ace"))
# print(solucion.longestCommonSubsequence("abc", "abc"))
# print(solucion.longestCommonSubsequence("abc", "def"))
# matrix = solucion.longestCommonSubsequence("bsbininm", "jmjkbkjkv")
# matrix = solucion.longestCommonSubsequence("bsbininm", "jmjkbkjkv")
# matrix = solucion.longestCommonSubsequence("bsbininm", "jmjkbkjkv")
# matrix = solucion.longestCommonSubsequence("abcde", "ace")
# for fila in matrix:
#     print(fila)
