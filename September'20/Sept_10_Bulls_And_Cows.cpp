class Solution {
public:
    string getHint(string secret, string guess) {
        
        string ret;
        int num=0;
        
        //for bulls
        for(int i=0; i<secret.size()&&i<guess.size(); i++)
        {
            if(secret[i]==guess[i])
                num++;
        }
        ret.append(to_string(num));
        ret.push_back('A');
        num=0;
        
        //for cows
        vector<int> sec(10, 0);
        for(int i=0; i<secret.size(); i++)
        {
            if(i<guess.size()&&(guess[i]!=secret[i]))
                sec[secret[i]-'0']++;
        }
        
        for(int i=0; i<guess.size(); i++)
        {
            if(sec[guess[i]-'0']&&guess[i]!=secret[i])
            {
                sec[guess[i]-'0']--;
                num++;
            }
        }
        
        ret.append(to_string(num));
        ret.push_back('B');
        
        return ret;
        
    }
};
