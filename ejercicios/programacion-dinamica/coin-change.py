# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def coinChange(self, coins: list[int], amount: int) -> int:
        coinsHave = {}
        coins.sort()
        for n in coins:
            coinsHave[n] = 1
        dp = [(2**31) - 1] * (amount + 1)
        dp[0] = 0
        for i in range(1, amount + 1):
            if i in coinsHave:
                dp[i] = 1
            else:
                for n in coins:
                    if i - n >= 0:
                        dp[i] = min(dp[i], 1 + dp[i - n])
                    else:
                        break
        return -1 if dp[amount] == ((2**31) - 1) else dp[amount]
