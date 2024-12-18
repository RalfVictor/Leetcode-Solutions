class Solution {
public:
    string reverseStr(string s, int k) {
        int n = s.length();
        int i = 0;
        int j = n-k;
        while(i<n){
            auto pt1 = s.begin()+i;
            auto pt2 = s.end()-j;
            if(j<0){
            reverse(pt1,s.end());
            break;
            }
            reverse(pt1,pt2);
            i=i+(2*k);
            j=j-(2*k);
        }
        return s;
    }
};