class Solution:
    def smallestSubsequence(self, s: str) -> str:
        last = [0] * 26

        # Last occurrence of every character
        for i, ch in enumerate(s):
            last[ord(ch) - ord('a')] = i

        in_stack = [False] * 26
        st = []

        for i, ch in enumerate(s):

            if in_stack[ord(ch) - ord('a')]:
                continue

            while (st and
                   st[-1] > ch and
                   last[ord(st[-1]) - ord('a')] > i):
                in_stack[ord(st[-1]) - ord('a')] = False
                st.pop()

            st.append(ch)
            in_stack[ord(ch) - ord('a')] = True

        return "".join(st)