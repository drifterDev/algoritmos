# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def search(self, nums: list[int], target: int) -> int:
        n = len(nums)
        der = n - 1
        izq = 0
        while izq <= der:
            mid = (der + izq) // 2
            if nums[mid] == target:
                return mid
            elif nums[izq] <= nums[mid]:
                if nums[mid] < target or target < nums[izq]:
                    izq = mid + 1
                else:
                    der = mid - 1
            else:
                if nums[mid] > target or target > nums[der]:
                    der = mid - 1
                else:
                    izq = mid + 1
        return -1
