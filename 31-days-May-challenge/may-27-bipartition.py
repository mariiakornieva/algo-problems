'''
  Possible Bipartition
Given a set of N people (numbered 1, 2, ..., N), we would like to split everyone into two groups of any size.
Each person may dislike some other people, and they should not go into the same group. 
Formally, if dislikes[i] = [a, b], it means it is not allowed to put the people numbered a and b into the same group.
Return true if and only if it is possible to split everyone into two groups in this way.
'''

class Solution:
    def possibleBipartition(self, N: int, dislikes: List[List[int]]) -> bool:
        adj = [[] for _ in range(N+1)]
        for i in range(len(dislikes)):
            adj[dislikes[i][0]].append(dislikes[i][1])
            adj[dislikes[i][1]].append(dislikes[i][0])
        # print(adj)
            
        def bipartition(adj, N, node, color):
            q = deque()
            q.append(node)
            color[node]=1
            
            while q:
                curr = q.pop()
                for el in adj[curr]:
                    if color[el] == color[curr]:
                        return False
                    if color[el]==-1:
                        color[el] = 1-color[curr]
                        q.append(el)
            return True
            
            
        color = [-1 for _ in range(N+1)]
        for i in range(N+1):
            if color[i] == -1:
                if not bipartition(adj, N, i, color):
                    return False
                
        return True
        
