from typing import List
class Solution:
    def shiftGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])

        total = m * n
        k %= total

        ans = [[0] * n for _ in range(m)]

        for i in range(m):
            for j in range(n):
                # Index in 1D array (before rotation)
                old_index = i * n + j

                # Index in 1D array (after rotation)
                new_index = (old_index + k) % total

                # Convert back from 1D to 2D
                new_row = new_index // n
                new_col = new_index % n

                ans[new_row][new_col] = grid[i][j]

        return ans