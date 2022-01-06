// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int CountWays(string str){
		    // Code here
		    int dp[10001];
		    memset(dp,-1,sizeof(dp));
		    return solve(0,str,dp)%(1000000007);
		}
		
		int solve(int i, string&str, int*dp){
		    
		    if(i >= str.size()) return 1;
		    if(dp[i] != -1) return dp[i];
		    int ans = 0;
		    int count1 = str[i] - '0',count2 = 0;
		    if(i < str.size() - 1)
		        count2 = count1*10 + str[i+1] - '0';
		       
		    if(count1 > 0) ans += solve(i + 1,str,dp)%(1000000007);
		    if(count1 > 0 && count2 > 0 && count2 <= 26) ans += solve(i + 2,str,dp)%(1000000007);
		    return dp[i] = ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string str;
		cin >> str;
		Solution obj;
		int ans = obj.CountWays(str);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends