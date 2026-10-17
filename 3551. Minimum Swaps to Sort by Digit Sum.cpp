#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumDigits(int num) {
        int sum = 0;

        while (num > 0) {
            sum += num % 10;
            num /= 10;
        }

        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n = nums.size();

        // Store: {digit sum, number, original index}
        vector<tuple<int, int, int>> arr;

        for (int i = 0; i < n; i++) {
            arr.push_back({sumDigits(nums[i]), nums[i], i});
        }

        // Sort by digit sum, then by number
        sort(arr.begin(), arr.end());

        vector<bool> visited(n, false);
        int swaps = 0;

        for (int i = 0; i < n; i++) {

            // Already processed
            if (visited[i])
                continue;

            int j = i;
            int cycleSize = 0;

            // Traverse the cycle
            while (!visited[j]) {
                visited[j] = true;
                cycleSize++;

                // Original index of the element
                // that belongs at sorted position j
                j = get<2>(arr[j]);
            }

            // A cycle of size k requires k - 1 swaps
            if (cycleSize > 1) {
                swaps += cycleSize - 1;
            }
        }

        return swaps;
    }
};
