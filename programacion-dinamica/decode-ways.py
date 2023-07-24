# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def numDecodings(self, s: str) -> int:
        n = len(s)
        dp = {n: 1}
        for i in range(n - 1, -1, -1):
            if s[i] == "0":
                dp[i] = 0
            else:
                dp[i] = dp[i + 1]
            if i + 1 > n - 1:
                continue
            if s[i] == "1" or s[i] == "2" and s[i + 1] in "0123456":
                dp[i] += dp[i + 2]
        return dp[0]
