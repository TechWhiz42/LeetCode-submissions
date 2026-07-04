class Solution {
public:
    using ull = unsigned long long;
    const ull BASE = 131;

    int check(string& s, int len){
        if(len == 0)
            return 0;

        int n = s.size();
        ull hash = 0;
        ull power = 1;

        for(int i = 0; i <len; i++){
            hash = hash*BASE + (s[i]-'a'+1);
            if(i<len - 1)
                power *= BASE;
        }
        unordered_map<ull, vector<int>> mp;
        mp[hash].push_back(0);

        for(int i = len; i< n ;i++){
            hash -= (ull)(s[i-len]-'a'+1)*power;
            hash = hash*BASE + (s[i]-'a'+1);

            int start = i-len+1;

            if(mp.count(hash)){
                for(int prev : mp[hash]){
                    if(s.compare(prev, len,s, start, len) == 0)
                        return start;
                }
            }
            mp[hash].push_back(start);
        }
        return -1;
    }

    string longestDupSubstring(string s) {
        int n = s.size();
        int left = 1, right = n - 1;

        int start = -1;
        int bestLen = 0;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            int idx = check(s, mid);

            if (idx != -1) {
                start = idx;
                bestLen = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return start == -1 ? "" : s.substr(start, bestLen);
    }
};
