from typing import List

class Solution:
    def sequentialDigits(self, low: int, high: int) -> List[int]:
        ans = []

        # Try every possible digit length (2 to 9)
        for length in range(2, 10):

            # Try every possible starting digit
            for start in range(1, 11 - length):

                num = 0

                # Construct the sequential number
                for digit in range(start, start + length):
                    num = num * 10 + digit

                # Check if it lies within the range
                if low <= num <= high:
                    ans.append(num)

        return ans