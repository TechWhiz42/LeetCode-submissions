class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> ans(n + 3, 0);

        for (int i = n - 1; i >= 0; i--) {
            int take = 0;
            ans[i] = INT_MIN;

            for (int k = 0; k < 3 && i + k < n; k++) {
                take += stoneValue[i + k];
                ans[i] = max(ans[i], take - ans[i + k + 1]);
            }
        }
        if (ans[0] > 0)
            return "Alice";
        if (ans[0] < 0)
            return "Bob";
        return "Tie";
    }
};