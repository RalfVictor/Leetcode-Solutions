class Solution {
public:
    string reverseOnlyLetters(string s) {
        int i=0;
        int j=s.length()-1;
        //97,122,65,90
        while(i<j){
            int x = int(s[i]);
            int y = int(s[j]);
            if(((x>=97&&x<=122)||(x>=65&&x<=90)) && ((y>=97&&y<=122)||(y>=65&&y<=90))){
                swap(s[i],s[j]);
                i++;j--;
            }else if(!((x>=97&&x<=122)||(x>=65&&x<=90)) && ((y>=97&&y<=122)||(y>=65&&y<=90))){
                i++;
            }
            else{
                j--;
            }
        }
        return s;
    }
};