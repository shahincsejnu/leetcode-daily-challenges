class Solution {
public:
    int arrangeCoins(int n) {
        int start = 0, end = n, mid, ans = 0;

        while(start <= end){
            mid = (start+end)/2;

            long long int val = (1ll * mid * (mid+1)) / 2;

            if(val <= n){
                ans = mid;
                start = mid+1;
            }
            else end = mid-1;
        }

        return ans;
    }
};