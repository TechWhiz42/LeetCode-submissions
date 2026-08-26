class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int left = 0;
        int count = 0;

        int bestLeft = 0;
        int bestLength = INT_MAX;

        for (int right = 0; right < s.size(); right++) {
            if (s[right] == '1')
                count++;

            while (count == k) {
                int length = right - left + 1;

                if (length < bestLength || (length == bestLength && 
                    s.substr(left, length) < s.substr(bestLeft, bestLength))) {
                    bestLength = length;
                    bestLeft = left;
                }

                if (s[left] == '1')
                    count--;

                left++;
            }
        }

        if (bestLength == INT_MAX)
            return "";

        return s.substr(bestLeft, bestLength);
    }
};