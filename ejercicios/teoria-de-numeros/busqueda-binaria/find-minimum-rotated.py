# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def findMin(self, nums: list[int]) -> int:
        nums.sort()
        n = len(nums)
        der = n - 1
        izq = 0
        while der != izq and der - 1 != izq:
            mid = izq + (der - izq) // 2
            if nums[izq] > nums[izq + 1]:
                izq += 1
                break
            if nums[der] > nums[izq]:
                der = mid
            elif nums[izq] > nums[der]:
                izq = mid
        return min(nums[izq], nums[der])
