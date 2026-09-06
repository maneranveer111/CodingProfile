class Solution {
public:
    int m, n, k;
    vector<vector<int>> grid;
    vector<vector<vector<vector<int>>>> dp;
    vector<vector<vector<vector<bool>>>> vis;

    int dr[4] = {-1, 1, 0, 0};
    int dc[4] = {0, 0, -1, 1};

    int helper(int i, int j, int dir, int currK) {
        if(currK > k)
            return 1e9;
        
        if(i == m - 1 && j == n - 1)
            return grid[i][j];

        if(vis[i][j][dir][currK])
            return dp[i][j][dir][currK];
        
        vis[i][j][dir][currK] = true;
        int ans = 1e9;

        for(int d = 0; d < 4; d++) {
            int ni = dr[d] + i;
            int nj = dc[d] + j;

            if(ni >= m || nj >= n || ni < 0 || nj < 0)
                continue;

            int newK = currK + ((dir != d) ? 1 : 0);

            ans = min(ans, grid[i][j] + helper(ni, nj, d, newK));
        }

        return dp[i][j][dir][currK] = ans;      
    }
    
    int minCost(vector<vector<int>>& g, int l) {
        grid = g;
        k = l;
        m = g.size();
        n = g[0].size();

        dp = vector<vector<vector<vector<int>>>>
            (m, vector<vector<vector<int>>>
                 (n, vector<vector<int>>
                      (4, vector<int>(k + 1, 0))));
        
        vis = vector<vector<vector<vector<bool>>>>
                (m, vector<vector<vector<bool>>>
                     (n, vector<vector<bool>>
                          (4, vector<bool>(k + 1, false))));

        int ans = 1e9;
        for(int d = 0; d < 4; d++) {
            ans = min(ans, helper(0, 0, d, 0));
        }

        return ans >= 1e9 ? -1 : ans;
    }
};