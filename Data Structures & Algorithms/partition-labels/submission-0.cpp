class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, int> latestCharIndex;
        for (int i = 0; i < s.size(); ++i) {
            latestCharIndex[s[i]] = i;
        }

        vector<int> groups;
        int latestIndex = 0; //9
        int curSize = 0;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            curSize++;
            if (latestCharIndex[c] > latestIndex) latestIndex = latestCharIndex[c];
            if (i == latestIndex) {
                groups.push_back(curSize);
                curSize = 0;
            }
        }
        return groups;
    }
};

// xyxxyzbzbbisl
// x: 3
// y: 4
// z: 7
// b: 9
// i: 10
// s: 11
// l: 12 
