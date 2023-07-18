class Solution:
    def groupAnagrams(self, strs: list[str]) -> list[list[str]]:
        anagrams = {}
        for string in strs:
            actual = "".join(sorted(list(string)))
            try:
                anagrams[actual].append(string)
            except:
                anagrams[actual] = [string]
        return anagrams.values()
