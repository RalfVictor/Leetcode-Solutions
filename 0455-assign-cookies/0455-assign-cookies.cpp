class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        cout<<s.size()<<" "<<g.size()<<endl;
        int i=0;
        int j=0;
        int count=0; 
        while(i<g.size() && j<s.size()){
            cout<<s[j]<<" "<<g[i]<<endl;
            if(s[j]>=g[i]){
                count++;
                i++;
                j++;
            }
            else{
                j++;
            }
        }
        return count;
    }
};