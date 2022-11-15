class Solution:
    import math
    def maxArea(self, h: List[int]) -> int:
        i = 0
        j = len(h) - 1
        res = 0
        while i < j:
            res = max(res, (j - i) * min(h[i], h[j]))
            if h[i]<h[j]:
                i += 1
            else:
                j -= 1
        return res
                      
