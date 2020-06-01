'''
  Permutation in String
Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1.
In other words, one of the first string's permutations is the substring of the second string.
'''

class Solution:
    def checkInclusion(self, s1: str, s2: str) -> bool:
        if len(s2) < len(s1):
            return False
        
        substring = Counter(s1)
        window = len(s1)
        for i in range(len(s2)-window+1):
            j = i+window
            if s2[i] in substring and not (substring - Counter(s2[i:j])):
                return True
        return False
            
