class Solution {
public:
    bool checkValidString(string s) {
        
         int mini = 0, maxi = 0;
        for (char check : s)
         {
            if (check=='(') 

            {
                mini++;
                maxi++;
            } 

            else if (check==')')
             {
                mini--;               
                maxi--;
            } else
             { 
                mini--;
                maxi++;
            }
            mini = max(mini, 0);
            if (maxi<0)
                return false;
        }
        return mini==0;
        
    }
};