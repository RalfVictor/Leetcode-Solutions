class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        int count = 0;
        int tot = row*col;
        int strow = 0;
        int stcol = 0;
        int enrow = row-1;
        int encol = col-1;
        vector<int> ans;
        
        while(count<tot){
            for(int i=stcol;count<tot && i<=encol;i++){
                ans.push_back(matrix[strow][i]);
                count++;
            }
            strow++;
            for(int i=strow;count<tot && i<=enrow;i++){
                ans.push_back(matrix[i][encol]);
                count++;
            }
            encol--;
            for(int i=encol;count<tot && i>=stcol;i--){
                ans.push_back(matrix[enrow][i]);
                count++;
            }
            enrow--;
            for(int i=enrow;count<tot && i>=strow;i--){
                ans.push_back(matrix[i][stcol]);
                count++;
            }
            stcol++;
        }
        return ans;
    }
};