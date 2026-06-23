class Solution {
public:
    int solve(int i , int j , string &s1 , string &s2,int n, int m,vector<vector<int>> &dp){
        if(i==n) return m-j;
        if(j==m) return n-i;

        if(dp[i][j] != -1) return dp[i][j];

        if(s1[i] == s2[j]){
            return dp[i][j] = solve(i+1,j+1,s1,s2,n,m,dp);
        }

        int replace = solve(i+1,j+1,s1,s2,n,m,dp) + 1;
        int d = solve(i+1,j,s1,s2,n,m,dp)+1;
        int insert = solve(i,j+1,s1,s2,n,m,dp)+1;

        return dp[i][j] = min({replace, d, insert});
    }
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>> dp(n,vector<int>(m,-1));
        return solve(0,0,word1,word2,n,m,dp);
    }
};