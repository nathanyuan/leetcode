import sys
class Solution(object):
    def countAndSay(self, n):
        res = "1"
        if n == 1:
            return res
        for n in range(1, n):
            tmp = ""
            ignore = False
            i = 0
            while i < len(res):
                j = i
                count = 0
                while j < len(res):
                    if res[j] != res[i]:
                        break;
                    count += 1
                    j += 1
                if count == 1:
                    tmp += "1{0}".format(res[i])
                else:
                    tmp += "{0}{1}".format(count, res[i])
                i += count
            res = tmp
        return res
        

if __name__ == "__main__":
    if len(sys.argv) != 2:
        exit(1);
    s = Solution()
    print s.countAndSay(int(sys.argv[1]))
