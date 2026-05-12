class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int row[9][9]={0};
        int col[9][9]={0};
        int box[9][9]={0};
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                char c=board[i][j];
                
                if(isdigit(c)){
                int num=c-'1';
                row[i][num]++; 
                col[j][num]++;
                box[(i/3)*3+(j/3)][num]++;
                if(row[i][num]>1 or col[j][num]>1 or box[(i/3)*3+(j/3)][num]>1) return false;
                }
            
            }
        }
        return true;
    }
};
