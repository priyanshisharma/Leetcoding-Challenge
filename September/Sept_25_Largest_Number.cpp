int myCompare(string X, string Y)
{
    string XY = X.append(Y);
    string YX = Y.append(X);
    return XY.compare(YX) > 0 ? 1: 0;
}
class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string> b;
    for(int i=0;i<nums.size();i++){
        b.push_back(to_string(nums[i]));
    }
    sort(b.begin(),b.end(),myCompare);
    string ans="";
    for(int i=0;i<b.size();i++){
     ans+=b[i];
    }
    int i=0;
    while(ans[i]=='0'){
        i++;
    }
    if(i==ans.length())
     ans="0";
    return ans;
    }
};