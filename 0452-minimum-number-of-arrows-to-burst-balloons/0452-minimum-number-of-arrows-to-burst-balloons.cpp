class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        int n = points.size();
        int i =0;
        if(n==0) return 0;
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
    return a[0] < b[0];
});
        int start;
        int end;
        int cnt  = 0;


        while(i<n){
            start = points[i][0];
            end = points[i][1];
            i++;
            while(i<n && points[i][0] <= end){
                end = min(end , points[i][1]);
                i++;
            }

            cnt++;
        }
        return cnt;
    }
};