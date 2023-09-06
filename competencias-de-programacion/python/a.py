n=int(input())
count=0
num=0
while (count<n):
  num+=5
  act=num
  while(act%5==0):
    count+=1
    act/=5
if count==n:
  print(5)
  for k in range(4):
    print(num+k, end=" ")
  print(num+4)
else: print(0)