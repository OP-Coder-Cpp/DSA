//The Best Optimal Solution
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        vector<int> freq(3, 0);
        int left = 0;
        int ans = 0;

        for (int right = 0; right < n; right++) {

            freq[s[right] - 'a']++;

            while (freq[0] > 0 && freq[1] > 0 && freq[2] > 0) {

                ans += (n - right);

                freq[s[left] - 'a']--;
                left++;
            }
        }

        return ans;
    }
};



//This Solution is of TC:O(nlogn)
//Accepted
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        // Prefix frequency array
        vector<vector<int>> pref(n + 1, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            pref[i + 1][s[i] - 'a']++;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            int low = i + 2;
            int high = n - 1;
            int first = -1;

            while (low <= high) {
                int mid = low + (high - low) / 2;

                int a = pref[mid + 1][0] - pref[i][0];
                int b = pref[mid + 1][1] - pref[i][1];
                int c = pref[mid + 1][2] - pref[i][2];

                if (a > 0 && b > 0 && c > 0) {
                    first = mid;
                    high = mid - 1;
                } else {
                    low = mid + 1;
                }
            }

            if (first != -1)
                ans += (n - first);
        }

        return ans;
    }
}; 





//This Solution is of O(N^2) TC
//Gave TLE
class Solution {
public:
    int numberOfSubstrings(string s) {
        int n = s.size();

        // Prefix frequency array
        vector<vector<int>> pref(n + 1, vector<int>(3, 0));

        for (int i = 0; i < n; i++) {
            pref[i + 1] = pref[i];
            pref[i + 1][s[i] - 'a']++;
        }

        int ans = 0;

        for (int i = 0; i < n; i++) {

            for (int j = i + 2; j < n; j++) {

                int a = pref[j + 1][0] - pref[i][0];
                int b = pref[j + 1][1] - pref[i][1];
                int c = pref[j + 1][2] - pref[i][2];

                if (a > 0 && b > 0 && c > 0) {
                    ans += (n - j);
                    break;          // all larger j are also valid
                }
            }
        }

        return ans;
    }
};