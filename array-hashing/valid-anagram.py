# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# class Solution:
#     def isAnagram(self, s: str, t: str) -> bool:
#         list1 = list(s)
#         list2 = list(t)
#         list1.sort()
#         list2.sort()
#         return list1 == list2


class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        return sorted(list(s)) == sorted(list(t))
