class Solution {
public:
    void solve(int ind, vector<int>& nums, vector<int>& curr,
               vector<vector<int>>& ans) {

        if (ind == nums.size()) {
            ans.push_back(curr);
            return;
        }

        // Take
        curr.push_back(nums[ind]);
        solve(ind + 1, nums, curr, ans);

        // Return
        curr.pop_back();

        // Don't take
        solve(ind + 1, nums, curr, ans);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> curr;

        solve(0, nums, curr, ans);

        return ans;
    }
};