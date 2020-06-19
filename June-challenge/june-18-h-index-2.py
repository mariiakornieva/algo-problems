'''
 H-Index II
Given an array of citations sorted in ascending order (each citation is a non-negative integer) of a researcher,
write a function to compute the researcher's h-index.
According to the definition of h-index on Wikipedia: "A scientist has index h if h of his/her N papers have at least h citations each,
and the other N − h papers have no more than h citations each."
'''

class Solution:
    def hIndex(self, citations: List[int]) -> int:
        l = 0
        h = len(citations)-1
        n = len(citations)
        
        while l <= h:
            mid = (l+h)//2
            if citations[mid] == n-mid:
                return citations[mid]
            elif citations[mid] > n-mid:
                h = mid-1
            else:
                l = mid+1
        return n-l
