class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long x=0;
        long long counter=0;
        while(n>0)
        {
            int temp=n%10;
            if(temp!=0)
            {
                x=temp*pow(10,counter)+x;
                counter++;
            }
            sum+=temp;
            n/=10;
        }
        int temp=x;
        return sum*x;
    }
};