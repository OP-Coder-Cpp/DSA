class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {

        sort(intervals.begin(), intervals.end(),
            [](const vector<int>& a, const vector<int>& b) {
                if (a[0] == b[0])
                    return a[1] > b[1];   // Descending end
                return a[0] < b[0];       // Ascending start
            });

        int ans = 0;
        int lastMaxEnd = 0;

        for (auto &interval : intervals) {
            if (interval[1] > lastMaxEnd) {
                ans++;
                lastMaxEnd = interval[1];
            }
            // else: interval is covered
        }

        return ans;
    }
};