class Solution(object):
    def isValid(self, s):
        """
        :type s: str
        :rtype: bool
        """
        heap = []
        left = ('{', '[', '(')
        right = ('}', ']', ')')

        for c in s:
            if c in left:
                heap.append(c)
            elif c in right:
                if heap == []:
                    return False
                if heap[-1] not in left:
                    return False
                if left.index(heap[-1]) != right.index(c):
                    return False
                heap.pop()
            else:
                continue
        return (heap == [])
