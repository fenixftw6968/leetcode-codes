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
          int n = mountainArr.length();

        // 1. Find peak using binary search
        int l = 0, r = n - 1;

        while (l < r) {
            int mid = l + (r - l) / 2;

            if (mountainArr.get(mid) < mountainArr.get(mid + 1))
                l = mid + 1;
            else
                r = mid;
        }

        int peak = l;
        int peak_idx=peak;
         l=0;
         r=peak_idx;
        while(l<=r){
            int mid=(l+r)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)<target) l=mid+1;
            else r=mid-1;
        }

        int l1=peak_idx+1;
        int r1=mountainArr.length()-1;
        while(l1<=r1){
            int mid=(l1+r1)/2;
            if(mountainArr.get(mid)==target) return mid;
            else if(mountainArr.get(mid)<target) r1=mid-1;
            else l1=mid+1;
            
        }
        return -1;
    }
};