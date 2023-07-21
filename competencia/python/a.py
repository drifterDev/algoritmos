def ranas(n, nums):
    array = [0] * (n + 1)
    mayor = 0
    nums.sort()
    for i in range(n):
        if nums[i] > n:
            break
        for j in range(0, n + 1, nums[i]):
            array[j] += 1
            if j == 0:
                continue
            mayor = max(array[j], mayor)
    return mayor


cases = int(input())
for i in range(cases):
    n = int(input())
    nums = list(map(int, input().split()))
    res = ranas(n, nums)
    print(res)
