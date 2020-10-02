#include <bits/stdc++.h>
using namespace std;
 
int main()
{
	int n,k;
	cin>>n;               //input size of the array <=20000
	int A[n];
	for(int i=0;i<n;i++)    //input the elements of the array in range [-10000,10000]
	cin>>A[i];
	              
				        //input the value of k
	cin>>k;
	
	int count=0;
	 for (int i = 0; i < n; i++) {   
            int sum = 0;
            for (int j = i; j < n; j++) {
            	
                sum += A[j];
                if (sum == k)                    //if at any moment sum is equal to k then increment count by 1
                   count++;
                   
            }
        }
        cout<<count;
}
