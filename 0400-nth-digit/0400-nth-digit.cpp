class Solution {
public:
    int findNthDigit(int n) {
        long long digit = 1;
        long long count = 9;
        long long start = 1;

        while(n > count * digit){
            n -= count*digit;
            digit++;
            count *= 10;
            start *= 10;
        }

        long long num = start + (n-1) / digit;
        int index = (n-1)%digit;
        string s = to_string(num);

        return s[index] -'0';
    }
};