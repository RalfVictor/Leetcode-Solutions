class Solution {
public:
    string bin(int x){
        string binary = "";
        while(x!=0){
            int b = x%2;
            if(b==0){
                binary+="0";
            }
            else{
                binary+="1";
            }
            x=x/2;
        }
        reverse(binary.begin(),binary.end());
        return (binary);
    }
    
    string convertDateToBinary(string date) {
        string ye = "";
        string mo = "";
        string da = "";
        for(int i=0;i<10;i++){
            if(date.at(i)=='-'){
                continue;
            }
            if(i<4){
                ye+=date[i];
            }
            else if(i<7){
                mo+=date[i];
            }else{
                da+=date[i];
            }
        }
        return bin(stoi(ye))+"-"+bin(stoi(mo))+"-"+bin(stoi(da));
    }
};