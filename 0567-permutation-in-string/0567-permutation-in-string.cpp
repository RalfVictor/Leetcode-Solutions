class Solution {
public:
    bool check(int count[26],int count2[26]){
        for(int i=0;i<26;i++){
            if(count[i]!=count2[i]){
                return 0;
            }
        }
        return 1;
    }
    
    bool checkInclusion(string s1, string s2) {
        int count[26] = {0};
        
        for(int i=0;i<s1.length();i++){
            int ind = s1[i]-'a';
            count[ind]++;
        }
        
        int i=0;
        int window = s1.length();
        int count2[26] = {0};
        
        while(i<window && i<s2.length()){
            int ind = s2[i]-'a';
            count2[ind]++;
            i++;
        }
        
        if(check(count,count2)){
            return 1;
        }
        while(i<s2.length()){
            char newch = s2[i];
            int ind = newch - 'a';
            count2[ind]++;
            
            char oldch = s2[i-window];
            ind = oldch-'a';
            count2[ind]--;
            
            i++;
            if(check(count,count2)){
            return 1;
        }
            
        }
        
        return 0;
    }
};