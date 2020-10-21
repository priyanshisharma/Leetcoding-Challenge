// https://leetcode.com/explore/challenge/card/october-leetcoding-challenge/561/week-3-october-15th-october-21st/3500/

class Solution {
public:
    
    int check(vector<int> &v1,vector<int> &v2, int key){
        int count =0;
        for(int i=0;i<v1.size();i++){
            if(v1[i]!=key && v2[i]!=key)
                return -1;
            else if(v1[i]!=key&&v2[i]==key)
                count++;
        }
        return count;
    }
    
    int minDominoRotations(vector<int>& A, vector<int>& B) {
        int arr1[7] = {0};
        int arr2[7] = {0};
        int max1 = INT_MIN;
        int max2 = INT_MIN;
        for(int i=0;i<A.size();i++){
            arr1[A[i]]++;
            arr2[B[i]]++;
            max1 = max(max1,arr1[A[i]]);
            max2 = max(max2,arr2[B[i]]);
        }
        int a=0, b=0;
        for(int i=1;i<=6;i++){
            if(arr1[i] == max1)
                a= i;
            if(arr2[i] == max2)
                b=i;
        }
        return (max1>=max2)? check(A,B,a) : check(B,A,b);  
    }
};
