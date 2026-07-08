from typing import List
class Solution:
    MOD = 10**9 + 7
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        n=len(s)
        pref_sum = [0] * (n + 1)
        pref_num = [0] * (n + 1)
        pref_cnt = [0] * (n + 1)

        # Powers of 10 modulo MOD
        pow10 = [1] * (n + 1)
        for i in range(1, n + 1):
            pow10[i] = (pow10[i - 1] * 10) % self.MOD
        
        # Build prefix arrays
        for i in range(n):
            pref_sum[i + 1] = pref_sum[i]
            pref_num[i + 1] = pref_num[i]
            pref_cnt[i + 1] = pref_cnt[i]

            if s[i] != '0':
                digit = int(s[i])

                pref_sum[i + 1] += digit
                pref_cnt[i + 1] += 1
                pref_num[i + 1] = (pref_num[i] * 10 + digit) % self.MOD
        
        ans = []
        for l, r in queries:
            # Sum of non-zero digits
            digit_sum = pref_sum[r + 1] - pref_sum[l]

            # Count of non-zero digits
            digit_count = pref_cnt[r + 1] - pref_cnt[l]

            # Concatenated number modulo MOD
            number = (
                pref_num[r + 1]
                - (pref_num[l] * pow10[digit_count]) % self.MOD
                + self.MOD
            ) % self.MOD

            ans.append((number * digit_sum) % self.MOD)

        return ans