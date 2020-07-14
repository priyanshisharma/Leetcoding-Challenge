class Solution {
public:
    string frequencySort(string s) {
        
        if(s.length()<2)
            return s;
          
        int arr[256]={0};
        for(int i=0;i<s.length();i++)
        {
                arr[s[i]]++;
        }
   
        int max=0,max_pos;
        bool flag;
        string ret;
        for(int i=0;i<256;i++)
        {
            max = 0;
            flag = true;
            
            for(int j=0;j<256;j++)
            {
                if(arr[j]!=0)
                    flag = false;
                
                if(max<arr[j])
                {
                    max=arr[j];
                    max_pos = j;
                }
                
            }
            
            if(flag)
                break;
            
            while(arr[max_pos]>0)
            {
                ret.push_back(max_pos);
                arr[max_pos]--;
            }
        }
        
        return ret;
    
        
        
    }
};
