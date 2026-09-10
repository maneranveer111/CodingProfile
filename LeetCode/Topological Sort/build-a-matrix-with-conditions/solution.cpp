class Solution {
public:
    vector<int> vis;
    bool hasCycle = false;

    void helper(int node, vector<vector<int>>& adj, stack<int>& st) {
        vis[node] = 1;
        for (auto nei : adj[node]) {
            if (vis[nei] == 1) {
                hasCycle = true;
                return;
            }
            if (vis[nei] == 0)
                helper(nei, adj, st);
        }
        vis[node] = 2; 
        st.push(node);
    }

    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>> rowAdj(k + 1);
        vector<vector<int>> colAdj(k + 1);
        vector<vector<int>> ans(k, vector<int>(k, 0));

        for (auto& edg : rowConditions)
            rowAdj[edg[0]].push_back(edg[1]);

        for (auto& edg : colConditions)
            colAdj[edg[0]].push_back(edg[1]);

        stack<int> st;
        vis.assign(k + 1, 0);
        hasCycle = false;

        for (int i = 1; i <= k && !hasCycle; i++)
            if (vis[i] == 0)
                helper(i, rowAdj, st);

        if (hasCycle)
            return {};

        vector<int> row;
        while (!st.empty()) {
            row.push_back(st.top());
            st.pop();
        }

        if ((int)row.size() != k)
            return {};

        st = stack<int>();
        vis.assign(k + 1, 0);
        hasCycle = false;

        for (int i = 1; i <= k && !hasCycle; i++)
            if (vis[i] == 0)
                helper(i, colAdj, st);

        if (hasCycle)
            return {};

        vector<int> col;
        while (!st.empty()) {
            col.push_back(st.top());
            st.pop();
        }

        if ((int)col.size() != k)
            return {};

        vector<int> rowPos(k + 1), colPos(k + 1);
        for (int i = 0; i < k; i++) rowPos[row[i]] = i;
        for (int j = 0; j < k; j++) colPos[col[j]] = j;

        for (int val = 1; val <= k; val++)
            ans[rowPos[val]][colPos[val]] = val;

        return ans;
    }
};