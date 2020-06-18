class Solution {
public:
    int hIndex(vector<int>& citations) {
        
        if(citations.size()==0) 
            return 0;
        
        int beg = 0, end = citations.size()-1, mid;
        
        while(beg<=end)
        {
            mid = (beg+end)/2;
            
            if(citations[mid]==citations.size()-mid)
                return citations.size()-mid;
            else if(citations[mid]<citations.size()-mid)
                beg = mid+1;
            else
                end = mid-1;
        }
        return citations.size()-beg;
    }
};
