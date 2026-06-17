class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.size();

        vector<long long> len(n);
        long long curr = 0;

        for (int i = 0; i < n; i++) {
            char ch = s[i];

            if (isalpha(ch))
                curr++;

            else if (ch == '*') {
                if (curr > 0)
                    curr--;
            }

            else if (ch == '#')
                curr *= 2;

            else if (ch == '%')
                ;

            len[i] = curr;
        }

        if (k >= curr)
            return '.';

        for (int i = n - 1; i >= 0; i--) {
            char ch = s[i];
            long long before = (i == 0 ? 0 : len[i - 1]);

            if (isalpha(ch)) {
                if (k == before)
                    return ch;
            }
            else if (ch == '#') {
                long long half = before;

                if (k >= half)
                    k -= half;
            }
            else if (ch == '%') {
                k = before - 1 - k;
            }
        }

        return '.';
    }
};
