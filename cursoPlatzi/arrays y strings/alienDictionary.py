# alfabeto=list("abcdefghijklmnopqrstuvwxyz")
# words=input().split()
# orden=input()
# dic={}
# for i in range(26):
#     dic[orden[i]]=alfabeto[i]
# m=len(words)
# for y in range (m):
#     n=len(words[y])
#     new=""
#     for j in range (n):
#         new+=dic[words[y][j]]
#     words[y]=new
# orden=sorted(words)
# if (words==orden):
#     print("YES")
# else:
#     print("NO")


def is_alien_sorted(words, orden):
    dic={}
    for i in range(26):
        dic[orden[i]]=i
    n=len(words) 
    for j in range(n-1): #O(n*m)
      if not comparar(dic, words[j], words[j+1]):
          return False
    return True
      
def comparar(dic, word1, word2):
    n=min(len(word1), len(word2)) 
    for k in range(n): #O(m)
        if dic[word1[k]]<dic[word2[k]]:
            return True
        elif dic[word1[k]]>dic[word2[k]]:
            return False
    return len(word1)<=len(word2)

#La complejidad es O(n) porque las constantes se desprecian
if __name__=="__main__":
    words=input().split()
    orden=input()
    print(is_alien_sorted(words, orden))