class Solution {
public:
    bool rotateString(string s, string goal) {
        int n = s.length();
        string temp;
        temp.append(n,'$');
        cout<<temp;
        for(int j=0;j<n;j++){
        for(int i=0;i<n;i++){
            temp[(i+j)%n] = s[i];
        }
        if(temp==goal){
            return true;
        }
        }
        return false;
    }
};