cases = int(input())
for case in range(cases):
    n, m = map(int, input().split())
    res = "YES" if n % m == 0 else "NO"
    print(res)
