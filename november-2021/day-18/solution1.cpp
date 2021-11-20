class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;

        for(int i = 0; i < n; i++){
            int val = abs(nums[i]);

            if(nums[val-1] > 0) nums[val-1] *= -1;
        }

        for(int i = 0; i < n; i++){
            if(nums[i] > 0) ans.push_back(i+1);
        }

        return ans;
    }
};