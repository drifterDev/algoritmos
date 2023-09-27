# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

class Solution:
    def eraseOverlapIntervals(self, intervals: list[list[int]]) -> int:
        intervals=sorted(intervals, key=lambda x: x[0])
        actual=intervals[0]
        n=len(intervals)
        res=0
        for i in range(1,n):
            if intervals[i][0]>=actual[1]:
                actual=intervals[i]
            else:
                res+=1
                if intervals[i][1]<actual[1]:
                    actual=intervals[i]
        return res