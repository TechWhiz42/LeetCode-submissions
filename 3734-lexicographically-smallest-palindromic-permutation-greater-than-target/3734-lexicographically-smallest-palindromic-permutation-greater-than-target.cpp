class Solution {
public:
    bool palindrome(string& s) {
        int left = 0;
        int right = s.size() - 1;

        while (left < right) {
            if (s[left] != s[right])
                return false;

            left++;
            right--;
        }

        return true;
    }

    string palindrome(string targetHalf, char middle) {
        string revTargetHalf = targetHalf;
        reverse(revTargetHalf.begin(), revTargetHalf.end());

        string palString;

        if (middle != '\0')
            palString = targetHalf + middle + revTargetHalf;
        else
            palString = targetHalf + revTargetHalf;

        return palString;
    }

    string lexPalindromicPermutation(string s, string target) {
        int n = s.length();

        vector<int> freq(26, 0);
        vector<int> halfFreq(26, 0);

        int cntOdd = 0;

        for (auto& ch : s)
            freq[ch - 'a']++;

        for (int i = 0; i < 26; i++) {
            if (freq[i] % 2 == 1)
                cntOdd++;

            halfFreq[i] = freq[i] / 2;
        }

        if (cntOdd > 1)
            return "";

        char middle = '\0';

        if (cntOdd == 1) {
            for (int i = 0; i < 26; i++) {
                if (freq[i] % 2 == 1)
                    middle = 'a' + i;
            }
        }

        int halfLen = n / 2;
        string targetHalf = target.substr(0, halfLen);

        vector<int> targetH = halfFreq;

        bool possible = true;

        for (auto& ch : targetHalf) {
            if (targetH[ch - 'a'] == 0) {
                possible = false;
                break;
            }

            targetH[ch - 'a']--;
        }

        string candidate = "";

        if (possible) {
            candidate = palindrome(targetHalf, middle);

            if (candidate > target)
                return candidate;
        }

        if (!possible || candidate <= target) {

            for (int i = halfLen - 1; i >= 0; i--) {

                vector<int> remaining = halfFreq;

                bool validPrefix = true;

                for (int j = 0; j < i; j++) {
                    int idx = targetHalf[j] - 'a';

                    if (remaining[idx] == 0) {
                        validPrefix = false;
                        break;
                    }

                    remaining[idx]--;
                }

                if (!validPrefix)
                    continue;

                int current = targetHalf[i] - 'a';

                for (int c = current + 1; c < 26; c++) {

                    if (remaining[c] > 0) {

                        targetHalf[i] = char('a' + c);
                        remaining[c]--;

                        for (int j = i + 1; j < halfLen; j++) {
                            for (int x = 0; x < 26; x++) {
                                if (remaining[x] > 0) {
                                    targetHalf[j] = char('a' + x);
                                    remaining[x]--;
                                    break;
                                }
                            }
                        }

                        candidate = palindrome(targetHalf, middle);

                        if (candidate > target)
                            return candidate;

                        break;
                    }
                }
            }
        }

        return "";
    }
};