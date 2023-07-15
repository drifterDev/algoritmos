# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

def container(nums):
  n=len(nums)
  p1=0
  p2=n-1
  mejorArea=0
  while p1<p2:
    area=min(nums[p1], nums[p2])*(p2-p1)
    if mejorArea<area:
      mejorArea=area
    if nums[p1]<=nums[p2]:
       p1+=1
    else:
       p2-=1
  return mejorArea

if __name__=="__main__":
    nums=list(map(int, input().split()))
    print(container(nums))