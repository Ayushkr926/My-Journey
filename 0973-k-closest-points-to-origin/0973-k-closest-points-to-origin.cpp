class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double,int> , vector<pair<double,int>>,greater<pair<double,int>>> mini;
        int n = points.size();
        for(int i = 0;i<n;i++){
            int x = points[i][0];
            int y = points[i][1];

            double d = pow((x-0),2) + pow((y-0),2);
            double mi = sqrt(d);
            cout<<mi<<endl;
            mini.push({mi,i});
        }

        vector<vector<int>> ans;
        while(k--){
            ans.push_back(points[mini.top().second]);
            mini.pop();
        }

        return ans;
    }
};