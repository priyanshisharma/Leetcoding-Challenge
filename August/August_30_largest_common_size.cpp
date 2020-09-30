#include <bits/stdc++.h> 
using namespace std; 
   
int dfs(int u, vector<int>* adj, int vis[]) 
{  
    vis[u] = 1; 
    int cSize = 1; 
       for (auto it : adj[u]) { 
        if (!vis[it]) { 
            cSize += dfs(it, adj, vis); 
        } 
    } 
    return cSize; 
} 
   
int max_Component_Size(int a[], int n) 
{ 
    vector<int> adj[n]; 
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { 
            if (__gcd(a[i], a[j]) > 1) 
                adj[i].push_back(j); 
            adj[j].push_back(i); 
        } 
    } 
    int answer = 0;  
    int vis[n]; 
    for(int k=0;k<n;k++){ 
      vis[k]=0; 
    } 
    for (int i = 0; i < n; i++) { 
        if (!vis[i]) { 
            answer = max(answer, dfs(i, adj, vis)); 
        } 
    } 
    return answer; 
} 

int main() 
{ 
    int n; 
    int arr[100000];
    cin>>n;
    for (int i = 0; i < n; ++i)
     {
         cin>>arr[i];
     } 
    cout << max_Component_Size(arr, n); 
    return 0; 
} 