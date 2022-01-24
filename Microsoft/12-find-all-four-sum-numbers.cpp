// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// User function template for C++

class Solution{
    public:
    // arr[] : int input array of integers
    // k : the quadruple sum required
    vector<vector<int> > fourSum(vector<int> &arr, int k) {
        // Your code goes here
        int n = arr.size();
        sort(arr.begin(), arr.end());
        set<vector<int>> sv;
        int target = k;
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
    
                for(int k=j+1;k<n;k++)
                { 
                  
                   int x = (long long)target - 
                           (long long)arr[i]-
                           (long long)arr[j]-(long long)arr[k];
                   
                        if(binary_search(arr.begin()+k+1,arr.end(),x)){
                            vector<int> v;
                            v.push_back(arr[i]);
                            v.push_back(arr[j]);
                            v.push_back(arr[k]);
                            v.push_back(x);
                            sort(v.begin(),v.end());
                            sv.insert(v);
                        }
                }
            }
        }
        vector<vector<int>> res(sv.begin(),sv.end());
        return res;
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, k, i;
        cin >> n >> k;
        vector<int> a(n);
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        vector<vector<int> > ans = ob.fourSum(a, k);
        for (auto &v : ans) {
            for (int &u : v) {
                cout << u << " ";
            }
            cout << "$";
        }
        if (ans.empty()) {
            cout << -1;
        }
        cout << "\n";
    }
    return 0;
}  // } Driver Code Ends