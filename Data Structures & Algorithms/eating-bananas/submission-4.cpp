class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // piles[i]: # of banana in ith pile
        // h: hours needed to eat all bananas
        // k: bananas/hour

        // 1 4 3 2

        // could be 1-4

        int min = 1;
        int max = INT_MIN;
        for (auto i : piles) {
            if (i > max) {
                max = i;
            }
        }

        int best = 0;

        while (min <= max) {
            int mid = min + (max - min) / 2;
            
            // loop each pile and add up all required
            int total = 0;
            for (auto p : piles) {
                total += p / mid;
                if (p % mid != 0) {
                    total += 1;
                }
            }

            if (total <= h) {
                max = mid - 1;
                best = mid;
            } else {
                min = mid + 1;
            } 
        }
        return best;

        
    }
};
