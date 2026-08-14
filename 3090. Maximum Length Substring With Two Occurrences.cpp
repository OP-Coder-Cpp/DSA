class Solution {
public:
    int maximumLengthSubstring(string s) {
        int left=0;
        int ans=0;
        vector<int> map(26,0);
        for(int right=0;right<s.size();right++)
        {
            char ch=s[right];
            int pos=ch-'a';

            map[pos]++;

            while(map[pos]>2){
                map[s[left]-'a']--;
                left++;
            }    
            ans=max(ans,right-left+1);
        }
        return ans;
    }
};