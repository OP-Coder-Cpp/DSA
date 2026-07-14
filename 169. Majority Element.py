from typing import List
class Solution:
    def majorityElement(self, nums: List[int]) -> int:
        nums.sort()
        n=len(nums)

        count=1
        i=1

        while i < n:
            if nums[i]==nums[i-1]:
                count+=1
            else:
                if count>n//2 :
                    break
                count=1
            i+=1

        
        return nums[i-1]