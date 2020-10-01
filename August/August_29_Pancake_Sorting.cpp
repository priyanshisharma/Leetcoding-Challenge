class Solution {
public:
        vector<int> pancakeSort(vector<int> A) 
        {
            //in a loop of number of elements in A times do the following steps:
            //find the index j of the next maximum number i
            //reverse j + 1 elements of vector so i will be at A[0]
            //then reverse i numbers, so that i will be at A[i - 1]
            
            vector<int> pancakeSorted; 
            for (int i = A.size(); i > 0; i--) 
            {
                int j = 0;
                while(A[j] != i)
                {
                    j++;
                }
                reverse(A.begin(), A.begin() + j + 1);
                pancakeSorted.push_back(j + 1);
                reverse(A.begin(), A.begin() + i); 
                pancakeSorted.push_back(i);
        }
        return pancakeSorted;
    }
};
