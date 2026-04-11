class Solution {
public:
    int findDistance(vector<vector<int>> &memo, string &word1, string &word2, int index1, int index2) {
        if (memo[index1][index2] != -1) return memo[index1][index2];

        int distance = -1;
        if (index1 >= word1.size() && index2 >= word2.size()) return 0;
        else if (index1 >= word1.size()) distance = 1 + findDistance(memo, word1, word2, index1, index2 + 1);
        else if (index2 >= word2.size()) distance = 1 + findDistance(memo, word1, word2, index1 + 1, index2);
        else if (word1[index1] == word2[index2]) distance = findDistance(memo, word1, word2, index1 + 1, index2 + 1);

        if (distance != -1) {
            memo[index1][index2] = distance;
            return distance;
        }
        
        int insertDistance = 1 + findDistance(memo, word1, word2, index1, index2 + 1);
        int deleteDistance = 1 + findDistance(memo, word1, word2, index1 + 1, index2);
        int replaceDistance = 1 + findDistance(memo, word1, word2, index1 + 1, index2 + 1);
        memo[index1][index2] = min(insertDistance, min(deleteDistance, replaceDistance));
        return memo[index1][index2];
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>> memo(word1.size() + 1, vector<int>(word2.size() + 1, -1));
        return findDistance(memo, word1, word2, 0, 0);
    }
};
