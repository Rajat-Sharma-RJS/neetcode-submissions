class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n <= 1) return 0;

        int maxp = 0, buy = n-2, sell = n-1, minp = n-1;
        while(buy>=0) {
            if(prices[buy] >= prices[sell]) {
                maxp = max(maxp, prices[sell]-prices[minp]);
                sell = buy;
                minp = buy;
            } else {
                if(prices[minp] > prices[buy]) minp = buy;
            }
            buy--;
        }
        maxp = max(maxp, prices[sell]-prices[minp]);
        return maxp;
    }
};
