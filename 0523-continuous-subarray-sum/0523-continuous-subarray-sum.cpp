class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        unordered_set<int> st;

        int prev=0;
        int curr =0;
        for(int i =0;i<nums.size();i++){
            curr = (curr + nums[i]) %k;

            if(st.count(curr)) return true;

            st.insert(prev);
            prev = curr;
        }

        return false;
    }
};