class Solution(object):
    def removeDuplicates(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) <= 1:
            return len(nums)
        i = 0
        j = 1
        while j < len(nums):
            if nums[i] == nums[j]:
                j += 1
            else:
                i += 1
                nums[i] = nums[j]
                j += 1
        return i + 1

if __name__ == "__main__":
    nums = [1,1,2,2,3,4,4,5,8,8,9]
    s = Solution()
    print s.removeDuplicates(nums)
    print nums
