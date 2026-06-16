class Solution {
public:
    int divide(int dividend, int divisor) {
        if(divisor == 0) return 0;
        if(dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        long long dvd = llabs((long long) dividend);
        long long dvs = llabs((long long) divisor);

        long long quotient = 0;

        for(int i = 31; i >=0; i--){
            if((dvs<<i) <= dvd){
                dvd -= (dvs << i);
                quotient += (1LL << i);
            }
        }
        if((dividend < 0)^(divisor <0))
            quotient = -quotient;

        return (int)quotient;
    }
};
