class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size(), lo = 0, hi = n-1, mid;

        while(lo <= hi){
            mid = lo + (hi-lo)/2;

            if(lo == hi) return nums[mid];
            if(mid > lo && mid < hi && nums[mid] != nums[mid-1] && nums[mid] != nums[mid+1]) return nums[mid];
            if(mid > lo && nums[mid] == nums[mid-1]) mid--;


            int d1 = mid-lo, d2 = hi-mid+1;

            if(d1%2) hi = mid-1;
            else lo = mid+2;
        }

        return -1;
    }
};