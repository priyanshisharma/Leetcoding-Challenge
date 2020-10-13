class Solution:
    def buddyStrings(self, A: str, B: str) -> bool:

            
        lena = len(A)
        lenb = len(B)
        if lena != lenb:
            return False
        elif sorted(A) != sorted(B):
            return False
        elif A==B and len(set(A))==len(A):
            return False
        else:
            count = 0
            for i in range(lena):
                if A[i] != B[i]:
                    count += 1
                    if count == 3:
                        return False
            return True
