class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        vector<int> dp(nums.size(), 1);
        int val = 0, n = nums.size();

        for(int i = 1; i < n; i++){
            for(int j = 0; j < i; j++){
                if(nums[i] % nums[j] == 0) dp[i] = max(dp[i], 1 + dp[j]);
            }
        }

        for(int i = 0; i < n; i++) val = max(val, dp[i]);

        vector<int> ans;

        for(int i = n-1; i >= 0; i--){
            if(dp[i] == val && (!ans.size() || ans.back()%nums[i] == 0)){
                ans.push_back(nums[i]);
                val--;
            }
        }

        return ans;
    }
};