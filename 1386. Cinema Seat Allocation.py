from typing import List
class Solution:
    def maxNumberOfFamilies(self, n: int, reservedSeats: list[list[int]]) -> int:

        block = [False, False, False]

        reservedSeats.sort()

        ans = 0
        row = 1

        for i in range(len(reservedSeats)):

            currRow = reservedSeats[i][0]
            seat = reservedSeats[i][1]

            if currRow != row:

                if not block[0] and not block[2]:
                    ans += 2
                elif not block[0] or not block[1] or not block[2]:
                    ans += 1

                ans += (currRow - row - 1) * 2

                row = currRow

                block = [False, False, False]

            if seat == 2 or seat == 3:
                block[0] = True

            elif seat == 4 or seat == 5:
                block[0] = True
                block[1] = True

            elif seat == 6 or seat == 7:
                block[1] = True
                block[2] = True

            elif seat == 8 or seat == 9:
                block[2] = True

        # Process the final row
        if not block[0] and not block[2]:
            ans += 2
        elif not block[0] or not block[1] or not block[2]:
            ans += 1

        # Completely empty rows after the final reserved row
        ans += (n - row) * 2

        return ans