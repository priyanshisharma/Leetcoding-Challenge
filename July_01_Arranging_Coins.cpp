class Solution {
public:
    int arrangeCoins(int n) {
    
        int beg=0,end=n,mid=(n/2),res;
        long long sum;
        while(beg<=end)
        {
            int mid = (beg+end)/2;
            sum = ((long long) mid*(mid+1)/2);
            if(sum<=n)
            {
                beg=mid+1;
                res = mid;
            }
            else
            {
                end = mid-1;
            }
        };
        
        return res;
        
    }
};
