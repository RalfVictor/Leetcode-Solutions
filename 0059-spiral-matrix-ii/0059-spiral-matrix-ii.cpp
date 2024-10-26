class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        int count = 1;
        int total = pow(n,2)+1;
        int strow = 0;
        int stcol = 0;
        int endrow = n-1;
        int endcol = n-1;
        vector<int> temp;
        vector<vector<int>> ans;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                temp.push_back(0);
            }
        ans.push_back(temp);
        temp.clear();
        }
        while(count<total){
        vector<int> temp ;
        for(int i=stcol;count<total && i<=endcol;i++){
            ans[strow][i] = count;
            count++;
        }
        strow++;
        for(int i=strow;count<total && i<=endrow;i++){
            ans[i][endcol] = count;
            count++;
        }
        endcol--;
        for(int i=endcol;count<total && i>=stcol;i--){
            ans[endrow][i] = count;
            count++;
        }
        endrow--;
        for(int i=endrow;count<total && i>=strow;i--){
            ans[i][stcol] = count;
            count++;
        }
            stcol++;
        }
    return ans;
    }
};