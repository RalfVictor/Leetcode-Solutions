class Solution {
public:
    int countfuc(vector<int>& x, int t){
        if(count(x.begin(),x.end(),t)>=1){
            return 1;
        }else{
            return 0;
        }
    }

    vector<int> twoOutOfThree(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3) {
        vector<int> ans;
        int x;
        for(int i=1;i<=100;i++){
            x = countfuc(nums1,i)+countfuc(nums2,i)+countfuc(nums3,i);
            if(x>=2){
                ans.push_back(i);
        }
    }return ans;
    }
};