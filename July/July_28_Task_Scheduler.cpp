class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        if(n==0)
            return tasks.size();
        
        vector<int> task_amount(26, 0);
        for(int i=0; i<tasks.size();i++)
            task_amount[tasks[i]-'A']++;
        
        sort(task_amount.begin(), task_amount.end());
        
        int max_units = task_amount[25]-1;
        int idle_units = max_units*n;
        
        for(int i = 24; i >= 0; i--)
        {
            if(task_amount[i]==0)
                break;
            
            idle_units -= min(task_amount[i], max_units);
            
            if(idle_units<0)
                return tasks.size();
        }
        return tasks.size() + idle_units;
        
        
        
    }
};
