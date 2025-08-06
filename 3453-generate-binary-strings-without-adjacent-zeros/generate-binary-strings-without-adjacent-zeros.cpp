class Solution {
public:
void printall(int num,int i,vector<string>& ans,string temp){
        if(i == num) {
            ans.push_back(temp);
            return;
        }
        if(i==0){
            temp += '0';
            printall(num,i+1,ans,temp);
            temp.pop_back();
            temp +='1';
            printall(num,i+1,ans,temp);
        }
        else{
            temp+='1';
            printall(num,i+1,ans,temp);
            if(temp[i-1]!='0'){
               temp.pop_back();
                temp +='0';
                printall(num,i+1,ans,temp); 
            }
        }
        return;
    }
    vector<string> validStrings(int n) {
        vector<string> ans;
        printall(n,0,ans,"");
        return ans;
    }
};