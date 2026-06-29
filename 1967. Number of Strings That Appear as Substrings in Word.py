from typing import List

class Solution:
    def numOfStrings(self, patterns: List[str], word: str) -> int:
        ans=0

        for pattern in patterns:
            n=len(pattern)

            for j in range(len(word)):
                if word[j] == pattern[0]:
                    if j + n <= len(word) and word[j:j + n] == pattern:
                        ans += 1
                        break
        
        return ans