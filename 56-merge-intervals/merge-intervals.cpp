class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<vector<int>> ans;
        if(n==0){
            return intervals;
        }
        sort(intervals.begin(),intervals.end());
        vector<int> tempint = intervals[0];
        for(auto it:intervals){
            if(it[0]<=tempint[1]){
                tempint[1] = max(tempint[1],it[1]);
            }
            else{
                ans.push_back(tempint);
                tempint = it;
            }
        }
        ans.push_back(tempint);
        return ans;
    }
};