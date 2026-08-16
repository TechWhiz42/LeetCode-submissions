class Solution {
public:
    bool stoneGameIX(vector<int>& stones) {
        int n = stones.size();
        if (n == 0)
            return false;
        int cnt = 0;
        int cnt1 = 0;
        int cnt2 = 0;
        for (auto& stone : stones) {
            if (stone % 3 == 0)
                cnt++;
            else if (stone % 3 == 1)
                cnt1++;

            else if (stone % 3 == 2)
                cnt2++;
        }
        if (cnt1 == 0 && cnt2 == 0) {
            return false;
        }

        if (cnt1 == 0) {
            if (cnt2 >2 && cnt % 2 == 1)
                return true;
            return false;
        }

        if (cnt2 == 0) {
            if (cnt1 >2 && cnt % 2 == 1)
                return true;
            return false;
        }

        if (cnt % 2 == 1){
            if(abs(cnt1-cnt2) > 2){
                return true;
            } else {
                return false;
            }
        } 
        return true;
        
    }
};