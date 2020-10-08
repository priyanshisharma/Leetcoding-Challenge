class Solution {
public:
    int minFlips(string target) {
        int n=target.size();
        string s="";
        for(int i=0;i<n;i++){
            s.push_back('0');
        }
        char cs='0';
        int count = 0;
        for(int i=0;i<n;i++)
        {
            if(target[i]==cs)
            {
                continue;
            }
            else
            {
                count++;
                if(target[i]=='1')
                {
                    cs='1';
                }
                else if(target[i]=='0')
                {
                    cs='0';
                }
            }
        }
        return count;
    }
};
