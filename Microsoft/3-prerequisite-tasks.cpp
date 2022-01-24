// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:

    bool isCyclic(vector<vector<int>>& adj, vector<int>& visited,int curr){
        if(visited[curr]==2)
            return true;
        
        visited[curr] = 2;
        for(int i=0;i<adj[curr].size();++i)
            if(visited[adj[curr][i]]!=1)
                if(isCyclic(adj,visited,adj[curr][i]))
                    return true;
        
        visited[curr] = 1;
        return false;
    }


	bool isPossible(int N, vector<pair<int, int>>& prerequisites) {
	    // Code here
	    vector<vector<int>> adj(N);
        for(int i=0;i<prerequisites.size();++i)
            adj[prerequisites[i].first].push_back(prerequisites[i].second);
        
        vector<int> visited(N,0);
        for(int i = 0; i < N; i++)
            if(visited[i] == 0)
                if(isCyclic(adj,visited,i))
                    return false;
        return true;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}  // } Driver Code Ends