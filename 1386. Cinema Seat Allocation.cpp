class Solution {
public:
    int maxNumberOfFamilies(int n, vector<vector<int>>& reservedSeats) {

        vector<bool> block(3, false);

        sort(reservedSeats.begin(), reservedSeats.end());

        int ans = 0;
        int row = 1;

        for (int i = 0; i < reservedSeats.size(); i++) {

            int currRow = reservedSeats[i][0];
            int seat = reservedSeats[i][1];

            
            if (currRow != row) {

                
                if (!block[0] && !block[2])
                    ans += 2;
                else if (!block[0] || !block[1] || !block[2])
                    ans += 1;

                
                ans += (currRow - row - 1) * 2;

                row = currRow;

               
                block.assign(3, false);
            }

            
            if (seat == 2 || seat == 3)
                block[0] = true;

            else if (seat == 4 || seat == 5)
                block[0] = block[1] = true;

            else if (seat == 6 || seat == 7)
                block[1] = block[2] = true;

            else if (seat == 8 || seat == 9)
                block[2] = true;
        }

        
        if (!block[0] && !block[2])
            ans += 2;
        else if (!block[0] || !block[1] || !block[2])
            ans += 1;

        
        ans += (n - row) * 2;

        return ans;
    }
};