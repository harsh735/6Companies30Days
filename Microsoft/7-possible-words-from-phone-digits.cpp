// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
#include <string>

using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution
{
    public:
    //Function to find list of all words possible by pressing given numbers.
    void solve(int a[], int N, int currIdx, string s, vector<string>&ans, unordered_map<int, string>&memo)
    {
        if(currIdx>=N){
            ans.push_back(s);
            return;
        }
        
        string temp = memo[a[currIdx]];
        for(int i=0; i<temp.size(); i++)
            solve(a, N, currIdx+1, s+temp[i], ans, memo);
        return;
    }
    //Function to find list of all words possible by pressing given numbers.
    vector<string> possibleWords(int a[], int N){
        //Your code here
        vector<string> ans;
        unordered_map<int, string>memo;
        memo[2]="abc";
        memo[3]="def";
        memo[4]="ghi";
        memo[5]="jkl";
        memo[6]="mno";
        memo[7]="pqrs";
        memo[8]="tuv";
        memo[9]="wxyz";
        solve(a, N, 0, "", ans, memo);
        return ans;
    }
};


// { Driver Code Starts.

int main() {
  
	int T;
	
	cin >> T; //testcases
	
	while(T--){ //while testcases exist
	   int N;
	    
	   cin >> N; //input size of array
	   
	   int a[N]; //declare the array
	   
	   for(int i =0;i<N;i++){
	       cin >> a[i]; //input the elements of array that are keys to be pressed
	   }
	   
	   Solution obj;
	   
	  vector <string> res = obj.possibleWords(a,N);
	  for (string i : res) cout << i << " ";
	   cout << endl;
	}
	
	return 0;
}  // } Driver Code Ends