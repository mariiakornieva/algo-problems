'''
  Cheapest Flights Within K Stops
There are n cities connected by m flights. Each flight starts from city u and arrives at v with a price w.
Now given all the cities and flights, together with starting city src and the destination dst,
your task is to find the cheapest price from src to dst with up to k stops. If there is no such route, output -1.
'''

class Solution:
    def findCheapestPrice(self, n: int, flights: List[List[int]], src: int, dst: int, K: int) -> int:
        # store [src, (dst, cost)]
        adj = [[] for _ in range(n)]
        for i in range(len(flights)):
            adj[flights[i][0]].append((flights[i][1], flights[i][2]))
        
        visited = [False for _ in range(n+1)]
        fare = [sys.maxsize]
        
        def dfs(adj, src, dst, K, fare, total, visited):
            if K < -1:
                return
            if src == dst:
                fare[0] = min(fare[0], total)
                # print(fare)
                return
            
            visited[src] = True
            for i in range(len(adj[src])):
                if not visited[adj[src][i][0]] and total+adj[src][i][1] <= fare[0]:
                    dfs(adj, adj[src][i][0], dst, K-1, fare, total+adj[src][i][1], visited)
            visited[src] = False
        
        dfs(adj, src, dst, K, fare, 0, visited)
        if fare[0] == sys.maxsize:
            return -1
        return fare[0]
