class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> curr;

        auto dfs = [&](auto& dfs, int start) -> void {
            if (curr.size() == k) {
                ans.push_back(curr);
                return;
            }

            int need = k - curr.size();

            for (int i = start; i <= n - need + 1; i++) {
                curr.push_back(i);
                dfs(dfs, i + 1);
                curr.pop_back();
            }
        };

        dfs(dfs, 1);
        return ans;
    }
};