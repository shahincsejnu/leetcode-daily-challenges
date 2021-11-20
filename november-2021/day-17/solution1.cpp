class Solution {
public:
    int dp[105][105];

    int func(int i, int j)
    {
        if(i == 0 && j == 0) return dp[i][j] = 1;
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int val = func(i-1, j) + func(i, j-1);

        return dp[i][j] = val;
    }

    int uniquePaths(int m, int n) {
        memset(dp, -1, sizeof(dp));

        return func(m-1, n-1);
    }
};