class Solution {
    bool f(vector<vector<char>>& bo, string &word, int r, int c,int idx){
        if(idx==word.size()) return true;
        if(r<0 or c<0 or r>=bo.size() or c>=bo[0].size() or bo[r][c]!=word[idx] or bo[r][c]=='!')
            return false;
        char ch= bo[r][c];
        bo[r][c]='!';
        bool up=f(bo,word,r-1,c,idx+1);
        bool right=f(bo,word,r,c+1,idx+1);
        bool left=f(bo,word,r,c-1,idx+1);
        bool down=f(bo,word,r+1,c,idx+1);
        bo[r][c]=ch;
        return up || down || left || right;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(board[i][j]==word[0]){
                    if(f(board,word,i,j,0)) return true;
                }
            }
        }
        return false;
    }
};
