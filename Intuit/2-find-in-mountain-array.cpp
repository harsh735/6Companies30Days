/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        
        int peak = peakIndex(mountainArr);
        int ans = orderAgnosticBS(mountainArr, target, 0, peak);
        if(ans == -1)
            ans = orderAgnosticBS(mountainArr, target, peak + 1, mountainArr.length() - 1);
        
        return ans;
    }
    
    int peakIndex(MountainArray &mountainArr) {
        
        int start = 0;
        int end = mountainArr.length() - 1;
        
        while(start < end){
            int mid = start + (end - start) / 2;
            if(mountainArr.get(mid) > mountainArr.get(mid + 1))
                end = mid;
            else
                start = mid + 1;
        }
        return end;
    }
    
    
    int orderAgnosticBS(MountainArray &mountainArr, int target, int start, int end) {
        
        bool rev = mountainArr.get(start) > mountainArr.get(end); 
        while(start <= end) {
            int mid = start + (end - start) / 2;
            
            int ele = mountainArr.get(mid);
            if (ele == target)
                return mid;
            else if (ele < target) {
                if(rev)
                    end = mid - 1;
                else
                    start = mid + 1;
            } else if (ele > target) {
                if(rev)
                    start = mid + 1;
                else
                    end = mid - 1;
            }
        }
        
        return -1;
        
        
       /*BRUTE FORCE
        
        bool flag = false;
        vector<int> ans;
        int res = 0;
        for(int i = 0; i<mountainArr.length(); i++) {
            if(mountainArr.get(i) == target) {
                ans.push_back(i);
                flag = true;
            }
        }
        if(flag){
            sort(ans.begin(),ans.end());
            return res = ans[0];
        }
        else return -1;
        */        
    }
};