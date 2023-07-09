n = int(input())
nums = list(map(int, input().split()))
deposito = 0
for j in range(20240000):
    for i in range(n):
        nums[i] += deposito
        deposito = nums[i] / 2
        nums[i] -= deposito
nums[0] += deposito
for n in nums:
    print(round(n, 6), end=" ")
