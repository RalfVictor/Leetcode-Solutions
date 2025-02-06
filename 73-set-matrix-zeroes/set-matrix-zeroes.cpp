class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> rowzero(row,0);
        vector<int> colzero(col,0);
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