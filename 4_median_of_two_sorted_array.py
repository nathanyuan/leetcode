class Solution(object):
    def findMedianSortedArrays(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: float
        """
        m = len(nums1)
        n = len(nums2)
        length = m + n
        if length == 0:
            return
        i = 0
        j = 0
        count = 0
        mid1 = 0
        mid2 = 0
        while count < length / 2:
            count += 1
            if i == m:
                mid1 = nums2[j]
                j += 1
                continue
            if j == n:
                mid1 = nums1[i]
                i += 1
                continue
            if nums1[i] > nums2[j]:
                mid1 = nums2[j]
                j += 1
            else:
                mid1 = nums1[i]
                i += 1
           
        if i == m:
            mid2 = nums2[j] 
        elif j == n:
            mid2 = nums1[i]
        elif nums1[i] > nums2[j]:
            mid2 = nums2[j]
        else:
            mid2 = nums1[i]
        if length % 2 == 0:
            mid = (mid1 + mid2) / 2.0
        else:
            mid = mid2
        return mid

s = Solution()
print s.findMedianSortedArrays([], [])
