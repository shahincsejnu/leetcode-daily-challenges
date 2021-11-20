class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int lo = 1, hi = m*n, mid;

        while(lo < hi){
            mid = lo + (hi-lo)/2;
            int cnt = 0;

            for(int i = 1; i <= m; i++){
                cnt += min(mid/i, n);
            }

            if(cnt >= k) hi = mid;
            else lo = mid+1;
        }

        return lo;
    }
};