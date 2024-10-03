class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        vector<char> str2;
        int m = stones.length();
        int n = jewels.length();
        for(int i=0;i<m;i++){
            str2.push_back(stones[i]);
        }
        int ans = 0;
        for(int i=0;i<n;i++){
            ans += count(str2.begin(),str2.end(),jewels[i]);
        }
        return ans;
    }
};