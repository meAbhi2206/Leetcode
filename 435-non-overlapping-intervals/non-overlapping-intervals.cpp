class Solution {
public:
 static bool cmp(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
         int n=intervals.size();
         if(n==0) return 0;
        sort(intervals.begin(), intervals.end(),cmp);
        int cnt=0;
        int end=intervals[0][1];
        for(int i=1;i<n;i++){
            //current interval is overlapping
            if(intervals[i][0]<end){
                cnt++;
            }
            //if current interval does not overlap 
            //update end with curr interval end
            else{
                end=intervals[i][1];
            }
        }
        return cnt;
    }
};