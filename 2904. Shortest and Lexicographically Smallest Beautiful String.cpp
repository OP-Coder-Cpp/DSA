#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int count = 0;
        int mn = s.size() + 1;
        string ans = "";

        for (int i = 0; i < s.size(); i++) {

            if (s[i] == '1')
                count++;

            while (count > k) {
                if (s[left] == '1')
                    count--;
                left++;
            }

            if (count == k) {

                while (s[left] == '0')
                    left++;

                int len = i - left + 1;

                if (len < mn) {
                    mn = len;
                    ans = s.substr(left, len);
                }
                else if (len == mn) {
                    string temp = s.substr(left, len);

                    if (temp < ans)
                        ans = temp;
                }
            }
        }

        return ans;
    }
};