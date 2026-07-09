class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> path(n,0);

        for(int i=1;i<n;i++)
        {
            int isNew=nums[i]-nums[i-1]>maxDiff;

            path[i]=path[i-1]+isNew;
        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++)
        {
            int u=queries[i][0];
            int v=queries[i][1];

            ans.push_back(path[u]==path[v]);
        }
        return ans;
    }
};