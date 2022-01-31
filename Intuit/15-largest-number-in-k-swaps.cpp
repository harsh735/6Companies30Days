// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the largest number after k swaps.
    
    void solve(string str, int k,string& ans,int idx){
       
        if(k == 0) return;
    
        int n=str.length();
        char maxc = str[idx];
        
        for(int i= idx+1; i<n; i++){
            if(maxc < str[i]){
                maxc = str[i];
            }
        }
        
        if(maxc != str[idx])
            k--;
        
        for(int i = idx; i<n; i++){
            if(str[i] == maxc){
                swap(str[i],str[idx]);
                if(str.compare(ans) > 0)
                    ans = str;
                    
                solve(str, k,ans,idx+1);
                swap(str[i],str[idx]);
            }

        }
    }
    
    
    string findMaximumNum(string str, int k)
    {
       // code here.
       string ans = str;
       solve(str,k,ans,0);
       return ans;
    }
};

// { Driver Code Starts.

int main()
{
    int t, k;
    string str;

    cin >> t;
    while (t--)
    {
        cin >> k >> str;
        Solution ob;
        cout<< ob.findMaximumNum(str, k) << endl;
    }
    return 0;
}
  // } Driver Code Ends