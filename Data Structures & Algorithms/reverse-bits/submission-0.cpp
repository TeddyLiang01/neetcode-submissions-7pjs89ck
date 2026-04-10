class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            int toAdd = 1 << i;
            if ((n & toAdd) != 0) {
                res = res | (1 << (31 - i));
            }
        }
        return res;
    }
};
