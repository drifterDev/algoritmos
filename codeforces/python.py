nums = [23, 39, 40, 41, 43, 47, 51, 58, 63, 66, 67, 69, 72]
result = 0
result2 = 0
for i in nums:
    result += i
    result2 += i**2
print(result)
print((result2 / 13) - ((result) ** 2))
print(((result2 / 13) - (result**2)) ** 0.5)
