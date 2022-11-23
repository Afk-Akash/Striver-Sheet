class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int m = 9, n = 9;
        for(int i = 0; i < 9; i++){
            unordered_set<char> set;
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')continue;
                if(set.find(board[i][j]) != set.end()) return 0;
                set.insert(board[i][j]);
                // cout<<i<<" ";
            }
        }
        // cout<<endl;
        for(int i = 0; i < 9; i++){
            unordered_set<char> set;
            for(int j = 0; j < 9; j++){
                if(board[j][i] == '.')continue;
                if(set.find(board[j][i]) != set.end()) return 0;
                set.insert(board[j][i]);
                // cout<<i<<" ";
            }
        }
        // cout<<endl;
        for(int i = 0; i < 9; i++){
            unordered_set<char> set;
            for(int j = 0; j < 9; j++){
                if(board[(i/3)*3+j/3][(i%3)*3 + j%3] == '.')continue;
                if(set.find(board[(i/3)*3+j/3][(i%3)*3 + j%3]) != set.end()) return 0;
                set.insert(board[(i/3)*3+j/3][(i%3)*3 + j%3]);
                // cout<<i<<" ";
            }
        }
        return 1;
    }
};