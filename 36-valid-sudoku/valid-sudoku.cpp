class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        for(int r=0;r<9;r++){
            for(int c=0;c<9;c++){
                char k = board[r][c];
                if(k!='.'){
                for(int i=0;i<9;i++){
                    if(board[i][c]==k && i!=r){
                        cout<<r<<c;
                        return false;   
                    } 
                    if(board[r][i]==k && i!=c){
                        cout<<r<<c;
                        return false;
                    }
                    if(board[3*(r/3)+i/3][3*(c/3)+i%3]==k && 3*(r/3)+i/3!=r && 3*(c/3)+i%3!=c){
                        return false;
                    }
                    }
                }
            }
        }
        return true;
    }
};