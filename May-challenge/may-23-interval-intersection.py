'''
 Interval List Intersections
Given two lists of closed intervals, each list of intervals is pairwise disjoint and in sorted order.
Return the intersection of these two interval lists.
(Formally, a closed interval [a, b] (with a <= b) denotes the set of real numbers x with a <= x <= b.
The intersection of two closed intervals is a set of real numbers that is either empty, or can be representedas a closed interval.
For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
'''

class Solution:
    def intervalIntersection(self, A: List[List[int]], B: List[List[int]]) -> List[List[int]]:
        result = []
        a = 0
        b = 0

        while a < len(A) and b < len(B):
            if B[b][0] <= A[a][1] and A[a][0] <= B[b][1]:
                result.append([max(A[a][0], B[b][0]), min(A[a][1], B[b][1])])
            if A[a][1] > B[b][1]:
                b += 1
            else:
                a += 1
                
        return result
