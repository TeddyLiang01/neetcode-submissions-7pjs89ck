class Solution {
public:
    int hammingWeight(uint32_t n) {
        int count = 0;
        while(n){
            count++;
            n &= ~-n;
        }
        return count;
    }
};

/*
count = 0

loop throuhg(
    if 1, count++
)

010111011101
000000000001 = 1
000000000000
000011
23 >> 1 = 11
23 << 1 = 46
23 & 259 = 3

return count
*/