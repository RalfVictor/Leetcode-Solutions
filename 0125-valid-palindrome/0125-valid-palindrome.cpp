class Solution {
public:
    bool isPalindrome(string s) {
        int x = s.length();
        string norm = "";
        for(int i = 0;i<x;i++){
            int y = s[i];
            if((y>=65 && y<=90)||(y>=97 && y<=122) || (y>=48 && y<=57)){
                norm+=s[i];
            }
        }
        transform(norm.begin(), norm.end(), norm.begin(), ::tolower);
        string rev = norm;
        reverse(rev.begin(),rev.end());
        cout<<rev;
        if(rev==norm){
            return true;
        }
        else{
            return false;
        }
        
    }
};