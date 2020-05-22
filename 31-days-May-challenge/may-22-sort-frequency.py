'''
Sort Characters By Frequency
Given a string, sort it in decreasing order based on the frequency of characters.
'''

class Solution:
    def frequencySort(self, s: str) -> str:
        result = str()
        for c, n in Counter(s).most_common(len(s)):
            result += ''.join([c for _ in range(n)])
        return result
