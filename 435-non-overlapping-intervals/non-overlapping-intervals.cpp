struct meeting{
    int start;
    int end;
    int pos;
};


class Solution {
public:
    bool static comparator (vector<int> t1, vector<int> t2){
        return t1[1]<t2[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        sort(intervals.begin(),intervals.end(),comparator);
        int count = 1;
        int times = intervals[0][1];
        for(int i=1;i<n;i++){
            if(intervals[i][0]>=times){
                count++;
                times = intervals[i][1];
            }
        }
        return n-count;
    }
};