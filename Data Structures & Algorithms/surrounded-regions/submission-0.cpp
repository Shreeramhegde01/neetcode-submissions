class Solution {
    void dfs(int i, int j, vector<vector<char>> &b){
        if(i<0 or j<0 or i>=b.size() or j>= b[0].size() or b[i][j]!='O') return;
        b[i][j]='@';
        dfs(i+1,j,b);
        dfs(i,j+1,b);
        dfs(i-1,j,b);
        dfs(i,j-1,b);
    }
public:
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int i=0;i<n;i++){
            if(board[i][0]=='O') dfs(i,0,board);
            if(board[i][m-1]=='O') dfs(i,m-1,board);
        }
        for(int j=0;j<m;j++){
            if(board[0][j]=='O') dfs(0,j,board);
            if(board[n-1][j]=='O') dfs(n-1,j,board);
        }
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='@') board[i][j]='O';
            }
        }
    }
};
