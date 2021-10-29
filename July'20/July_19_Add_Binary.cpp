class Solution {
public:
    string addBinary(string a, string b) {
        
        string res;
        int carry = 0, ptr_a = a.size()-1, ptr_b = b.size()-1;
        
        while (ptr_a>=0 || ptr_b>=0 ) 
        {
            int curr_sum = carry;
            if (ptr_a>=0) 
                curr_sum += (a[ptr_a--] - '0');
            
            if (ptr_b>=0) 
                curr_sum += (b[ptr_b--] - '0');
            
            res.insert(res.begin(), curr_sum % 2 + '0');
            carry = curr_sum / 2;
            
        }
        
        if(carry>0)
            res.insert(res.begin(), '1');
        
        return res;
    }
};
