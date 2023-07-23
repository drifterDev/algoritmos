# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def uniquePaths(self, m: int, n: int) -> int:
        mayor = m + n - 2
        factorial = [1] * (mayor + 1)
        for i in range(2, mayor + 1):
            factorial[i] = i * factorial[i - 1]
        return int(factorial[mayor] / (factorial[n - 1] * factorial[mayor - n + 1]))
