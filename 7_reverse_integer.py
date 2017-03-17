class Solution(object):
    def reverse(self, x):
        if x < 0:
            s = str(0-x) 
            neg = True
        else:
            s = str(x)
            neg = False
        s = list(s)
        l = len(s)
        if l == 2:
            tmp = s[0]
            s[0] = s[1]
            s[1] = tmp
           
        else:
            if l % 2:
                left = l / 2 - 1
                right = l / 2 + 1
            else:
                left = l / 2 - 1
                right = l / 2
            while left >= 0:
                tmp = s[left]
                s[left] = s[right]
                s[right] = tmp
                left -= 1
                right += 1
        b = long(str.join("", s))
        if b > 2147483647:
            return 0
        b = int(b)
        if neg:
            b = 0 - b 
        return b

s = Solution()
a = s.reverse(900000)
print a
