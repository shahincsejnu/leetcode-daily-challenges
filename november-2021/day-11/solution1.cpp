class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size(), mn = 1e9, sum = 0;

        for(int i = 0; i < n; i++){
            sum += nums[i];

            mn = min(mn, sum);
        }

        if(mn > 0) return 1;
        return abs(mn) + 1;
    }
};