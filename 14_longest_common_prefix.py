class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """

        if not strs:
            return ""

        res = strs[0]
        for s in strs:
            if s.startswith(res):
                continue
            while not s.startswith(res):
                res = res[:-1]
        return res
