# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def maxProfit(self, prices: list[int]) -> int:
        maxi = 0
        n = len(prices)
        maximos = []
        ultimo = 0
        for i in range(n - 1, -1, -1):
            maximos.append(max(ultimo, prices[i]))
            ultimo = maximos[-1]
        maximo = 0
        for j in range(n):
            maximo = max(maximo, maximos[n - 1 - j] - prices[j])
        return maximo
