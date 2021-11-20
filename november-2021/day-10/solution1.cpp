class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices.size(), profit = 0, mn;

        if(l == 0) return profit;

        mn = prices[0];

        for(int i = 1; i < l; i++){
            if(prices[i] <= mn) mn = prices[i];
            else{
                profit += (prices[i] - mn);
                mn = prices[i];
            }
        }

        return profit;
    }
};