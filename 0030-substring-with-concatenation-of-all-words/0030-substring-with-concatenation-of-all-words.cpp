class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int totalLength = 0;
        unordered_map<string, int> freq;
        int wordLength = words[0].length();

        for (auto& word : words) {
            totalLength += word.length();
            freq[word]++;
        }

        vector<int> ans;

        for (int offset = 0; offset < wordLength; offset++) {
            int left = offset;
            int right = offset + totalLength - 1;

            if (right >= s.size())
                break;

            unordered_map<string, int> swh;

            // Build the initial window
            for (int i = left; i <= right; i += wordLength) {
                string word = s.substr(i, wordLength);
                swh[word]++;
            }

            while (right < s.size()) {

                if (swh == freq)
                    ans.push_back(left);

                // No new word can enter the window
                if (right + wordLength >= s.size())
                    break;

                string leftWord = s.substr(left, wordLength);
                string rightWord = s.substr(right + 1, wordLength);

                // Remove word leaving the window
                swh[leftWord]--;

                if (swh[leftWord] == 0)
                    swh.erase(leftWord);

                // Add word entering the window
                swh[rightWord]++;

                left += wordLength;
                right += wordLength;
            }
        }

        return ans;
    }
};