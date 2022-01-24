// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;

 // } Driver Code Ends
class Solution
{
    public:
    //Function to find the maximum money the thief can get.
    int FindMaxSum(int arr[], int n)
    {
        // Your code here
        unordered_map<int,int> memo = {};
        return solve(arr,n,0,memo);
    }
    
    int solve(int arr[], int n, int currIdx, unordered_map<int,int>&memo){
        
        if(currIdx >= n) return 0; 
        if(memo.find(currIdx) != memo.end()) return memo[currIdx];
        
        int robbing = arr[currIdx] + solve(arr,n,currIdx+2,memo);
        int notRobbing = solve(arr,n,currIdx+1,memo);
        
        return memo[currIdx] = max(robbing,notRobbing);
    }
};

// { Driver Code Starts.
int main()
{
    //taking total testcases
	int t;
	cin>>t;
	while(t--)
	{
	    //taking number of houses
		int n;
		cin>>n;
		int a[n];
		
		//inserting money of each house in the array
		for(int i=0;i<n;++i)
			cin>>a[i];
		Solution ob;
		//calling function FindMaxSum()
		cout<<ob.FindMaxSum(a,n)<<endl;
	}
	return 0;
}
  // } Driver Code Ends