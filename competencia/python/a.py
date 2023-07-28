class Solution:
    def isHappy(self, n: int) -> bool:
        num = str(n)
        n = 0
        for l in num:
            n += int(l) ** 2
        c = 0
        while c < 100000:
            if n == 1:
                return True
            c += 1
            num = str(n)
            n = 0
            for l in num:
                n += int(l) ** 2
        return n == 1
