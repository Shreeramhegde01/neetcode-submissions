class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> s(n,string(n,'.'));
        f(n,0,s,ans);
        return ans;
    }
    void f(int n, int row, vector<string> &s, vector<vector<string>> &ans){
        if(row==n){
            ans.push_back(s);
            return;
        }
        for(int c=0;c<n;c++){
            if(isok(row,c,s,n)){
                s[row][c]='Q';
                f(n,row+1,s,ans);
                s[row][c]='.';
            }
        }
    }
    bool isok(int row, int col, vector<string>& s, int n){
        for(int i=0;i<row;i++) if(s[i][col]=='Q') return false;
        for(int i=row-1,j=col-1;i>=0 and j>=0;i--,j--) if(s[i][j]=='Q') return false;
        for(int i=row-1,j=col+1;i>=0 and j<n;i--,j++) if(s[i][j]=='Q') return false;
        return true;
    }
};
