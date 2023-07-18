class Solution:
    def isValid(self, s: str) -> bool:
        cola = [s[0]]
        n = len(s)
        for i in range(1, n):
            try:
                if s[i] == ")":
                    if cola[-1] != "(":
                        return False
                    cola.pop()
                elif s[i] == "}":
                    if cola[-1] != "{":
                        return False
                    cola.pop()
                elif s[i] == "]":
                    if cola[-1] != "[":
                        return False
                    cola.pop()
                else:
                    cola.append(s[i])
            except:
                return False
        return len(cola) == 0
