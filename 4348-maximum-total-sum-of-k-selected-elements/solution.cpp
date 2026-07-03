class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(), nums.end(), greater<int>());
        
        long long ans = 0;

        for(int i = 0; i<k;i++)
            ans += nums[i];

        int cnt = min(k, max(0, mul-1));

        for(int i = 0; i<cnt; i ++){
            ans += 1LL*nums[i] * (mul -1-i);
        }
        return ans;
    }
};
