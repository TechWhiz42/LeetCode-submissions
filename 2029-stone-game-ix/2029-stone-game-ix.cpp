class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int cnt[3] = {};

        for (int x : stones)
            ++cnt[x % 3];

        int zero = cnt[0];
        int one = cnt[1];
        int two = cnt[2];

        if (one == 0 && two == 0)
            return false;

        if (one == 0 || two == 0)
            return (one + two > 2 && zero % 2);

        return zero % 2 ? abs(one - two) > 2 : true;
    }
};