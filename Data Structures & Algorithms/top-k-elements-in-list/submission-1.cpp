class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> intCount;
        for (int i : nums) {
            if (intCount.find(i) != intCount.end()) {
                ++intCount[i];
            } else {
                intCount[i] = 1;
            }
        }

        vector<int> returnVector;
        returnVector.reserve(k);
        for (int i = 0; i < k; ++i) {
            returnVector.push_back(findHighest(intCount));
        }
        return returnVector;
    }

    int findHighest(unordered_map<int, int> &intCount) {
        int highCount = INT_MIN;
        int highNum = 0;

        for (auto i : intCount) {
            if (i.second > highCount) {
                highCount = i.second;
                highNum = i.first;
            }
        }
        intCount.erase(highNum);
        return highNum;
    }
};
