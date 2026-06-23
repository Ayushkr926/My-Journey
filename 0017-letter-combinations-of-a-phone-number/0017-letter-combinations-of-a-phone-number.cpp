class Solution {
public:

    void solve(int i ,string digit, unordered_map<char,string> &freq,vector<string> &ans,string out){
        if(i== digit.size()){
            ans.push_back(out);
        }

        string curr = freq[digit[i]];
        int n = curr.size();

        for(int j = 0;j<n;j++){
            solve(i+1,digit,freq,ans,out + curr[j]);
            // out.pop_back();
        }
    }



    vector<string> letterCombinations(string digits) {
        if(digits.size()==0) return {};
        unordered_map<char, string> freq = {
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}
        };
        vector<string> ans;
        string out="";
        solve(0,digits,freq,ans,out);
        return ans;
    }
};