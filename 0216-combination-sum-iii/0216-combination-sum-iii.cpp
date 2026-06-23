class Solution {
public:
    void solve(int i, int k, int n,
               vector<vector<int>>& ans,
               vector<int>& out) {

        if (n == 0 && k == 0) {
            ans.push_back(out);
            return;
        }

        if (n < 0 || k < 0)
            return;

        for (int j = i; j <= 9; j++) {
            out.push_back(j);

            solve(j + 1, k - 1, n - j, ans, out);

            out.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> out;

        solve(1, k, n, ans, out);

        return ans;
    }
};