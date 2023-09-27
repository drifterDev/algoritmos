# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def canPartition(self, nums: list[int]) -> bool:
        suma = sum(nums)
        self.seet = {0}
        if suma % 2 != 0:
            return False
        else:
            suma = suma // 2
            for n in nums:
                seetAct = set()
                for s in self.seet:
                    seetAct.add(s + n)
                    seetAct.add(s)
                self.seet = seetAct
                if suma in self.seet:
                    return True
            return False
