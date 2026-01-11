class Solution {
public:
void findsum(vector<int>& candidates,int target,int index, vector<int>& vals, int sum, vector<vector<int>>& ans,int n){
        if(sum == target){
            sort(vals.begin(),vals.end());
            ans.push_back(vals);
            return;
        }
        else if(sum>target){
            return;
        }
        for(int i=index;i<n;i++){
            if (i > index && candidates[i] == candidates[i - 1]) continue;
            if (candidates[i] > target) break;
            int x = candidates[i];
            vals.push_back(x);
            findsum(candidates,target,i+1,vals,sum+x,ans,n);
            vals.pop_back();
        }
        return;
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int n = candidates.size();
        vector<vector<int>> ans;
        vector<int> vals;
        if(n==0){
            return ans;
        }
        findsum(candidates,target,0,vals,0,ans,n);
        return ans;
    }
};