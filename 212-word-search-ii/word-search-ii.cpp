struct TrieNode{
    TrieNode* child[26] = {nullptr};
    string word = "";
};

class Solution {
public:
    void insert(TrieNode* root,string& w){
        TrieNode* curr = root;
        for(char c:w){
            int i=c-'a';
            if(!curr->child[i]) curr->child[i] = new TrieNode();
            curr = curr->child[i];
        }
        curr->word = w;
    }
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        TrieNode* root = new TrieNode();
        for(string& w:words) insert(root,w);
        vector<string> ans;
        for(int r=0;r<board.size();r++){
            for(int c=0;c<board[0].size();c++){
                dfs(board,r,c,root,ans);
            }
        }
        return ans;
    }
    void dfs(vector<vector<char>>& board,int r,int c,TrieNode* node,vector<string>& ans){
        char ch = board[r][c];
        if(ch=='#' || !node->child[ch-'a']) return;
        node = node->child[ch-'a'];
        if(node->word != ""){
            ans.push_back(node->word);
            node->word = "";
        }
        board[r][c] = '#';
        if(r>0) dfs(board,r-1,c,node,ans);
        if(r<board.size()-1) dfs(board,r+1,c,node,ans);
        if(c>0) dfs(board,r,c-1,node,ans);
        if(c<board[0].size()-1) dfs(board,r,c+1,node,ans);
        board[r][c] = ch;
        return;
    }
};