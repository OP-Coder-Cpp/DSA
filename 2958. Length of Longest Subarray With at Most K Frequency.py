from typing import List
class Solution:
    def maxSubarrayLength(self, nums: List[int], k: int) -> int:
        left=0
        ans=0
        umap={}
        for i,num in enumerate(nums):
            umap[num] = umap.get(num, 0) + 1

            while(umap[num]>k):
                umap[nums[left]]-=1
                left+=1
            
            ans=max(ans,i-left+1)
        
        return ans