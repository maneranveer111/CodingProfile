class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int p : prices){
            if(p < minPrice)minPrice = p;
            else maxProfit = max(maxProfit, p - minPrice);
        }

        return maxProfit;
    }
};