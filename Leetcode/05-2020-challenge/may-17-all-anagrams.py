'''
Find All Anagrams in a String
Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
The order of output does not matter.
'''

class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        window = len(p)
        target = Counter(p)
        result = []
        for i in range(len(s)-window+1):
            j = i+window
            if s[i] in p and not (Counter(s[i:j]) - target):
                result.append(i)        
        
        return result
