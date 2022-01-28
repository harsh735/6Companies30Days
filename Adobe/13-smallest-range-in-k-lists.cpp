// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define N 1000


 // } Driver Code Ends
// you are required to complete this function 
// function should print the required range
class Solution{
    public:
    typedef pair<int,pair<int,int>> pai;
    pair<int,int> findSmallestRange(int KSortedArray[][N], int n, int k)
    {
        //code here
        pair<int,int> ans;
        int mini = INT_MAX;
        int mx = 0;
        int minEle = INT_MAX;
        int maxEle = INT_MIN;
        int range = INT_MAX;
        pair<int,int> minIdx;
        priority_queue<pai,vector<pai>,greater<pai>> pq;
        for(int i=0;i<k;i++) {
            pq.push(make_pair(KSortedArray[i][0],make_pair(i,0)));
            mx = max(mx,KSortedArray[i][0]);
        }
        while(true) {
            mini = pq.top().first;
            minIdx = pq.top().second;
            pq.pop();
            if(mx - mini < range)
            {
                maxEle = mx;
                minEle = mini;
                range = (mx-mini);
                ans = make_pair(mini,mx);
            }
            int x=minIdx.first;
            int y=minIdx.second+1;
            if(y==n)
                break;
                
            if(KSortedArray[x][y]>mx)
            mx = KSortedArray[x][y];
            pq.push(make_pair(KSortedArray[x][y],make_pair(x,y)));
        }
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n, k;
        cin>>n>>k;
        int arr[N][N];
        pair<int,int> rangee;
        for(int i=0; i<k; i++)
            for(int j=0; j<n; j++)
                cin>>arr[i][j];
        Solution obj;
	    rangee = obj.findSmallestRange(arr, n, k);
	    cout<<rangee.first<<" "<<rangee.second<<"\n";
    }   
	return 0;
}

  // } Driver Code Ends