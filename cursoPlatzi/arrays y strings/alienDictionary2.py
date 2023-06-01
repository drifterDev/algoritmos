def is_alien_sorted(words, orden):
    dic={}
    for i in range(26):
        dic[words[i]]=i
    n=len(words)
    for j in range(n-1):
      if not comparar(words[j], words[j+1]):
          return False
    return True
      
def comparar(dic, word1, word2):
    n=min(len(word1), len(word2))
    for k in range(n):
        if dic[word1[k]]<dic[word2[k]]:
            return True
        elif dic[word1[k]]>dic[word2[k]]:
            return False
    return len(word1)<=len(word2)
              
if __name__=="__main__":
    words=input().split()
    orden=input()
    print(is_alien_sorted(words, orden))