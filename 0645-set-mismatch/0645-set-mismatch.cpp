class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        int dup = 0;
        int missing =0;
        unordered_map<int,int> freq;

        for(auto &i:nums){
            freq[i]++;
            if(freq[i] >1){
                dup = i;
            }
        }

        for(int i =1;i<=n;i++){
            if(freq.find(i) == freq.end()){
                missing = i;
            }
        }

        return {dup,missing};
    }
};