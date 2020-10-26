class Solution:
    def findRepeatedDnaSequences(self, s: str) -> List[str]:
        #counter for all the strings
        count = collections.Counter()
        current_string = ""
        for char in s:
            current_string+=char
            #if length exceeds 10
            if len(current_string) > 10:
                current_string = current_string[1:]
            #if length equals 10    
            if len(current_string) == 10:
                count[current_string]+=1      
                
        #return all the keys whose value is greater than 2        
        return [key for key,value in count.items() if value>=2]
