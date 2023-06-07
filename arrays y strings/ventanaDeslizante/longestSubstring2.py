def longest(string):
    inicio=0
    n=len(string)
    caracteresPosicion={}
    maximo=0
    for fin in range (n):
        if string[fin] in caracteresPosicion and inicio<=caracteresPosicion[string[fin]]:
            inicio=caracteresPosicion[string[fin]]+1
        caracteresPosicion[string[fin]]=fin
        maximo=max(maximo, fin-inicio+1)
    return maximo    

if __name__=="__main__":
    string=input()
    print(longest(string))