class Solution {
public:
    int minOperations(string s1, string s2) {
        int n = s1.size();

        if(n == 1) {
            if(s1[0] == s2[0]) return 0;
            if(s1[0] == '0' && s2[0] == '1') return 1;
            return -1;
        }

        int dist[4][4] = {
            {0,1,1,2},
            {2,0,3,1},
            {2,3,0,1},
            {1,2,2,0}
        };

        int dp[2] = {INT_MAX, INT_MAX};

        dp[s1[0] - '0'] = 0;

        for(int i = 0; i < n - 1; i++) {
            int dp2[2] = {INT_MAX, INT_MAX};

            int d = s1[i + 1] - '0';
            int target1 = s2[i] - '0';

            for(int j = 0; j < 2; j++) {
                if(dp[j] == INT_MAX) continue;

                int a = (j << 1) | d;

                for(int k = 0; k < 2; k++) {
                    int b = (target1 << 1) | k;
                    dp2[k] = min(dp2[k], dp[j] + dist[a][b]);
                }
            }

            dp[0] = dp2[0];
            dp[1] = dp2[1];
        }

        int last = s2[n - 1] - '0';
        int ans;

        if(last == 0)
            ans = dp[0];
        else
            ans = min(dp[1], dp[0] + 1);

        return (ans == INT_MAX) ? -1 : ans;
    }
};
