class Solution:
    def poorPigs(self, buckets: int, minutesToDie: int, minutesToTest: int) -> int:
        cycle = minutesToTest // minutesToDie + 1
        pigs = 0
        while(cycle)**pigs < buckets:
            pigs+=1
            
        return pigs
