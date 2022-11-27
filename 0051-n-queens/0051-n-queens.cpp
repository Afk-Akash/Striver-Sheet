class Solution {
public:
    bool is_valid(vector<string> &board, int row, int col){
        // check col
        for(int i=row;i>=0;--i)
            if(board[i][col] == 'Q') return false;
        // check left diagonal
        for(int i=row,j=col;i>=0&&j>=0;--i,--j)
            if(board[i][j] == 'Q') return false;
        //check right diagonal
        for(int i=row,j=col;i>=0&&j<board.size();--i,++j)
            if(board[i][j] == 'Q') return false;
        return true;
    }
    bool isValid(vector<string> &board, int row, int col){
        for(int i = 0; i <= row; i++){
            // if(board[row][i] == 'Q') return false;
            if(board[i][col] == 'Q') return false;
        }
        for(int i = row, j = col; i >= 0 and j >= 0; i--,j--){
            if(board[i][j] == 'Q') return false;
        }
        for(int i = row, j = col; i >= 0 and j < board.size(); i--, j++){
            if(board[i][j] == 'Q') return false;
        }
        return true;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        string s= "";
        for(int i = 1; i<= n; i++)s.push_back('.');
        vector<string> t(n,s);

        vector<vector<bool>> vis(n, vector<bool> (n,false));
        
        fun(0, ans, t, n, vis, 0);
        return ans;
    }
    void fun(int ind, vector<vector<string>> & ans, vector<string> & temp, int n, vector<vector<bool>>&vis, int cnt){
        if(ind == n){
            ans.push_back(temp);
            return;
        }
        for(int j = 0; j < n; j++){
            if(isValid(temp, ind, j) == false)continue;
            // if(vis[ind][j])continue;
            temp[ind][j] = 'Q';
            for(int i = ind; i < n; i++){
                vis[i][j] = 1;
            }
            int p = ind, q = j;
            while(p < n and q >= 0){
                vis[p][q] = 1;
                p++;
                q--;
            }
            p = ind, q = j;
            while(p < n and q < n){
                vis[p][q] = 1;
                p++;
                q++;
            }
            
            fun(ind+1, ans, temp, n, vis, cnt+1);
            temp[ind][j] = '.';
            for(int i = ind; i < n; i++){
                vis[i][j] = false;
            }

            p = ind, q = j;
            while(p < n and q >= 0){
                vis[p][q] = false;
                p++;
                q--;
            }
            p = ind, q = j;
            while(p < n and q < n){
                vis[p][q] = false;
                p++;
                q++;
            }
            
            
        }

        
    }
};