'''
Two City Scheduling
There are 2N people a company is planning to interview. The cost of flying the i-th person to city A is costs[i][0],
and the cost of flying the i-th person to city B is costs[i][1].
Return the minimum cost to fly every person to a city such that exactly N people arrive in each city.
'''

class Solution:
    def twoCitySchedCost(self, costs: List[List[int]]) -> int:
        def compare(a, b):
            if a[1]-a[0] > b[1]-b[0]:
                return -1
            elif a[1]-a[0] < b[1]-b[0]:
                return 1
            else:
                return 0
        
        ordered_costs = sorted(costs, key=cmp_to_key(compare))
        result = 0
        for idx, pair in enumerate(ordered_costs):
            # print(pair)
            if idx < len(costs)//2:
                result += pair[0]
            else:
                result += pair[1]
                
        return result    
