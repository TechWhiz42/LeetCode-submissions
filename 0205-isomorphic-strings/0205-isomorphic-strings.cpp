class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size())
            return false;

        unordered_map<char, char> mp;
        unordered_map<char, char> rev;

        for (int i = 0; i < s.size(); i++) {
            char a = s[i];
            char b = t[i];

            if (mp.count(a) && mp[a] != b)
                return false;

            if (rev.count(b) && rev[b] != a)
                return false;

            mp[a] = b;
            rev[b] = a;
        }

        return true;
    }
};