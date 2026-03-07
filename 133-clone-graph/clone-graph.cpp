/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node,unordered_map<Node*,Node*>& mp){
        vector<Node*> temp;
        Node* clone = new Node(node->val);
        mp[node] = clone;
        for(auto no:node->neighbors){
            if(mp.find(no)!=mp.end()){
                temp.push_back(mp[no]);
            }
            else{
                temp.push_back(dfs(no,mp));
            }
        }
        clone->neighbors = temp;
        return clone;
    }

    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> mp;
        if(!node){
            return NULL;
        }
        if(node->neighbors.size()==0){
            Node* newi = new Node(node->val);
            return newi;
        }
        return dfs(node,mp);
    }
};