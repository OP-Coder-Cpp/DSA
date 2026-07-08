class Solution {
public:
    static const int MOD = 1e9 + 7;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.size();

        vector<long long> prefSum(n + 1, 0);
        vector<long long> prefNum(n + 1, 0);
        vector<int> prefCnt(n + 1, 0);

        //precomputing the power of 10
        vector<long long> pow10(n + 1, 1);
        for (int i = 1; i <= n; i++)
            pow10[i] = (pow10[i - 1] * 10) % MOD; 

        for (int i = 0; i < n; i++) {
            prefSum[i + 1] = prefSum[i];
            prefNum[i + 1] = prefNum[i];
            prefCnt[i + 1] = prefCnt[i];

            if (s[i] != '0') {
                int d = s[i] - '0';

                prefSum[i + 1] += d;
                prefCnt[i + 1]++;

                prefNum[i + 1] = (prefNum[i] * 10 + d) % MOD;
            }
        }
        vector<int> ans;

        for (auto &q : queries) {
            int l = q[0];
            int r = q[1];

            long long sumDigits = prefSum[r + 1] - prefSum[l];

            int cntDigits = prefCnt[r + 1] - prefCnt[l];

            long long number =
                (prefNum[r + 1] -
                 prefNum[l] * pow10[cntDigits] % MOD +
                 MOD) % MOD;

            ans.push_back((number * sumDigits) % MOD);
        }

        return ans;   
    }
};