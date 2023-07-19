# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def maxArea(self, height: list[int]) -> int:
        n = len(height)
        p1 = 0
        p2 = n - 1
        mejorArea = 0
        while p1 < p2:
            area = min(height[p1], height[p2]) * (p2 - p1)
            mejorArea = max(mejorArea, area)
            if height[p1] <= height[p2]:
                p1 += 1
            else:
                p2 -= 1
        return mejorArea
