class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> score(n, vector<int>(m, -1));

        int startLife = health - grid[0][0];
        if (startLife < 1)
            return false;

        score[0][0] = startLife;

        queue<pair<int, pair<int, int>>> q;
        q.push({startLife, {0, 0}});

        int dx[4] = {0, 0, 1, -1};
        int dy[4] = {1, -1, 0, 0};

        while (!q.empty()) {
            int life = q.front().first;
            int x = q.front().second.first;
            int y = q.front().second.second;
            q.pop();

            if (x == n - 1 && y == m - 1)
                return true;

            for (int i = 0; i < 4; i++) {
                int newX = x + dx[i];
                int newY = y + dy[i];

                if (newX >= 0 && newX < n &&
                    newY >= 0 && newY < m) {

                    int newLife = life - grid[newX][newY];

                    if (newLife >= 1 && score[newX][newY] < newLife) {
                        score[newX][newY] = newLife;
                        q.push({newLife, {newX, newY}});
                    }
                }
            }
        }

        return false;
    }
};