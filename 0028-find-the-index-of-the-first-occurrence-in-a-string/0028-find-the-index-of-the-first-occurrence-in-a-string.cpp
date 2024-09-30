class Solution {
public:
    int strStr(string haystack, string needle) {
        int h=-1;
        int c = needle.length();
        int x =haystack.length();
        if(needle==haystack){
            return 0;
        }else if(c>=x){
            return h;
        }
        
        else if(c==1){
            for(int i=0;i<x;i++){
            string b ="";
            for(int j=i;j<i+c;j++){
                b=b+haystack[j];
            }
        if(b==needle){
            h=i;
            break;
        }
        }
        return h;
        }
        else if(c==x){
            for(int i=0;i<x;i++){
            string b ="";
            for(int j=i;j<i+c;j++){
                b=b+haystack[j];
            }
        if(b==needle){
            h=i;
            break;
        }
        }
        return h;
        } 
        else{
        for(int i=0;i<x-c+1;i++){
            string b ="";
            for(int j=i;j<i+c;j++){
                b=b+haystack[j];
            }
        if(b==needle){
            h=i;
            break;
        }
        }
        return h;
        }

    }
};