// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{

  public:
	int minDifference(int arr[], int n)  { 
	    // Your code goes here
	    int sumTotal = 0;
	    unordered_map<string,int> memo = {};
	    for(int i = 0; i<n; i++) sumTotal += arr[i];
	    return solve(arr,n-1,0,0,memo);
	} 
	
	int solve(int arr[], int i, int s1, int s2 ,unordered_map<string,int>&memo){
	    
	    if (i < 0)
            return abs(s1 - s2);
            
        string key = to_string(i) + "|" + to_string(s1);
        if(memo.find(key) != memo.end())
            return memo[key];
            
        int consider = solve(arr,i - 1,s1 + arr[i],s2,memo);
        int notConsider = solve(arr,i - 1, s1,s2 + arr[i],memo);
        
        return memo[key] = min(consider,notConsider);
	}
};


// { Driver Code Starts.
int main() 
{
   
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

        int a[n];
        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minDifference(a, n) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends