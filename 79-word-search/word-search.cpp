class Solution {
public:

    bool search(vector<vector<char>>&  board, string& word, int row, int col ,int idx){
        if(row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col]!=word[idx]){
            return false;
        }

        if(idx==word.length()-1){
            return true;
        }

        char temp=board[row][col];
        board[row][col]='?';
        bool flag=search(board,word,row+1,col,idx+1) || search(board,word,row,col+1,idx+1) || search(board,word,row,col-1,idx+1) || search(board,word,row-1,col,idx+1);
        board[row][col]=temp;
        return flag;


    }

    bool exist(vector<vector<char>>& board, string word) {
        int r=board.size();
        int c=board[0].size();
        for(int i=0;i<r;i++){
            for(int j=0;j<c;j++){
                if(board[i][j]==word[0] && search(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
    }
};