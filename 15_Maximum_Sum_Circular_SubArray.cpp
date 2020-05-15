// Well, I definitely feel this isn't the best solution and could be a lot better. I just invoked my knowledge of Kadane's
// algorithm and thought this out, ofcourse the failed test cases helped too. I think this needs improvisations but I think I got 
// a little off schedule today, wrt the leetcoding challenge, So this is my approach. I'm hopeful to improvise it later.
// Suggestions are welcomed too!

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& A) {
        

        int n = A.size();
        int local_min = A[0], sum = 0;
        int global_min = INT_MAX;
        bool neg=false, pos = false;
        
        for(int i=0;i<A.size();i++)
        {
            local_min = local_min>A[i]?local_min:A[i];
        }
        
        
        for(int i=0;i<n;i++)
        {
            local_min = min(A[i],A[i]+local_min);
            sum+=A[i];
            if(local_min < global_min)
                global_min = local_min;
            
            if(A[i]>0)
                pos = true;
            
            if(A[i]<0)
                neg = true;
        }
        
        int local_max = A[0];
        int global_max = INT_MIN;
        
        for(int i=0;i<A.size();i++)
        {
            local_max = local_max<A[i]?local_max:A[i];
        }

        for(int i=0 ; i<n; ++i)
	    {
	        local_max = local_max+A[i]>A[i]?local_max+A[i]:A[i];
	        global_max=local_max>global_max?local_max:global_max;
	    }
        
        if(!neg)
            return sum;

        if(pos)
            sum =sum - global_min > sum ?sum - global_min:sum;
        else
            sum = global_min - sum;
            
        sum = sum>global_max?sum:global_max;
        
        return sum;
        
    }
};
