class Solution(object):
    def isPalindrome(self, x):
        """
        :type x: int
        :rtype: bool
        """
        if x < 0 or (x >= 10 and x%10 == 0):
            return False
        r = 0
        while x > r:
            r = 10 * r + x % 10
            x = x / 10
        return (x == r or x == r / 10)
