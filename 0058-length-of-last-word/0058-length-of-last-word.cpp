class Solution {
public:
    int lengthOfLastWord(string s) {
        int size = 0;
        int start;
        int n = s.length();
        for(int i=n-1;i>=0;i--){
            if(s[i]!=' '){
                start = i;
                break;
            }
        }
        for(int i=start;i>=0;i--){\
        if(s[i]==' '){
                break;
            }
            cout<<s[i];
            size++;
            
        }
        return size;
    }
};