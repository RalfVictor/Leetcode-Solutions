class Solution {
public:
    int ones (int n){
    int count = 0;
    while(n!=0){
        int x = n%2;
        if(x==1){
            count++;
        }
        n=n/2;
    }
    return count;
    }
    
    vector<int> countBits(int n) {
        vector<int> ans = {0};
        for(int i=1;i<=n;i++){
            ans.push_back(ones(i));
        }
        return ans;
    }
};