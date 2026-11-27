class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
          int n = items.size();
        int min_price = INT_MAX;
        
        // dp[b] = max items obtained by buying at most 1 copy of distinct items with cost b
        vector<int> dp(budget + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            int factor_i = items[i][0];
            int price_i = items[i][1];
            min_price = min(min_price, price_i);
            
            // Count total items gained on the first purchase of item i (1 self + free copies)
            int gain = 0;
            for (int j = 0; j < n; ++j) {
                if (items[j][0] % factor_i == 0) {
                    gain++;
                }
            }
            
            // 0/1 Knapsack transition (iterate backwards to use each item type at most once)
            for (int b = budget; b >= price_i; --b) {
                dp[b] = max(dp[b], dp[b - price_i] + gain);
            }
        }
        
        // Spend any leftover budget on the cheapest available item
        int max_items = 0;
        for (int b = 0; b <= budget; ++b) {
            int extra_copies = (budget - b) / min_price;
            max_items = max(max_items, dp[b] + extra_copies);
        }
        
        return max_items;
    }
};