class Solution {
public:
    long long countAtMost(vector<int>& nums, int k){
        unordered_map<int, int> freq;
        int left = 0;
        long long count = 0;
        int distincts = 0;

        for(int right = 0; right < nums.size(); right++){
            if(++freq[nums[right]] == 1)
                distincts++;

            while(distincts > k){
                if(--freq[nums[left]] == 0)
                    distincts--;
                left++;
            }
            count += right-left+1;
        }
        return count;
    }

    int medianOfUniquenessArray(vector<int>& nums) {
        int n = nums.size();
        long long total = 1LL*n*(n+1)/2;
        long long target = (total+1)/2;

        int low = 1;
        int high = n;

        while(low < high){
            int mid = low + (high-low)/2;

            if (countAtMost(nums,mid) >= target)
                high = mid;
            else
                low = mid+1;
        }
        return low;
    }
};
