class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        d = {}
        for i in range(len(nums)):
            x = target - nums[i]
            if x in d:
                return [d[x], i]
            d[nums[i]] = i

