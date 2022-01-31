// { Driver Code Starts
//Initial template for C++
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
//User function template in C++

class Solution
{
    public:
    //Function to find total number of unique paths.
    int NumberOfPath(int m, int n)
    {
        //code here
        unordered_map<string,int> memo = {};
        return solve(m,n,1,1,memo);
    }
    
    int solve(int m,int n, int currX, int currY, unordered_map<string,int>&memo) {
        
        if(currX == m && currY == n) return 1;
        else if(currX > m || currY > n) return 0;
        
        string currentKey = to_string(currX) + ";" + to_string(currY);
        if(memo.find(currentKey) != memo.end()) return memo[currentKey];
        
        int down = 0;
        int right = 0;
        if(currX <= m && currY <= n) {
            down = solve(m,n,currX + 1,currY,memo);
            right = solve(m,n,currX,currY + 1,memo);
        }
        return memo[currentKey] = down + right;
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
        //taking dimensions of the matrix
        int a,b;
        cin>>a>>b;
        Solution ob;
        //calling NumberOfPath() function
        cout << ob.NumberOfPath(a,b) << endl;
    }
}

  // } Driver Code Ends