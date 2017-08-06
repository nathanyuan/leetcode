class Solution(object):
    def plusOne(self, digits):
        """
        :type digits: List[int]
        :rtype: List[int]
        """
        return [int(c) for c in str(int(str.join("", [str(c) for c in digits]))+1)]


s = Solution()
print s.plusOne([1,2,3,4,5])
