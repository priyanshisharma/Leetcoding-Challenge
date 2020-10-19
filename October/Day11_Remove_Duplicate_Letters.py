from collections import Counter
class Solution:
    def removeDuplicateLetters(self, s: str) -> str:
        freq = Counter(s)
        ans = [] # Stack
        cSet = set()
        for char in s:
            if char in cSet:
                freq[char]-=1
                continue

            while ans and char < ans[-1] and freq[ans[-1]]>0:
                cSet.remove(ans.pop())
            
            freq[char]-=1
            ans.append(char)
            cSet.add(char)
        
        return ''.join(ans)
