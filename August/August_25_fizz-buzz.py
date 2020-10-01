class Solution:
    def fizzBuzz(self, n: int):
        l=[]
        for i in range(1,n+1):
            if i%3==0 and i%5==0:
                l.append("FizzBuzz")
                continue
            elif i%3==0:
                l.append("Fizz")
            elif i%5==0:
                l.append("Buzz")
            else:
                l.append(str(i))
        return l
        
