class Solution {
public:
    long long sumAndMultiply(int n) {
        string str = to_string(n);

        str.erase(remove(str.begin(), str.end(), '0'), str.end());

        string result = "";
        unordered_set<char> seen;

        for (char ch : str) { 
                seen.insert(ch);
                result += ch;
            
        }

        if (result.empty())
            return 0;

        long long sum = 0;
        for (char ch : result) {
            sum += ch - '0';
        }

        long long x = stoll(result);

        return x * sum;
    }
};
