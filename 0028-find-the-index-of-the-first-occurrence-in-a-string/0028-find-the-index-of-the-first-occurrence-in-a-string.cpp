class Solution {
public:
    int strStr(string haystack, string needle) {
        int ans = -1;
        int n1 = haystack.length();
        int n2 = needle.length();
        int i=0;
        while(ans==-1 && i<n1-n2+1){
            int st = 0;
            while(st<n2){
                if(haystack[i+st]==needle[st]){
                    ans = i;
                    st++;
                }else{
                    ans=-1;
                    break;
                }
            }i++;
        }return ans;
    }
};