class Solution {
public:
    void dfs(int node,
             vector<vector<int>>& adj,
             vector<bool>& vis,
             vector<int>& component) {

        vis[node] = true;
        component.push_back(node);

        for (int nei : adj[node]) {
            if (!vis[nei]) {
                dfs(nei, adj, vis, component);
            }
        }
    }
    
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        vector<int> degree(n,0);

        for(auto &edge:edges)
        {
            int u=edge[0];
            int v=edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);

            degree[u]++;
            degree[v]++;
        }

        vector<bool> vis(n,false);
        int ans=0;

        for(int i=0;i<n;i++)
        {
            if(vis[i])
                continue;
            
            vector<int> component;
            dfs(i,adj,vis,component);

            int sz = component.size();

            bool complete = true;

            for (int node : component) {
                if (degree[node] != sz - 1) {
                    complete = false;
                    break;
                }
            }

            if (complete)
                ans++;
        }
        return ans;
    }
};