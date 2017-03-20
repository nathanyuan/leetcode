class Solution(object):
    def longestCommonPrefix(self, strs):
        """
        :type strs: List[str]
        :rtype: str
        """
        res = "" if strs == [] else strs[0]
        for s in strs:
            while not s.startswith(res):
                res = res[:-1]
        return res
