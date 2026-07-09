from typing import List
class Solution:
    def pathExistenceQueries(self, n: int, nums: List[int], maxDiff: int, queries: List[List[int]]) -> List[bool]:
        path = [0] * n

        for i in range(1, n):
            is_new = 1 if nums[i] - nums[i - 1] > maxDiff else 0
            path[i] = path[i - 1] + is_new

        ans = []

        for u, v in queries:
            ans.append(path[u] == path[v])

        return ans