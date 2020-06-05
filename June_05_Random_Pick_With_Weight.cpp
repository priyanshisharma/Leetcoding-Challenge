class Solution {
public:
     
    vector<int> v;
    int sum = 0;
   
    Solution(vector<int>& w) {
         
        sum=0;
        for(int i=0; i<w.size(); i++)
        {
            sum+=w[i];
            v.push_back(sum);
        }
    }
    
    int pickIndex() {
       
        int index=rand()%sum;
        return binaryindex(v,0,v.size()-1,index);
    }

    int binaryindex(vector<int>& v, int beg, int end, int target)
    {
        if(beg==end) 
            return beg;
        
        int mid=(end+beg)/2;
        while(beg<=end)
        {
            if(beg==end) 
                return beg;
            
            mid=(end+beg)/2;
            
            if(v[mid]==target) 
                break;
            else if(v[mid]<target) 
                beg = mid+1;
            else 
                end = mid;
            
        }
        return mid+1;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */
