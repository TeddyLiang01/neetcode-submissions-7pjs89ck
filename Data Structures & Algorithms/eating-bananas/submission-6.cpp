class Solution {
public:
    bool canComplete(vector<int>& piles, int h, int k) {
        int count = 0;
        for (auto &pile : piles) {
            count += pile / k;
            if (pile % k > 0) count += 1;
        }
        return h >= count;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        // at least piles.size()
        // at most max(piles)
        int low = 1;
        int high = piles[0]; // 4
        for (auto &pile : piles) {
            if (pile > high) high = pile;
        }

        int best = high;
        while (low <= high) {
            int mid = (low + high) / 2;

            if (canComplete(piles, h, mid)) {
                if (best > mid) best = mid;
                high = mid - 1;
            } else {
                low = mid + 1;
            }
        }
        return best;
    }
};
