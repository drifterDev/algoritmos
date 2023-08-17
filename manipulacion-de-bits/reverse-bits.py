# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def reverseBits(self, n: int) -> int:
        res = 0
        act = n
        pot = -1
        while act > 0:
            pot += 1
            res += (2 ** (32 - pot - 1)) if act % 2 != 0 else 0
            act = act // 2
        return res
