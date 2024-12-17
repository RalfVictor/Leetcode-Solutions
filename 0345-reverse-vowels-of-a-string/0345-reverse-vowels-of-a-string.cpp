class Solution {
public:
    string reverseVowels(string s) {
        int i=0;
        int j=s.length()-1;
        vector<char> vowel = {'a','e','i','o','u'};
        while(i<j){
            char x = tolower(s[i]);
            char y = tolower(s[j]);
            if(find(vowel.begin(),vowel.end(),y)!=vowel.end() && find(vowel.begin(),vowel.end(),x)!=vowel.end()){
                swap(s[i],s[j]);
                i++;
                j--;
            }
            else if(find(vowel.begin(),vowel.end(),y)!=vowel.end() && find(vowel.begin(),vowel.end(),x)==vowel.end()){
                i++;
            }
            else if(find(vowel.begin(),vowel.end(),y)==vowel.end()){
                j--;
            }
            else{
                i++;
                j--;
            }
        }
        return s;
    }
};