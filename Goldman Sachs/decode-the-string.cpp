// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
    string decodedString(string s){
        // code here
        stack<string> stringSt;
        stack<int> numSt;
        int curNum = 0;
        int prevNum;
        
        string prevString;
        string curString = "";
        
        for(int i = 0; i<s.size(); i++){
            
            if(isdigit(s[i]))curNum = curNum*10 + (s[i] - '0');
            if(isalpha(s[i])) curString += s[i];
            
            if(s[i] == '['){
                stringSt.push(curString);
                numSt.push(curNum);
                curString = "";
                curNum = 0;
            }
            if(s[i] == ']'){
                prevNum = numSt.top();
                numSt.pop();
                prevString = stringSt.top();
                stringSt.pop();
                
                while(prevNum--){
                    prevString += curString;   
                }
                curString = prevString;
            }
        }
        return curString;
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        string s;
        cin>>s;
        
        Solution ob;
        cout<<ob.decodedString(s)<<"\n";
    }
    return 0;
}  // } Driver Code Ends