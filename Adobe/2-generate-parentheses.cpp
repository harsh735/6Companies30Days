// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
vector<string> AllParenthesis(int n) ;


 // } Driver Code Ends
//User function Template for C++

// N is the number of pairs of parentheses
// Return list of all combinations of balanced parantheses
class Solution
{
    public:
    
    vector<string> AllParenthesis(int n) 
    {
        // Your code goes here 
        int open=n;
        int close=n;
        vector<string> ans;
        string temp="";
        solve(n,ans,open,close,temp);
        return ans;
    }
    
    void solve(int n , vector<string>&ans, int open, int close, string&temp){
        
        if(close == 0 && open == 0){
            ans.push_back(temp);
            return;
        }
        if(open!= 0){
            string t1 = temp + '(';
            solve(n,ans,open-1,close,t1);
        }
        if(close > open){
            string t2 = temp + ')';
            solve(n,ans,open,close -1,t2);
        }
    }
    
};

// { Driver Code Starts.


int main() 
{ 
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		Solution ob;
		vector<string> result = ob.AllParenthesis(n); 
		sort(result.begin(),result.end());
		for (int i = 0; i < result.size(); ++i)
			cout<<result[i]<<"\n";
	}
	return 0; 
} 
  // } Driver Code Ends