from typing import List
from collections import defaultdict
import heapq

class Solution:
    def check(self, mid: int, n: int, k: int, adj) -> bool:
        INF = float('inf')
        dist = [INF] * n

        dist[0] = 0

        pq = []
        heapq.heappush(pq, (0, 0))  # (distance, node)

        while pq:
            d, node = heapq.heappop(pq)

            if d > k:
                return False

            if node == n - 1:
                return True

            if d > dist[node]:
                continue

            for adj_node, edge_cost in adj[node]:

                # We only allow edges whose cost >= mid
                if edge_cost < mid:
                    continue

                if d + edge_cost < dist[adj_node]:
                    dist[adj_node] = d + edge_cost
                    heapq.heappush(pq, (d + edge_cost, adj_node))

        return False

    def findMaxPathScore(self, edges: List[List[int]], online: List[bool], k: int) -> int:
        n = len(online)

        adj = defaultdict(list)

        left = float('inf')
        right = 0

        for u, v, w in edges:

            if not online[u] or not online[v]:
                continue

            adj[u].append((v, w))

            left = min(left, w)
            right = max(right, w)

        answer = -1

        while left <= right:

            mid = left + (right - left) // 2

            if self.check(mid, n, k, adj):
                answer = mid
                left = mid + 1
            else:
                right = mid - 1

        return answer