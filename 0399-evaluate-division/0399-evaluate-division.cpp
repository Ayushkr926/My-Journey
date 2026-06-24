class Solution {
public:
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) { 
        unordered_map<string, unordered_map<string, double>> adj ; 
        for(int i = 0 ; i < equations.size() ; i++)
        {
            adj[equations[i][0]].insert({equations[i][1], values[i]}) ; 
            adj[equations[i][1]].insert({equations[i][0], 1.0/values[i]}) ; 
        }
        for(const auto& [n1, n2] : adj)
        {
            string k = n1 ;
            for(const auto& [n2, v] : adj[k])
            {
                string i = n2 ; 
                for( const auto& [n2, v]: adj[k])
                {
                    string j = n2 ; 
                    if(!adj[i][j]) 
                    adj[i][j] = adj[i][k] * adj[k][j] ; 
                }
            }
        }
        vector<double> ans;
        for(const auto& q : queries)
        {
            const string& a = q[0];
            const string& b = q[1];
            if(!adj.count(a) || !adj[a].count(b)) 
                ans.push_back(-1.0);
            else
                ans.push_back(adj[a][b]) ;
        }
        return ans ; 

    }
};