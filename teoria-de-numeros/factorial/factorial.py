# Forma 1
fact = [0] * 100


def calculateFact() -> None:
    fact[0] = 1
    for i in range(1, 100):
        fact[i] = i * fact[i - 1]


# Forma 2
fact = [0] * 100
MOD = 10007


def calculateFact() -> None:
    fact[0] = 1
    for i in range(1, 100):
        fact[i] = (i * fact[i - 1]) % MOD
