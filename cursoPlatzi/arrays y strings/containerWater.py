def container(nums):
    maximo=0
    n=len(nums)
    for i in range (n):
       for j in range(i+1, n):
          iteracion=min(nums[i], nums[j])*abs(j-i)
          if maximo<iteracion:
             maximo=iteracion
    return maximo
#O(n^2)
if __name__=="__main__":
  nums=list(map(int, input().split()))
  print(container(nums))  

