class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        map<int,int>m;
        m[0]=-1;
        int c=0;
        int maximum=0;
        for(int i=0;i<nums.size();i++) {
            if(nums[i]==0)
                c++;
            else
                c--;
            if(m.find(c)!=m.end())
                maximum=max(maximum,i-m[c]);
            else
                m[c]=i;
        }
        return maximum;
    }
};