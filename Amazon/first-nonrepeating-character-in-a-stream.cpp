// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		string FirstNonRepeating(string A){
		    // Code here
		    
		    queue<char> q;
		    vector<int> res(26,0);
		    string ans = "";
		    for(char it: A){
		        q.push(it);
		        res[it - 'a']++;
		        while(!q.empty() && res[q.front() - 'a'] > 1) q.pop();
		        if(!q.empty()) ans += q.front();
		        else ans += "#";
		    }
		    return ans;
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		string A;
		cin >> A;
		Solution obj;
		string ans = obj.FirstNonRepeating(A);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends