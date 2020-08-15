int cmp(vector<int>a,vector<int>b){
    return a[1]<b[1];
}
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end(),cmp);
        int c=0;
        if(intervals.size()==0){
            return 0;
        }
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i+1][0]<intervals[i][1]){
                intervals[i+1][0]=intervals[i][0];
                intervals[i+1][1]=intervals[i][1];
                c++;
            }
        }
        return c;
    }
};
