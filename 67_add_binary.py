class Solution(object):
    def addBinary(self, a, b):
        res = ""
        extra = False
        (m, n) = (len(a)-1, len(b)-1)
        while m >= 0 or n >= 0:
            if m < 0:
                num1 = '0'
                num2 = b[n]
            elif n < 0:
                num1 = a[m]
                num2 = '0' 
            else:
                num1 = a[m]
                num2 = b[n]
            if (num1, num2) == ('1', '1'):
                if extra:
                    res = '1' + res 
                else:
                    res = '0' + res 
                extra = True
            if (num1, num2) == ('0', '1') or (num1, num2) == ('1', '0'):
                if extra:
                    extra = True
                    res = '0' + res 
                else:
                    extra = False
                    res = '1' + res 
            if (num1, num2) == ('0', '0'):
                if extra:
                    res = '1' + res 
                else:
                    res = '0' + res 
                extra = False
            m -= 1
            n -= 1
        if extra:
            res = '1' + res
        if res[0] == '0' and len(res) > 1:
            return res[1:]
        return res
