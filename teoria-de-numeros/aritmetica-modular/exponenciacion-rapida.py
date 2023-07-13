def fastPow(a, b):
    MOD = 10**9 + 7
    if b == 0:
        return 1
    if b == 1:
        return a
    if b % 2 == 0:
        tmp = fastPow(a, b // 2)
        return (tmp * tmp) % MOD
    return (a * fastPow(a, b - 1)) % MOD
