from typing import List
class Solution:
    def removeCoveredIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort(key=lambda x: (x[0], -x[1]))

        ans = 0
        last_max_end = 0

        for start, end in intervals:
            if end > last_max_end:
                ans += 1
                last_max_end = end

        return ans