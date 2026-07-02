from typing import List
from collections import deque

class Solution:
    def findSafeWalk(self, grid: List[List[int]], health: int) -> bool:
        n = len(grid)
        m = len(grid[0])

        score = [[-1] * m for _ in range(n)]

        start_life = health - grid[0][0]
        if start_life < 1:
            return False

        score[0][0] = start_life

        q = deque()
        q.append((start_life, 0, 0))

        dx = [0, 0, 1, -1]
        dy = [1, -1, 0, 0]

        while q:
            life, x, y = q.popleft()

            if x == n - 1 and y == m - 1:
                return True

            for i in range(4):
                new_x = x + dx[i]
                new_y = y + dy[i]

                if 0 <= new_x < n and 0 <= new_y < m:
                    new_life = life - grid[new_x][new_y]

                    if new_life >= 1 and score[new_x][new_y] < new_life:
                        score[new_x][new_y] = new_life
                        q.append((new_life, new_x, new_y))

        return False