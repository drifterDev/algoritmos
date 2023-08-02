# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.


class Solution:
    def evalRPN(self, tokens: list[str]) -> int:
        res = []
        n = len(tokens)
        for i in range(n):
            try:
                res.append(int(tokens[i]))
            except:
                a = res[-2]
                b = res[-1]
                res.pop()
                res.pop()
                if tokens[i] == "+":
                    res.append(a + b)
                elif tokens[i] == "-":
                    res.append(a - b)
                elif tokens[i] == "*":
                    res.append(a * b)
                else:
                    res.append(int(a / b))
        return int(res[0])


solu = Solution()

solu.evalRPN(["2", "1", "+", "3", "*"])
print("******************************")
solu.evalRPN(["4", "13", "5", "/", "+"])
print("******************************")
solu.evalRPN(["10", "6", "9", "3", "+", "-11", "*", "/", "*", "17", "+", "5", "+"])
