class Solution {
public:
    int dp[22][22];

    int func(int left, int right)
    {
        if(right <= left) return dp[left][right] = 1;

        if(dp[left][right] != -1) return dp[left][right];

        int cnt = 0;

        for(int i = left; i <= right; i++){
            int lft = func(left, i-1);
            int rht = func(i+1, right);

            cnt += (lft * rht);
        }

        return dp[left][right] = cnt;
    }

    int numTrees(int n) {
        memset(dp, -1, sizeof(dp));

        return func(1, n);
    }
};