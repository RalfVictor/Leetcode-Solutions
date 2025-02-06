class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int x,y;
        int rowzero[row];
        int colzero[col];
        for(int i=0;i<row;i++){
            rowzero[i]=0;
        }
        for(int i=0;i<col;i++){
            colzero[i]=0;
        }
        for(int i = 0;i<row;i++){
            for(int j=0;j<col;j++){
                if(matrix[i][j]==0){
                    rowzero[i]=1;
                    colzero[j]=1;
                }
            }
        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(rowzero[i] || colzero[j]){
                    matrix[i][j]=0;
                }
            }
        }
    }
};