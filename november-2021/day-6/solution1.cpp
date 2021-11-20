class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        unordered_map<int, int> ump;

        for(int i = 0; i < n; i++) ump[nums[i]]++;

        for(auto it : ump){
            if(it.second == 1) ans.push_back(it.first);
        }

        return ans;
    }
};