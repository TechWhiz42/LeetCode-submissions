class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());

        int icecreams = 0;

        for(int cost : costs) {
            if(cost > coins)
                break;

            coins -= cost;
            icecreams++;
        }

        return icecreams;
    }
};
