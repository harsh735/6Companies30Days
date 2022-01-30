class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        
        int sum = 0;
        int maxi = 0;
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            maxi = max(nums[i],maxi);
        }
        
        int low = maxi; //max element in array
        int high = sum; //total sum of array
        int ans = 0;
        
        if(m == nums.size()) return low;
        
        while(low <= high){
            int mid = low + (high - low)/2;
            
            if(isPossible(nums,mid,m) == true){
                
                ans = mid;
                high = mid - 1;
            }
            else
                low = mid + 1;
        }
        
        return ans;
    }
    
    
    int isPossible(vector<int>&nums,int mid, int m){
        int subArrCount = 1;
        int sum = 0;
        
        for(int i = 0; i<nums.size(); i++){
            sum += nums[i];
            
            if(sum > mid){
                subArrCount++;
                sum = nums[i];
            }
        }
        return subArrCount <= m;
    }
};