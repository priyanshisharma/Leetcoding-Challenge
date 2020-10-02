class Solution {
public:
    bool isPalindrome(string s) {
    	string r = s;
	reverse(begin(r),end(r));
	return (s==r);
    }	    
	
    bool isPalindrome(string s) {
        
       int beg=0, end=s.size()-1;
        while(beg<end)
		{
		
            if(!isalnum(s[beg]))
                beg++;
				
            if(!isalnum(s[end]))
                end--;
				
            if(isalnum(s[beg]) && isalnum(s[end]))
			{
                if(tolower(s[beg++]) != tolower(s[end--]))
                return false;
            }
        }
        return true;
    }
};
