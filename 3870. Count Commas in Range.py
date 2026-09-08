class Solution:
    def countCommas(self, n: int) -> int:
        count=0

        if n <=999:
            return 0
        
        for i in range(1000,n+1):
            temp=i
            while(temp>999):
                count+=1
                temp/=1000
        
        return count