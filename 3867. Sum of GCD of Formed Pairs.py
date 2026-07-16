class Solution:
    def gcd(self, a,b):
        while b !=0:
            a,b=b,a%b
        return a
    def gcdSum(self, nums: list[int]) -> int:
        n=len(nums)
        mx=nums[0]

        for i in range (1,n):
            if mx < nums[i]:
                mx=nums[i]
            nums[i]=self.gcd(mx,nums[i])

        nums.sort()

        i=0
        j=n-1
        ans=0
        while(i<j):
            ans+=self.gcd(nums[j],nums[i])
            i+=1
            j-=1
        
        return ans