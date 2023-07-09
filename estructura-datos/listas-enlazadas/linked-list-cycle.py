class Nodo:
    def __init__(self, x):
        self.valor = x
        self.siguiente = None


# Primera implementación
# O(n)
def hasCycle(cabeza: Nodo) -> bool:
    if not cabeza:
        return False
    lento = cabeza
    rapido = cabeza.siguiente
    while lento != rapido:
        if not rapido or not rapido.siguiente:
            return False
        lento = lento.siguiente
        rapido = rapido.siguiente.siguiente
    return True


# Segunda implementación
# O(n)
def hasCycle2(cabeza: Nodo) -> bool:
    if not cabeza:
        return False
    lento = cabeza
    rapido = cabeza.siguiente
    while rapido and rapido.siguiente:
        if rapido == lento:
            return True
        lento = lento.siguiente
        rapido = rapido.siguiente.siguiente
    return False
