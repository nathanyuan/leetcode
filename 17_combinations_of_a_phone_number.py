class Solution(object):
    def letterCombinations(self, digits):
        """
        :type digits: str
        :rtype: List[str]
        """
        p2l = {"0":[], "1":[], 
               "2":["a", "b", "c"], 
               "3":["d", "e", "f"], 
               "4":["g", "h", "i"],
               "5":["j", "k", "l"], 
               "6":["m", "n", "o"], 
               "7":["p", "q", "r", "s"], 
               "8":["t", "u", "v"], 
               "9":["w", "x", "y", "z"],}
        res = [] if digits == "" else p2l[digits[0]][:]
        for d in digits[1:]:
            tmp = []
            letters = p2l[d]
            if letters == []:
                continue
            for r in res:
                for c in letters:
                    tmp.append(r + c)
            res = tmp
        return res
