class Solution {
public:
    
    void go(vector<vector<int>> &ans,vector<int> v,int k,int n,int lst){
        if(k==0 && n==0){
            ans.push_back(v);
            return;
        }
        if(k==0)
            return;
    
        for(int i=lst+1;i<=9;i++){
            v.push_back(i);
            go(ans,v,k-1,n-i,i);
            v.pop_back(); 
        }
        
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        go(ans,v,k,n,0);
        return ans;
    }
};