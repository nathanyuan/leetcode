class Solution(object):
    def divide(self, dividend, divisor):
        """
        :type dividend: int
        :type divisor: int
        :rtype: int
        """
        if dividend < 0 and divisor < 0:
            negative = False 
            dividend = 0 - dividend
            divisor = 0 - divisor
        elif dividend > 0 and divisor < 0:
            negative = True 
            divisor = 0 - divisor
        elif dividend < 0 and divisor > 0:
            negative = True
            dividend = 0 - dividend
        else:
            negative = False
        result = 0
        while True:
            if (dividend - divisor) > 0:
                result += 1
                dividend -= divisor
            elif (dividend - divisor) == 0:
                result += 1
                break
            else:
                break
        if negative:
            return 0 - result
        return result

s = Solution()
print s.divide(-1, -1)
