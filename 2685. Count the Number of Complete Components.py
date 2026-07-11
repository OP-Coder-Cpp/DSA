from typing import List

class Solution:
    def dfs(self, node, adj, vis, component):
        vis[node] = True
        component.append(node)

        for nei in adj[node]:
            if not vis[nei]:
                self.dfs(nei, adj, vis, component)

    def countCompleteComponents(self, n: int, edges: List[List[int]]) -> int:
        adj = [[] for _ in range(n)]
        degree = [0] * n

        # Build graph and degree array
        for u, v in edges:
            adj[u].append(v)
            adj[v].append(u)

            degree[u] += 1
            degree[v] += 1

        vis = [False] * n
        ans = 0

        for i in range(n):
            if vis[i]:
                continue

            component = []
            self.dfs(i, adj, vis, component)

            size = len(component)
            complete = True

            for node in component:
                if degree[node] != size - 1:
                    complete = False
                    break

            if complete:
                ans += 1

        return ans