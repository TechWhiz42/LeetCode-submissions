class Solution {
public:
    int powMod(int x, int n, int M) {
        long long ans = 1;
        x %= M;

        while (n > 0) {
            if (n & 1)
                ans = (__int128)ans * x % M;

            x = (__int128)x * x % M;
            n >>= 1;
        }
        return ans;
    }

    vector<int> getGoodIndices(vector<vector<int>>& variables, int target) {
        vector<int> ans;
        for (int i = 0; i < (int)variables.size(); i++) {
            int a = variables[i][0];
            int b = variables[i][1];
            int c = variables[i][2];
            int m = variables[i][3];

            int inner = powMod(a, b, 10);
            int outer = powMod(inner, c, m);

            if (outer == target)
                ans.push_back(i);
        }
        return ans;
    }
};