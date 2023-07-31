# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# FIXME: corregir el nombre de la funcion
class Solution:
    def hammingWeight(self, n: int) -> int:
        res=n
        count=0
        while res>1:
            count+= 1 if res%2!=0 else 0
            res=res//2
        return count

