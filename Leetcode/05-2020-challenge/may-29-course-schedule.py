'''
Course Schedule
There are a total of numCourses courses you have to take, labeled from 0 to numCourses-1.
Some courses may have prerequisites, for example to take course 0 you have to first take course 1,
which is expressed as a pair: [0,1]
Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
'''

class Solution:
    def canFinish(self, numCourses: int, prerequisites: List[List[int]]) -> bool:
        # Directed Graph (adjacency matrix)
        adj = [[] for _ in range(numCourses)]
        for i in range(len(prerequisites)):
            adj[prerequisites[i][0]].append(prerequisites[i][1])
        
        def isCyclic(adj, visited, i):
            if visited[i] == 2:
                return True
            
            visited[i] = 2
            for j in range(len(adj[i])):
                if visited[adj[i][j]] != 1:
                    if isCyclic(adj, visited, adj[i][j]):
                        return True
            visited[i] = 1
            return False
        
        visited = [0 for _ in range(numCourses)]
        for i in range(numCourses):
            if visited[i] == 0:
                if isCyclic(adj, visited, i):
                    return False
        return True
