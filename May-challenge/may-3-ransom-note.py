// Ransom Note
// O(n+m) time and space, where n, m = sizes of input strings

class Solution:
    def canConstruct(self, ransomNote: str, magazine: str) -> bool:
        return not collections.Counter(ransomNote) - collections.Counter(magazine)
