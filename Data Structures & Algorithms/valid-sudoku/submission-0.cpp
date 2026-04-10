class Solution {
public:
    bool checkSquare(vector<vector<char>>& board, int x, int y) {
        // x and y is cord of top left corner of board
        unordered_set<char> seen;
        for (int i = x; i < x + 3; ++i) {
            for (int j = y; j < y + 3; ++j) {
                if (board[j][i] == '.') continue;
                if (seen.count(board[j][i]) > 0) return false;
                seen.insert(board[j][i]);
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int y = 0; y < board.size(); ++y) {
            unordered_set<char> seen;
            for (int x = 0; x < board[0].size(); ++x) {
                if (board[y][x] == '.') continue;
                if (seen.count(board[y][x]) > 0) return false;
                seen.insert(board[y][x]);
            }
        }

        for (int x = 0; x < board[0].size(); ++x) {
            unordered_set<char> seen;
            for (int y = 0; y < board.size(); ++y) {
                if (board[y][x] == '.') continue;
                if (seen.count(board[y][x]) > 0) return false;
                seen.insert(board[y][x]);
            }
        }

        vector<pair<int, int>>corners {{0, 0}, {3, 0}, {6, 0}, {3, 0}, {3, 3}, {3, 6}, {6, 0}, {6, 3}, {6, 6}};

        for (auto &p : corners) {
            if (!checkSquare(board, p.first, p.second)) return false;
        }
        return true;
    }
};
