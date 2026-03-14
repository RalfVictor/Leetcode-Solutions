class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& n1, vector<int>& n2) {
        int n = n2.size();
        vector<int> v(n,-1);
        stack<int> st;
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++){
            while(!st.empty() && n2[st.top()]<n2[i]){
                v[st.top()] = n2[i];
                st.pop();
            }
            st.push(i);
        }
        for (int i = 0; i < n; i ++){
            mp.insert({n2[i], v[i]});
        }
        vector<int>ans;
        for(int i = 0; i < n1.size(); i ++){
            ans.push_back(mp[n1[i]]);
        }
        return ans;
    }
};