class Solution {

public:
    bool isVowel(char ch)
    {
        ch = tolower(ch);
      
        if(ch =='a' || ch =='e' || ch =='i' || ch =='o' || ch =='u')
            return true;

        return false;
    }
    string toGoatLatin(string S) {
        
        stringstream ss(S);
        string temp, suff="maa", res = "";
        
        while(!ss.eof())
        {
            ss >> temp;
            if(!isVowel(temp[0]))
            {
                char ch = temp[0];
                temp.erase(temp.begin());
                temp.push_back(ch);
            }
            temp += suff;
            suff.push_back('a');
            res += (temp + ' ');
        }
        res.pop_back();
     
        return res;
    }
};
