class Solution {
public:
    bool findWord(vector<vector<char>>& board, string word, vector<vector<bool>>& visited, int row, int col) {
        if (word.size() == 0) return true;
        visited[row][col] = true;
        bool result = false;
        if (row > 0 && board[row - 1][col] == word[0] && !visited[row - 1][col]) {
            result = result || findWord(board, word.substr(1), visited, row - 1, col);
        }
        if (row < board.size() - 1 && board[row + 1][col] == word[0] && !visited[row + 1][col]) {
            result = result || findWord(board, word.substr(1), visited, row + 1, col);
        }
        if (col > 0 && board[row][col - 1] == word[0] && !visited[row][col - 1]) {
            result = result || findWord(board, word.substr(1), visited, row, col - 1);
        }
        if (col < board[0].size() - 1 && board[row][col + 1] == word[0] && !visited[row][col + 1]) {
            result = result || findWord(board, word.substr(1), visited, row, col + 1);
        }
        visited[row][col] = false;
        return result;
    }    

    bool exist(vector<vector<char>>& board, string word) {
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                bool found = false;
                vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
                if (board[row][col] == word[0]) found = findWord(board, word.substr(1), visited, row, col);
                if (found) return true;
            }
        }
        return false;
    }
};
