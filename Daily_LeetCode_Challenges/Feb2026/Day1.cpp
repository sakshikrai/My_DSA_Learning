// problem link- https://leetcode.com/problems/minimum-time-to-make-rope-colorful/?envType=daily-question&envId=2025-11-03

class Solution {
public:
    int binaryGap(unsigned n) {
        int d=0, p=32;
        for(; n>0; n&=(n-1)){
            int ctz=countr_zero(n);
            d=max(d, ctz-p);
            p=ctz;
        }
        return d;
    }
};