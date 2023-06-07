def trappingRainWater(alturas):
    izq = 0
    der = len(alturas)-1 
    maxIzq = 0
    maxDer = 0
    aguaRecolectada = 0

    while(izq <= der):
        if(alturas[izq]<=alturas[der]): 
            if(alturas[izq]>=maxIzq): 
                maxIzq = alturas[izq]
            else: 
                aguaRecolectada += maxIzq - alturas[izq]
            izq += 1
        else:
            if(alturas[der]>=maxDer): 
                maxDer = alturas[der]
            else: 
                aguaRecolectada += maxDer - alturas[der]
            der -= 1
    return aguaRecolectada

if __name__=="__main__":
    nums=list(map(int, input().split()))
    print(trappingRainWater(nums))
