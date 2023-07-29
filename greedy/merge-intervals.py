# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def merge(self, intervals: list[list[int]]) -> list[list[int]]:
        intervals=sorted(intervals, key=lambda x: x[0])
        res=[]
        actual=intervals[0]
        n=len(intervals)
        for i in range (1, n):
            if intervals[i][0]>actual[1]:
                res.append(actual)
                actual=intervals[i]
            elif intervals[i][0]<=actual[1]:
                actual=[min(actual[0], intervals[i][0]),max(actual[1], intervals[i][1])]
        res.append(actual)
        return res