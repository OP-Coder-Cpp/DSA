from typing import List
class Solution:
    def minimumDeletions(self, nums: List[int]) -> int:
        n=len(nums)

        mn_pos=nums.index(min(nums))
        mx_pos=nums.index(max(nums))

        left=min(mn_pos,mx_pos)
        right=max(mn_pos,mx_pos)

        option1=right+1
        option2=n-left
        option3=(left+1)+(n-right)

        return min(option1,option2,option3)