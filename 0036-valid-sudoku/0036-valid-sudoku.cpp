class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int vis1[9][9]={0}, vis2[9][9]={0}, vis3[9][9]={0};
        for(int i = 0; i < 9; i++){
            for(int j = 0; j < 9; j++){
                if(board[i][j] == '.')continue;
                int val = board[i][j] - '0' - 1, box = (i/3)*3 + j/3;
                if(vis1[i][val] or vis2[j][val] or vis3[box][val]) return false;
                vis1[i][val]=1;
                vis2[j][val]=1;
                vis3[box][val]=1;
            }
        }
        return 1;
    }
};