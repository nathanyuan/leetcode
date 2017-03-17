class Solution(object):
    def convert(self, s, numRows):
        """
        :type s: str
        :type numRows: int
        :rtype: str
        """

        rows = []
        for l in range(numRows):
            rows.append("")
        r = 0
        for i in range(len(s)):
            if r == (numRows - 1):
                direction = -1
            if r == 0:
                direction = 1
            rows[r] += s[i]
            r = r + direction
        res = ""
        for s2 in rows:
            res += s2 
        return res
            
