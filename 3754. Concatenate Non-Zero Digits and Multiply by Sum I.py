class Solution:
    def sumAndMultiply(self, n: int) -> int:
       s=0
       x=0
       power=0
       while(n>0):
        temp=n%10
        if(temp!=0):
            x=(temp*(10**power))+x
            power+=1
        
        s+=temp
        n//=10
    
       return s*x