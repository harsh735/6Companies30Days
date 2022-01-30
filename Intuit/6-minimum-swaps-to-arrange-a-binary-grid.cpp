class Solution {
public:
    int minSwaps(vector<vector<int>>& grid) {
        
        int n=grid.size(),res=0;
        vector<int>a(n);
        
        //finding the zeroes at the end of each row.
        for(int i=0 ; i<n ; i++){
            int j=n-1;
            int count = 0;
            while(j>=0 && grid[i][j]==0) {count++;j--;}
            a[i]=count;
        }
        
        //for calculating the swaps count or sorting the array decreasing.
        for(int i=0 ; i<n ; i++){
            if(a[i]<n-1-i){
                int j=i;
                while(j < n && a[j]<n-1-i) 
                    j++;
                
                if(j == n) return -1;
                while(i < j) {
                    swap(a[j],a[j-1]);
                    res++;
                    j--;
                }
            }
        }
        return res;
    }
};