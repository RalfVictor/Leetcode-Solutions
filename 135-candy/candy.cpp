class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<int> temp1(n,1);
        vector<int> temp2(n,1);
        for(int i=1,j=n-2;i<n;i++,j--){
            if(ratings[i]>ratings[i-1]){
                temp1[i] = temp1[i-1]+1;
            }
            if(ratings[j]>ratings[j+1]){
                temp2[j] = temp2[j+1]+1;
            }
        }
        int maxi = 0;
        for(int i=0;i<n;i++){
            maxi = maxi+(max(temp1[i],temp2[i]));
        }
        return maxi;
    }
};