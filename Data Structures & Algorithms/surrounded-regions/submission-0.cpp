class Solution {
public:
    void traverse(vector<vector<char>>& board, vector<vector<int>>& curVisited, vector<vector<bool>>& visited, int row, int col, bool& touchEdge) {
        if (row < 0 || row >= board.size() || col < 0 || col >= board[0].size()) return;
        if (board[row][col] != 'O') return;
        if (visited[row][col]) return;
        curVisited.push_back({row, col});
        visited[row][col] = true;
        if (row == 0 || row == board.size() - 1 || col == 0 || col == board[0].size() - 1) touchEdge = true;
        traverse(board, curVisited, visited, row + 1, col, touchEdge);
        traverse(board, curVisited, visited, row, col + 1, touchEdge);
        traverse(board, curVisited, visited, row - 1, col, touchEdge);
        traverse(board, curVisited, visited, row, col - 1, touchEdge);
    }

    void markBoard(vector<vector<char>>& board, vector<vector<int>>& curVisited) {
        for (int i = 0; i < curVisited.size(); ++i) {
            int row = curVisited[i][0];
            int col = curVisited[i][1];
            board[row][col] = 'X';
        }
    }


    void solve(vector<vector<char>>& board) {
        vector<vector<bool>> visited(board.size(), vector<bool>(board[0].size(), false));
        for (int row = 0; row < board.size(); ++row) {
            for (int col = 0; col < board[0].size(); ++col) {
                if (board[row][col] == 'O' && visited[row][col] == false) {
                    vector<vector<int>> curVisited;
                    bool touchEdge = false;
                    traverse(board, curVisited, visited, row, col, touchEdge);
                    if (!touchEdge) markBoard(board, curVisited);
                }
            }
        }
        return;
    }
};
