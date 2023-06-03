def rotated(nums):
    n=len(nums)
    corte=0
    dic={}
    for j in range(n):
        dic[nums[j]]=j
    for i in range (n-1):
        if nums[i]>nums[i+1]:
           dic["corte"]=i+1
           break
    return dic

def search(nums,dic, target):
    der=len(nums)-1
    izq=0
    while der>=izq:
        mid=izq+(der-izq)//2
        if nums[mid]==target:
            return dic[nums[mid]]
        elif nums[mid]<target:
            izq=mid+1
        else:
            der=mid-1
    return -1

if __name__ == "__main__":
    nums=list(map(int, input().split()))
    target=int(input())
    dic=rotated(nums)
    try:
      nums=nums[dic["corte"]:]+nums[:dic["corte"]]
      print(search(nums, dic, target))
    except:
      print(search(nums, dic, target))
