class Solution {
public:
    int singleNumber(vector<int>& nums) {
        
        int x;
        while(cin>>x){
            nums.push_back(x);
        }
        	int B[1000001];
	for(int i=0;i<=1000000;i++)
	B[i]=0;
	for(int i=0;i<nums.length;i++)
	{
	                        
		B[nums[i]]++;
	}
	for(int i=0;i<=1000000;i++)
	{
		if(B[i]==1)
		{
			cout<<i;
			break;
		}
	}

    }
};
