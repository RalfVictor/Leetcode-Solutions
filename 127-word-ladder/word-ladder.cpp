class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string,int>> q;
        unordered_set <string> st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);
        int n = beginWord.length();
        while(!q.empty()){
            string w = q.front().first;
            int l = q.front().second;
            q.pop();
            if(w==endWord) return l;
            for(int i=0;i<n;i++){
                char og = w[i];
                for(char j='a';j<='z';j++){
                    w[i] = j;
                    if(st.find(w)!=st.end()){
                        st.erase(w);
                        q.push({w,l+1});
                    }
                }
                w[i] = og;
            }
        }
        return 0;
    }
};