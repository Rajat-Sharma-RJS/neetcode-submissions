class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int sum = 0, i = 1, currp = 0;

        while(i<n) {
            if(prices[i-1] > prices[i]) {
                sum += prices[i-1] - prices[currp];
                currp = i;
            }
            i++;
        }
        sum += prices[i-1] - prices[currp];
        return sum;
    }
};