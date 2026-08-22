class Solution:
    def checkDivisibility(self, n: int) -> bool:
        s = 0
        p = 1
        temp = n

        while n > 0:
            digit = n % 10

            s += digit
            p *= digit

            n //= 10

        return temp%(p+s)==0
