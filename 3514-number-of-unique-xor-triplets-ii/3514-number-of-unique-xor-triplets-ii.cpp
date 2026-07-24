class Solution {
public:
    void fwht(vector<long long>& a, bool inverse) {
        int n = a.size();

        for (int len = 1; len < n; len <<= 1) {
            for (int i = 0; i < n; i += (len << 1)) {
                for (int j = 0; j < len; j++) {
                    long long x = a[i + j];
                    long long y = a[i + j + len];

                    a[i + j] = x + y;
                    a[i + j + len] = x - y;
                }
            }
        }

        if (inverse) {
            for (auto &x : a)
                x /= n;
        }
    }

    int uniqueXorTriplets(vector<int>& nums) {
        const int MAXX = 2048;

        vector<long long> f(MAXX, 0);

        for (int x : nums)
            f[x] = 1;       

        fwht(f, false);

        for (auto &x : f)
            x = x * x * x;

        fwht(f, true);

        int ans = 0;
        for (long long x : f)
            if (x != 0)
                ans++;

        return ans;
    }
};