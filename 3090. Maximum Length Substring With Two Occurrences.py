class Solution:
    def maximumLengthSubstring(self, s: str) -> int:
        left=0
        ans=0
        map={}
        for i,ch in enumerate(s):
            map[ch]=map.get(ch,0)+1

            while(map[ch]>2):
                map[s[left]]-=1
                left+=1
            
            ans=max(ans,i-left+1)
        return ans