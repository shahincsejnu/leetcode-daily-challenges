class Solution {
public:
    int hammingDistance(int x, int y) {
        int xr = x ^ y, cnt = 0;

        while(xr){
            cnt++;
            xr = xr & (xr-1);
        }

        return cnt;
    }
};