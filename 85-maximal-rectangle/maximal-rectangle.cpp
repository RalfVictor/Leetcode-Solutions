class Solution {
public:
    int f(vector<int>& heights){
        int n = heights.size();
        stack<int> st;
        int area = 0;
        for(int i=0;i<=n;i++){
            while(!st.empty()&&(i==n||heights[st.top()]>=heights[i])){
                int height = heights[st.top()];
                st.pop();
                int width;
                if(st.empty()) width = i;
                else width = i-st.top()-1;
                area = max(area,width*height);
            }
            st.push(i);
        }   
        return area;
    } 
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int maxarea = 0;
        vector<int> rect(m,0);
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(matrix[i][j]=='1'){
                    rect[j]++;
                }else if(matrix[i][j]=='0'){
                    rect[j] = 0;
                }
            }
        maxarea = max(maxarea,f(rect));
        }
        return maxarea;
    }
};