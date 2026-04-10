class Solution {
public:
    vector<int> sizes;

    string encode(vector<string>& strs) {
        string ret = "";
        for (auto s : strs) {
            ret += s;
            sizes.push_back(s.size());
        }
        return ret;
    }

    vector<string> decode(string s) {
        vector<string> ret;
        int lastIndex = 0;
        for (auto& size : sizes) {
            ret.push_back(s.substr(lastIndex, size));
            lastIndex += size;
        }
        return ret;

    }
};
