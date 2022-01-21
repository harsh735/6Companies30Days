class Solution {
public:
    int longestMountain(vector<int>& arr) {
        
        int end = arr.size(); 
        int ans =  0; 
        for(int i = 1; i< end - 1; i++){
            int left = i;
            int right = i;
            
            // to check for peak
            if(arr[i] > arr[i + 1] && arr[i - 1] < arr[i]){
    
                while(left > 0 && arr[left] > arr[left - 1]){
                    left--;                    
                }
                
                while(right + 1 < end && arr[right] > arr[right + 1]){
                    right++;                    
                }                
                ans = max(ans,(right - left + 1));
            }
        }
        return ans;
    }
};