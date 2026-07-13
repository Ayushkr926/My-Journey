class Solution {
public:
    vector<int> getConcatenation(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        int j = n;
        vector<int> ans(n*2);
        while(i<n){
            ans[i] = nums[i];
            ans[j] = nums[i];
            i++;
            j++;
        }

        return ans;
    }
};