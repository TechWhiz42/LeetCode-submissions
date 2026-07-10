class Solution {
public:
    vector<int> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<pair<int, int>> arr;
        for (int i = 0; i < n; i++)
            arr.push_back({nums[i], i});

        sort(arr.begin(), arr.end());

        vector<int> vals(n), pos(n);
        for (int i = 0; i < n; i++) {
            vals[i] = arr[i].first;
            pos[arr[i].second] = i;
        }

        const int LOG = 18;
        vector<vector<int>> up(LOG, vector<int>(n));

        for (int i = 0; i < n; i++) {
            up[0][i] = upper_bound(vals.begin(), vals.end(), vals[i] + maxDiff) - vals.begin() - 1;
        }

        for (int k = 1; k < LOG; k++) {
            for (int i = 0; i < n; i++) {
                up[k][i] = up[k - 1][up[k - 1][i]];
            }
        }

        vector<int> ans;

        for (auto &q : queries) {
            int l = pos[q[0]];
            int r = pos[q[1]];

            if (l > r)
                swap(l, r);

            if (l == r) {
                ans.push_back(0);
                continue;
            }

            if (up[LOG - 1][l] < r) {
                ans.push_back(-1);
                continue;
            }

            int steps = 0;
            int cur = l;

            for (int k = LOG - 1; k >= 0; k--) {
                if (up[k][cur] < r) {
                    cur = up[k][cur];
                    steps += (1 << k);
                }
            }

            ans.push_back(steps + 1);
        }

        return ans;
    }
};
