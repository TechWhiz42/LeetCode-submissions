class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {
        vector<int> prefix(n,0);

        for(int i = 0; i<n-1;i++){
            prefix[i+1] = prefix[i] + ((nums[i+1] - nums[i] > maxDiff));
        }
        vector<bool> ans;
        for(auto it : queries){
            int l = it[0];
            int r = it[1];
            int sum = prefix[r] - prefix[l];
            if(sum == 0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};
