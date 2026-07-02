class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,int> mapping;

        for(int i = 0;i<nums.size();i++){
            int need = target - nums[i];
            if(mapping.find(need) != mapping.end()){
                return {mapping[need] , i};
            }

            mapping[nums[i]] = i;
        }

        return {-1,-1};
    }
};















