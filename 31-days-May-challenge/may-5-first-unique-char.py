'''
First Unique Character in a String
Given a string, find the first non-repeating character in it and return it's index. If it doesn't exist, return -1.
'''

class Solution:
    def firstUniqChar(self, s: str) -> int:
        # dict(char, occurrence)
        chars = {c: 0 for c in s}
        for c in s:
            chars[c] += 1
        for idx, c in enumerate(s):
            if chars[c] == 1:
                return idx
            
        return -1
