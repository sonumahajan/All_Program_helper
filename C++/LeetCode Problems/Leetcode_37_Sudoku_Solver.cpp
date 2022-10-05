class Solution {
public:
    bool isvalid(vector<vector<char>>& board,int row,int col,char val){
        for(int i=0;i<9;i++)
            if(col!=i && board[row][i]==val)  return false;
        for(int i=0;i<9;i++)
            if(row!=i && board[i][col]==val)  return false;
        int startr=3*(row/3),startc=3*(col/3);
        for(int i=startr;i<startr+3;i++){
            for(int j=startc;j<startc+3;j++)
                if(row!=i && col!=j && board[i][j]==val)    return false;
        }
        return true; 
    }
    
    bool func(vector<vector<char>>& board,int row,int col){
        if(row==board.size())   return true;
        if(col==board[0].size())    return func(board,row+1,0);
        if(board[row][col]!='.')  return func(board,row,col+1);
        for(int i=1;i<=9;i++){
            if(isvalid(board,row,col,i+'0')){
                board[row][col]=i+'0';
                if(func(board,row,col+1))   return true;
            }
        }
        board[row][col]='.';
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        func(board,0,0);
    }
};
