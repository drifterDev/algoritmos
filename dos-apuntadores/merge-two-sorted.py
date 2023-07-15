# Autor: Mateo Álvarez Murillo
# Fecha de creación: 2023

# Este código se proporciona bajo la Licencia MIT.
# Para más información, consulta el archivo LICENSE en la raíz del repositorio.

def merge_lists(nums1, n1, nums2,n2):
    nums0=[]
    n=n1+n2
    apuntador1=0
    apuntador2=0
    for i in range(n):
        if(apuntador1<n1 and apuntador2<n2):
            if nums1[apuntador1]<=nums2[apuntador2]:
              nums0.append(nums1[apuntador1])
              apuntador1+=1
            else:
              nums0.append(nums2[apuntador2])
              apuntador2+=1
        elif(apuntador1<n1):
          nums0.append(nums1[apuntador1])
          apuntador1+=1
        elif(apuntador2<n2):
            nums0.append(nums2[apuntador2])
            apuntador2+=1
    return nums0

