class Fenwick{
public:
    vector<long long> bit;
    int n;

    Fenwick(int n ) : n(n), bit(n+1, 0){}

    void add(int idx, long long val){
        for(; idx <=n; idx += idx & -idx){
            bit[idx] += val;
        }
    }
    long long sum(int idx){
        long long res = 0;

        for(; idx > 0; idx -= idx & -idx)
            res += bit[idx];

        return res;
    }
};

class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<long long> pref(n+1, 0);

        for(int i = 0; i<n;i++){
            pref[i+1] = pref[i] + (nums[i] == target ? 1 : -1);
        }

        vector<long long> vals = pref;
        sort(vals.begin(), vals.end());
        vals.erase(unique(vals.begin(), vals.end()), vals.end());

        Fenwick fw(vals.size());

        long long ans = 0;

        for(long long p : pref){
            int pos = lower_bound(vals.begin(), vals.end(), p) - vals.begin() +1;

            ans += fw.sum(pos-1);

            fw.add(pos,1);
        }
        return ans;
    }
};
