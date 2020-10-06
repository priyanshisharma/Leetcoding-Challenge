class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        
        int x;
        while(cin>>x)
            nums.push_back(x);
	
	int count=0;
	 for (int i = 0; i < nums.length; i++) {   
            int sum = 0;
            for (int j = i; j < n; j++) {
            	
                sum += A[j];
                if (sum == k)                   
                   count++;
            }
        }
        cout<<count;
        
        
    }
};
