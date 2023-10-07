# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

class Node:
    def __init__(self, key):
        self.key = key
        self.left = None
        self.right = None

class BinarySearchTree:
    def __init__(self):
        self.root = None

    def insert(self, key):
        self.root = self._insert_recursively(self.root, key)

    def _insert_recursively(self, root, key):
        if root is None:
            return Node(key)
        if key < root.key:
            root.left = self._insert_recursively(root.left, key)
        elif key > root.key:
            root.right = self._insert_recursively(root.right, key)
        return root

    def search(self, key):
        if self._search_recursively(self.root, key) != None:
            return True
        else:
            return False

    def _search_recursively(self, root, key):
        if root is None or root.key == key:
            return root
        if key < root.key:
            return self._search_recursively(root.left, key)
        return self._search_recursively(root.right, key)

    def delete(self, key):
        self.root = self._delete_recursively(self.root, key)

    def _delete_recursively(self, root, key):
        if root is None:
            return root

        if key < root.key:
            root.left = self._delete_recursively(root.left, key)
        elif key > root.key:
            root.right = self._delete_recursively(root.right, key)
        else:
            if root.left is None:
                return root.right
            elif root.right is None:
                return root.left

            root.key = self._min_value_node(root.right).key
            root.right = self._delete_recursively(root.right, root.key)

        return root

    def _min_value_node(self, node):
        current = node
        while current.left is not None:
            current = current.left
        return current

    def inorder(self):
        elements = []
        self._inorder_recursively(self.root, elements)
        return elements

    def _inorder_recursively(self, root, elements):
        if root:
            self._inorder_recursively(root.left, elements)
            elements.append(root.key)
            self._inorder_recursively(root.right, elements)

# Ejemplo de aplicacion
bst = BinarySearchTree()
bst.insert(10)
bst.insert(5)
bst.insert(15)
bst.insert(3)
bst.insert(7)

print(bst.search(7))  # True
print(bst.search(9))  # False

print(bst.inorder())  # [3, 5, 7, 10, 15]

bst.delete(5)
print(bst.inorder())  # [3, 7, 10, 15]