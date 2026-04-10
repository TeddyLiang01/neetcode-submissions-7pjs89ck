class Solution {
public:

    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if (hand.size() % groupSize != 0) return false;
        sort(hand.begin(), hand.end());
        
        unordered_map<int, int> count;
        for (auto &card : hand) {
            count[card]++;
        }

        for (auto &card : hand) {
            if (count[card] > 0) {
                for (int i = 0; i < count[card]; ++i) {
                    for (int j = 0; j < groupSize; ++j) {
                        count[card + j]--;
                        if (count[card + j] < 0) return false;
                    }
                }
            }
        }
        return true;

        
        

    }
};
