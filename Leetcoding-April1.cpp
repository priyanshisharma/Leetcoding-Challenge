#include<bits/stdc++.h>
using namespace std;
int main()
{
	
	int n;
	cin>>n;       //user gives value of n
	int A[n];
	int B[1000001];
	for(int i=0;i<=1000000;i++)
	B[i]=0;
	for(int i=0;i<n;i++)
	{
		cin>>A[i];                         //input n integers
		B[A[i]]++;
	}
	for(int i=0;i<=1000000;i++)
	{
		if(B[i]==1)
		{
			cout<<i;
			break;
		}
	}
	return 0;
	
}
