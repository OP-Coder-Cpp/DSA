from typing import List
from collections import Counter

class Solution:
    def maximumLength(self, nums: List[int]) -> int:
        mp = Counter(nums)

        ans = 1

        # Handle 1 separately
        if 1 in mp:
            cnt = mp[1]
            ans = max(ans, cnt if cnt % 2 else cnt - 1)

        for num in mp:
            if num == 1:
                continue

            x = num
            length = 0

            while x in mp and mp[x] >= 2:
                length += 2

                if x > 10**9:
                    break      # avoid overflow

                x *= x

            if x in mp:
                length += 1
            else:
                length -= 1

            ans = max(ans, length)

        return ans