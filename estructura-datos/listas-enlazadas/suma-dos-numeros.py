# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

# Sumar dos números

# Se dan dos listas enlazadas no vacías que representan dos enteros no negativos. Los dígitos están almacenados en orden inverso, y cada uno de sus nodos contiene un solo dígito. Suma los dos números y devuelve la suma como una lista enlazada.

# Puede suponer que los dos números no contienen ningún cero inicial, excepto el propio número 0.

# Ejemplo 1:
#     Entrada: l1 = [2,4,3], l2 = [5,6,4]
#     Salida: [7,0,8]
# Explicación: 342 + 465 = 807


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next


class Solution:
    def sumarDosNumeros(self, nodo1: ListNode, nodo2: ListNode) -> ListNode:
        cabezaTemporal = ListNode()
        apuntador1 = nodo1
        apuntador2 = nodo2
        nodoActual = cabezaTemporal
        lleva = 0
        while apuntador1 or apuntador2:
            x = apuntador1.val if apuntador1 else 0
            y = apuntador2.val if apuntador2 else 0

            current_sum = lleva + x + y

            lleva = current_sum // 10
            nodoActual.next = ListNode(current_sum % 10)
            nodoActual = nodoActual.next

            if apuntador1:
                apuntador1 = apuntador1.next
            if apuntador2:
                apuntador2 = apuntador2.next

        if lleva:
            nodoActual.next = ListNode(lleva)
        return cabezaTemporal.next
