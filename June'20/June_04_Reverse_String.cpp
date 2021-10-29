class Solution {
public:
    void reverseString(vector<char>& s) {
        if(s.size() ==0 || s.size() == 1)
            return;
        int beg =0, end = s.size()-1;
        char temp;
        while(end>beg)
        {
            temp = s[beg];
            s[beg]= s[end];
            s[end] = temp;
            beg++;
            end--;
        }
    }
};
