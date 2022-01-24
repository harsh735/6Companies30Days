// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    int equalPartition(int N, int arr[])
    {
        // code here
        map<pair<int,int>,int> memo = {};
        int sum = 0;
        for(int i = 0; i<N; i++) sum += arr[i];
        if(sum % 2 != 0) return 0;
        
        return solve(N,arr,0,sum/2,memo);
    }
    
    int solve(int N, int arr[], int currIdx, int target, map<pair<int,int>,int>&memo){
        
        if(currIdx >= N && target != 0) return 0;
        else if(currIdx >= N && target == 0) return 1;
        pair<int,int> currentKey(currIdx,target);
        if(memo.find(currentKey) != memo.end()) return memo[currentKey];
        
        int consider = 0;
        if(target >= arr[currIdx]){
            consider = solve(N,arr,currIdx + 1,target - arr[currIdx],memo);
        }
        if(consider) return 1;
        elseint notConsider = solve(N,arr,currIdx + 1,target,memo);
        
        return memo[currentKey] = consider || notConsider;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends