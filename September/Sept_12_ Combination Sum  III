class Solution {
public:
      vector<int> num = {1,2,3,4,5,6,7,8,9};
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr;
        vector<vector<int>> sol;
          if(k == 0 || n == 0) return  sol;
        temp(sol, curr, n-1, k, n, 0);
        return sol;
    }
    
    void temp(vector<vector<int>>& sol, vector<int>& curr, int m, int k, int target, int idx ){
        if(target==0&&curr.size()==k){
            sol.push_back(curr);
            return;
        }
         else if(target<0||idx>=num.size()||curr.size()>k)
        {
            return;
        }
        
        for(int i=idx;i<num.size();i++){
            
            if(target-num[i]>=0)
            {  curr.push_back(num[i]);
               temp(sol,curr,m,k,target-num[i],i+1);
             curr.pop_back();
            }
            
        }
    }
};
