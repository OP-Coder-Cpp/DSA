class Solution {
public:
    int dist(char a,char b){
        return min(abs(a-b),26-abs(a-b));
    }
    int minOperations(string s) {
        int n=s.size();

        string temp=s;
        int ans=INT_MAX;

        for(int r=0;r<n;r++){
            int cost=r;

            for(int i=0;i<n/2;i++){
                char left=s[(i+r)%n];
                char right=s[(r+n-1-i)%n];
                cost+=dist(left,right);
            }
            ans=min(ans,cost);
        }
        return ans;
    }
};