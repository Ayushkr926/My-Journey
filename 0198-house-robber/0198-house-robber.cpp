class Solution {
public:
    int solve(int i , int n , vector<int> & nums, vector<vector<int>> & dp,bool p){
        if(i>=n) return 0;
        if(dp[i][p] != -1) return dp[i][p];
        int pick = INT_MIN;
        int not_pick = INT_MIN;
        if(p){
            pick = nums[i] + solve(i+1,n,nums,dp,false);
        }

        not_pick = solve(i+1,n,nums,dp,true);

        return dp[i][p] =  max(pick,not_pick);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(2, -1));
        return solve(0,n,nums,dp,true);
    }
};