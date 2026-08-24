class Solution {
public:
    bool sumGame(string num) {
        int mid = num.size() / 2;
        int left = 0, right = 0;
        int leftSum = 0, rightSum = 0;

        for (int i = 0; i < num.size(); i++) {
            if (num[i] == '?') {
                if (i < mid)
                    left++;
                else
                    right++;
            } else {
                if (i < mid)
                    leftSum += num[i] - '0';
                else
                    rightSum += num[i] - '0';
            }
        }
        int diff = leftSum - rightSum;
        int queDiff = left - right;

        if (queDiff == 0)
            return diff != 0;

        return 2* diff +9*queDiff != 0;
    }
};