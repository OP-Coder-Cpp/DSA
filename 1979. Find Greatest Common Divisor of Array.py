from typing import List
class Solution:
    def gcd(self,a,b):
        while(b!=0):
            a,b=b,a%b
        return a
    def findGCD(self, nums: List[int]) -> int:
        mn=nums[0]
        mx=nums[0]
        for num in nums:
            if mn>num:
                mn=num
            elif mx<num:
                mx=num
        
        return self.gcd(mx,mn)