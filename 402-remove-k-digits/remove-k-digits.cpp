class Solution {
public:
    string removeKdigits(string num, int k) {
        stack<char> st;

        for (char c : num) {
            while (!st.empty() && k > 0 && st.top() > c) {
                st.pop();
                k--;
            }
            st.push(c);
        }

        while (k > 0) {
            st.pop();
            k--;
        }

        string res;
        while (!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());

        // Remove leading zeros
        int start = 0;
        while (start < res.size() && res[start] == '0') {
            start++;
        }
        res = res.substr(start);

        return res.empty() ? "0" : res;
    }
};
