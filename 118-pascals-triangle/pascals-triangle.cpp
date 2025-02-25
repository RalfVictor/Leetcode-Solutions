class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<int> temp;
        vector<vector<int>> ans;
        int count = 0;
        int col = 1;
        for(int i=1;i<=numRows;i++){
            int res = 1;
            for(int j = 0;j<col;j++){
                if(j == 0){
                    temp.push_back(1);
                    continue;
                }
                else{
                    res = res*(col-j);
                    res = res/j;
                    temp.push_back(res);
                } 
            }
        ans.push_back(temp);
        temp.clear();
        col++;
        }
        return ans;
    }
};