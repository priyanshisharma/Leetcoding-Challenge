class Solution:
    def findPairs(self, nums: List[int], k: int) -> int:
        if k==0:
            d = dict()
            for i in nums:
                if i not in d:
                    d[i]=1
                else:
                    d[i] += 1
            ans = 0
            for i in d:
                if d[i]>1:
                    ans+=1
            return ans        
        s = set(nums)
        ans = 0
        final = set()
        for i in nums:
            if i+k in s and i not in final:
                ans+=1
                final.add(i)
        return ans    
