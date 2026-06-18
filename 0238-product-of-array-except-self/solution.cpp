class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> result(n,1);

        int lproduct = 1;

        for(int i = 0; i<n;i++){
            result[i] = lproduct;
            lproduct *= nums[i];
        }

        int rproduct = 1;
        for(int i = n-1; i>=0; i--){
            result[i] *= rproduct;
            rproduct *= nums[i];
        }
        return result;
    }
};
