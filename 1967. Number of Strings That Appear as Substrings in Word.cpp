class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        int ans = 0;

        for(int i = 0; i < patterns.size(); i++)
        {
            int len = patterns[i].size();

            for(int j = 0; j < word.size(); j++)
            {
                if(word[j] == patterns[i][0])
                {
                    if(word.substr(j, len) == patterns[i])
                    {
                        ans++;
                        break;
                    }
                }
            }
        }

        return ans;
    }
};