class Solution {
public:
    static constexpr int MOD = 1e9 + 7;

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1)
            return m;

        vector<long long> up(m, 0), down(m, 0);

        for (int i = 0; i < m; i++) {
            up[i] = i;            
            down[i] = m - 1 - i;   
        }

        vector<long long> newUp(m, 0);
        vector<long long> newDown(m, 0);

        for (int len = 3; len <= n; len++) {

            long long cur = 0;

            for (int y = 0; y < m; y++) {
                newUp[y] = cur;
                cur = (cur + down[y]) % MOD;
            }

            cur = 0;

            for (int y = m - 1; y >= 0; y--) {
                newDown[y] = cur;
                cur = (cur + up[y]) % MOD;
            }

            swap(up, newUp);
            swap(down, newDown);
        }

        long long ans = 0;

        for (int i = 0; i < m; i++) {
            ans = (ans + up[i] + down[i]) % MOD;
        }

        return (int)ans;
    }
};
