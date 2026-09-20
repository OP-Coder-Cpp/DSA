class Solution:
    def reverseDegree(self, s: str) -> int:
        ans=0

        for i,ch in enumerate(s):
            d=(122-ord(ch)+1)*(i+1)
            ans+=d
        return ans