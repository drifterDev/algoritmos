# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Busqueda binaria
# Algoritmo para hacer una busqueda en una lista ordenada en O(Log n)


def busqueda_binaria(array, target):
    class Solution:
        def search(self, nums: list[int], target: int) -> int:
            low = 0
            high = len(nums) - 1
            while low <= high:
                mid = (low + high) // 2
                if nums[mid] == target:
                    return mid
                elif nums[mid] > target:
                    high = mid - 1
                else:
                    low = mid + 1
            return -1
