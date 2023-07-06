n = int(input())
x = 0
y = 0
z = 0
for vector in range(n):
    px, py, pz = list(map(int, input().split()))
    x += px
    y += py
    z += pz
if x == 0 and y == 0 and z == 0:
    print("YES")
else:
    print("NO")
