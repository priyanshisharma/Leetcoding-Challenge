// problem : https://leetcode.com/problems/house-robber-ii/

class Solution {
public:
    int rob(vector<int>& a) {
        int n=a.size();
        if(n==1) return a[0];
        vector<int> sum(n);
        for(int i=0;i<n-1;i++)
        {
            sum[i]=a[i];
            if(i>=2){
                sum[i]+=sum[i-2];
            }
            if(i>=3){
                sum[i]=max(sum[i],sum[i-3]+a[i]);
            }
        }
        int ans=0;
        if(n>1){
            ans=sum[n-2];
        }
        if(n>2){
            ans=max(ans,sum[n-3]);
        }
        for(int i=1;i<n;i++){
            sum[i]=a[i];
            if(i>=3){
                sum[i]+=sum[i-2];
            }
            if(i>=4){
                sum[i]=max(sum[i],sum[i-3]+a[i]);
            }
        }
        return max({ans,(n>1)?sum[n-2]:0,(n>0)?sum[n-1]:0});
    }
};