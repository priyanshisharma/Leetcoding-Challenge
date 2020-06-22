//This is also a difficult question for me and I did take external help and this isn't purely my solution, while I did share a similar intuition and looked for a similar approach with greaterr attention to detail, in order to get this done in time.
class Solution {
public:
    string getPermutation(int n, int k) {
        
        //numSet contains all possible values from 1 to n that we would reference later
        vector<int> numSet(n);
        for(int i=0;i<n;i++)
            numSet[i]=i+1;
        
        //fact contains all possible factorials from 0 to 9 that we would reference later
        int fact[10] = {1};
        for(int i=1;i<=9;i++)
            fact[i] = fact[i-1]*(i);
        
        
        int index;  //index refers to the index of appropriate number from numSet.
        int result=0;
        
        while(n&&k)
        {
            index = ceil((double)k/fact[n-1]);
            // get index of first pos element
            result = (result*10)+numSet[index-1];
            //Add it to result
            numSet.erase(numSet.begin()+(index-1));
            //erase as numbers do not get reapeated
            k = k%(fact[n-1]);
            //updated k and n for subsequent number
            n = n-1;
        }
        
        if(k==0) //to enter leftover numbers however many
        {
            int t=numSet.size();
            for(int i=t-1;i>=0;i--)
                result = (result*10)+numSet[i];       
        }
        
        string st = to_string(result);
        
        return st;
    }
};
