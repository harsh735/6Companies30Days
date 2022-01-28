// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    int solve(vector<int>v){
  
        vector<int>ans;
        for(int i=0; i<v.size(); i++){
            auto it = lower_bound(ans.begin(),ans.end(),v[i]);
            if(it == ans.end())
                ans.push_back(v[i]);
            else{
                *it = v[i];
            }
        }
        return ans.size();
    }
    int minInsAndDel(int A[], int B[], int N, int M) {
        // code here
        unordered_map<int,int>memo;
        for(int i=0; i<M; i++){
            memo[B[i]]++;
        }
        vector<int>v;
        for(int i=0; i<N; i++){
            if(memo.find(A[i]) != memo.end())
                v.push_back(A[i]);
        }
        return (N + M) - 2 * solve(v);
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,M;
        cin>>N>>M;
        
        int A[N], B[M];
        for(int i=0; i<N; i++)
            cin>>A[i];
        for(int i=0; i<M; i++)
            cin>>B[i];

        Solution ob;
        cout << ob.minInsAndDel(A,B,N,M) << endl;
    }
    return 0;
}  // } Driver Code Ends