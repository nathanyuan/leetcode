class Solution(object):
    def convertToBase7(self, num):
        """
        :type num: int
        :rtype: str
        """
        if num == 0:
            return "0"
        tab = [1, 7, 49, 343, 2401, 16807, 117649, 823543, 5764801, 10000001]
        
        if num > 0:
            neg = False
        else:
            neg = True
        num = abs(num)
        i = 0
        while i < len(tab):
            if num < tab[i]:
                break;
            i += 1
        res = ""
        for j in range(i-1, -1, -1):
            res += str(num / tab[j])
            num %= tab[j]
        if neg:
            res = "-" + res
        return res

print Solution().convertToBase7(5000000)
