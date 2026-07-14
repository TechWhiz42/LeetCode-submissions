class Solution {
public:
    static const int MOD = 1e9 + 7;

    int n;
    vector<int> nums;

    int memo[201][201][201];
    bool vis[201][201][201];

    int solve(int idx, int g1, int g2) {

        if (idx == n)
            return (g1 == g2 && g1 != 0);

        if (vis[idx][g1][g2])
            return memo[idx][g1][g2];

        vis[idx][g1][g2] = true;

        long long ans = 0;

        ans += solve(idx + 1, g1, g2);

        int ng1 = (g1 == 0) ? nums[idx] : gcd(g1, nums[idx]);
        ans += solve(idx + 1, ng1, g2);

        int ng2 = (g2 == 0) ? nums[idx] : gcd(g2, nums[idx]);
        ans += solve(idx + 1, g1, ng2);

        return memo[idx][g1][g2] = ans % MOD;
    }

    int subsequencePairCount(vector<int>& arr) {
        nums = arr;
        n = nums.size();

        memset(vis, 0, sizeof(vis));

        return solve(0, 0, 0);
    }
};
