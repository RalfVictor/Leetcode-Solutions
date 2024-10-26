class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        string c;
        for(char ch:s){
            if(st.empty()){
                st.push(ch);
            }
            else if(st.top()==ch){
                st.pop();
            }
        else{
            st.push(ch);
        }
        }
        while(!st.empty()){
            c.push_back(st.top());
            st.pop();
        }
        reverse(c.begin(),c.end());
        cout<<c;
        return c;
    }
};